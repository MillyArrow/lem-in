/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bhandari.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrow <marrow@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 05:05:08 by marrow            #+#    #+#             */
/*   Updated: 2020/11/11 05:09:40 by marrow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void		initialize_before(t_lemin *lem)
{
	t_room	*room;

	room = lem->graph;
	while (room)
	{
		room->visited = 0;
		add_path_room(room, init_path(room));
		room = room->room_next;
	}
	lem->end->path->length = 0;
}

void		lock_all_pathes(t_edge *edge)
{
	t_edge	*ed;

	while (edge)
	{
		edge->weight = -1;
		ed = edge->out->edge_next;
		while (ed)
		{
			if (ed->to == edge->to)
			{
				ed->locked = 1;
				ed->same_edge->locked = 1;
				ed->to->locked = 1;
				break ;
			}
			ed = ed->edge_next;
		}
		edge = edge->out->path->edge;
	}
}

t_path		*switch_links(t_path *pointer, t_path *pointer_prev)
{
	t_path	*two;

	two = pointer->edge->oppos_edge->belongs_to_path->path_next;
	pointer_prev->path_next = two;
	pointer_prev->edge->same_edge->belongs_to_path->path_next = two;
	return (two);
}

void		delete_links(t_lemin *lem)
{
	t_path	*pointer;
	t_path	*path;
	t_path	*pointer_prev;

	path = lem->start->path->next_path_in_room;
	while (path)
	{
		pointer_prev = path;
		pointer = path->path_next;
		while (pointer->belongs_to != lem->end)
		{
			if (pointer->edge->locked == 1 &&
			pointer->edge->oppos_edge->locked == 1)
				pointer = switch_links(pointer, pointer_prev);
			else
			{
				pointer_prev = pointer;
				pointer = pointer->path_next;
			}
		}
		path = path->next_path_in_room;
	}
}

void		bhandari(t_lemin *le_min)
{
	search_path(le_min);
	lock_all_pathes(le_min->start->path->edge);
	initialize_before(le_min);
	bfs(le_min);
	while (le_min->end->visited)
	{
		search_path(le_min);
		lock_all_pathes(le_min->start->path->edge);
		initialize_before(le_min);
		bfs(le_min);
	}
	delete_links(le_min);
	recount(le_min->start->path);
	merge_sort(&(le_min->start->path->next_path_in_room));
}
