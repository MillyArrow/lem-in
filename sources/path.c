/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrow <marrow@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 12:45:23 by rlintill          #+#    #+#             */
/*   Updated: 2020/11/11 05:00:15 by marrow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void			search_path_help(t_room *room, int *changed)
{
	t_edge		*edge;

	edge = room->edge_prev;
	while (edge != NULL)
	{
		if (edge->locked == 0 && edge->same_edge->locked == 0 &&
			edge->out->locked == 0 &&
			edge->out->path->length + edge->weight < room->path->length)
		{
			room->path->length = edge->out->path->length + edge->weight;
			room->path->path_next = edge->out->path;
			room->path->edge = edge;
			add_path_edge(edge, room->path);
			add_path_edge(edge->same_edge, room->path);
			*changed = 1;
		}
		edge = edge->edge_next;
	}
}

void				search_path(t_lemin *lem)
{
	t_room		*room;
	int			i;
	int			changed;

	i = 0;
	while (i < lem->rooms - 1)
	{
		changed = 0;
		room = lem->graph;
		while (room != NULL)
		{
			if (room == lem->end)
			{
				room = room->room_next;
				continue ;
			}
			search_path_help(room, &changed);
			room = room->room_next;
		}
		if (changed == 0)
			break ;
		i++;
	}
}

/*
** length = infinity = max_int - 1;
*/

void				add_path_room(t_room *room, t_path *new)
{
	new->next_path_in_room = room->path;
	room->path = new;
}

void				add_path_edge(t_edge *edge, t_path *new)
{
	new->next_path_in_edge = edge->belongs_to_path;
	edge->belongs_to_path = new;
}

t_path				*init_path(t_room *room)
{
	t_path		*path;

	if (!(path = (t_path*)ft_memalloc(sizeof(t_path))))
		return (NULL);
	path->length = INT_MAX - 1;
	path->belongs_to = room;
	path->edge = NULL;
	path->path_next = NULL;
	path->next_path_in_edge = NULL;
	path->next_path_in_room = NULL;
	return (path);
}
