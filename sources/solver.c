/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrow <marrow@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 04:51:58 by marrow            #+#    #+#             */
/*   Updated: 2020/11/11 04:54:52 by marrow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int				best_way(int ants, t_path *path, t_path *start_path)
{
	int			best_length;

	best_length = 0;
	while (path != start_path)
	{
		if (start_path)
			best_length += path->length - start_path->next_path_in_room->length;
		start_path = start_path->next_path_in_room;
	}
	if (ants > best_length)
		return (TRUE);
	else
		return (FALSE);
}

void			move_for_start(t_lemin *le_min, t_path *path)
{
	int			curr_ant;
	char		*room_name;
	t_room		*curr_room;

	curr_ant = le_min->curr_ant;
	curr_room = path->path_next->belongs_to;
	room_name = curr_room->name;
	if (curr_room != le_min->end)
	{
		curr_room->ant = curr_ant;
		++le_min->ants_on_road;
	}
	++le_min->curr_ant;
	--le_min->ants;
	ft_printf("L%d-%s ", curr_ant, room_name);
}

void			move_ant_from_start(t_lemin *le_min, t_queue *free_rooms)
{
	t_path		*paths;

	paths = le_min->start->path->next_path_in_room;
	while (paths && le_min->ants)
	{
		if (best_way(le_min->ants, paths, le_min->start->path->\
		next_path_in_room) && !paths->edge->out->occupied)
		{
			queue_add_end(free_rooms, paths->edge->out);
			move_for_start(le_min, paths);
		}
		paths = paths->next_path_in_room;
	}
}

t_path			*move_ants_rec(t_path *curr, t_room *end, t_lemin *le_min)
{
	t_room	*room;

	if (curr->belongs_to->ant == 0)
		return (curr);
	else if (curr->belongs_to == end)
	{
		--le_min->ants_on_road;
		return (curr);
	}
	room = move_ants_rec(curr->path_next, end, le_min)->belongs_to;
	room->ant = curr->belongs_to->ant;
	ft_printf("L%d-%s ", room->ant, room->name);
	curr->belongs_to->ant = 0;
	return (curr);
}

void			move_ant_on_road(t_lemin *le_min)
{
	t_path *path;
	t_path *curr;

	path = le_min->start->path->next_path_in_room;
	while (path)
	{
		curr = path;
		while (curr->path_next->belongs_to != le_min->end && \
		curr->path_next->belongs_to->ant == 0)
			curr = curr->path_next;
		move_ants_rec(curr->path_next, le_min->end, le_min);
		path = path->next_path_in_room;
	}
}

void			solver(t_lemin *le_min)
{
	t_queue		*free_rooms;

	if (!(free_rooms = malloc_queue()))
		error();
	bhandari(le_min);
	while (le_min->ants > 0 || le_min->ants_on_road > 0)
	{
		if (le_min->ants_on_road)
			move_ant_on_road(le_min);
		move_ant_from_start(le_min, free_rooms);
		ft_printf("\n");
	}
	free_queue(&free_rooms);
}
