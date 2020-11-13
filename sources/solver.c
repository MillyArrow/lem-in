/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrow <marrow@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 04:51:58 by marrow            #+#    #+#             */
/*   Updated: 2020/11/12 09:59:07 by marrow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static	int		best_way(int ants, t_path *path, t_path *start_path)
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

static	void	move_for_start(t_lemin *le_min, t_path *path)
{
	int			curr_ant;
	char		*room_name;
	t_room		*curr_room;

	curr_ant = le_min->curr_ant;
	curr_room = path->path_next->belongs_to;
	room_name = curr_room->name;
	if (curr_room != le_min->end)
	{
		curr_room->occupied = TRUE;
		curr_room->ant = curr_ant;
		(le_min->ants_on_road)++;
	}
	(le_min->curr_ant)++;
	(le_min->ants)--;
	ft_printf("L%d-%s ", curr_ant, room_name);
}

static void		move_ant_from_start(t_lemin *le_min)
{
	t_path		*paths;
	int			ants;

	paths = le_min->start->path->next_path_in_room;
	while (paths && le_min->ants)
	{
		ants = le_min->ants;
		if (best_way(ants, paths, le_min->start->path->next_path_in_room) \
		&& !paths->edge->out->occupied)
			move_for_start(le_min, paths);
		paths = paths->next_path_in_room;
	}
}

void			solver(t_lemin *le_min)
{
	int			count;

	count = 0;
	bhandari(le_min);
	if (le_min->bonus_print_count_paths)
		ft_printf("{yellow}Count of paths: %d{eoc}\n", \
		count_paths(le_min->start->path));
	while (le_min->ants_on_road > 0 || le_min->ants > 0)
	{
		if (le_min->ants_on_road)
			move_ant_on_road(le_min);
		move_ant_from_start(le_min);
		ft_printf("\n");
		++count;
	}
	if (le_min->bonus_print_line_count)
		ft_printf("{black}LINE COUNT: %d{eoc} \n", count);
}
