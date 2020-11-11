/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlintill <rlintill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 04:51:58 by rlintill          #+#    #+#             */
/*   Updated: 2020/11/11 04:54:52 by rlintill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static t_path	*move_ants_rec(t_path *curr, t_room *end, t_lemin *le_min)
{
	t_room	*room;

	if (curr->belongs_to == end)
	{
		(le_min->ants_on_road)--;
		return (curr);
	}
	if (curr->belongs_to->ant == 0)
		return (curr);
	room = move_ants_rec(curr->path_next, end, le_min)->belongs_to;
	room->ant = curr->belongs_to->ant;
	room->occupied = TRUE;
	ft_printf("L%d-%s ", room->ant, room->name);
	curr->belongs_to->ant = 0;
	curr->belongs_to->occupied = FALSE;
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
		while (curr->path_next->belongs_to != le_min->end &&
			curr->path_next->belongs_to->ant == 0)
			curr = curr->path_next;
		if (curr->path_next->belongs_to == le_min->end)
		{
			path = path->next_path_in_room;
			continue ;
		}
		move_ants_rec(curr->path_next, le_min->end, le_min);
		path = path->next_path_in_room;
	}
}
