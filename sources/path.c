/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlintill <rlintill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 12:45:23 by rlintill          #+#    #+#             */
/*   Updated: 2020/11/05 13:37:24 by rlintill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include <stdio.h>

void print_path(t_lemin *lem)
{
	t_path *pointer;
	t_path *path;
	t_room *room;

	path = lem->start->path->next_path_in_room;
	while (path)
	{
		ft_printf("Length: %i [%s -> ", path->length, lem->start->name);
		pointer = path->path_next;
		room = pointer->belongs_to;
		while (room != lem->end)
		{
			ft_printf("%s -> ", room->name);
			pointer = pointer->path_next;
			room = pointer->belongs_to;
		}
		ft_printf("%s]\n", room->name);
		path = path->next_path_in_room;
	}
	ft_printf("\n");
}

void search_path(t_lemin *lem)
{
	t_room	*room;
	t_edge *edge;
	int		i;
	int		changed;

	i = 0;
	while (i < lem->rooms - 1)
	{
		changed = 0;
		room = lem->graph;
		while (room != NULL)
		{
			edge = room->edge_prev;
			if (room == lem->end)
			{
				room = room->room_next;
				continue ;
			}
			while (edge != NULL)
			{
				if (edge->locked == 0 &&
				edge->out->path->length + edge->weight < room->path->length)
				{
					room->path->length = edge->out->path->length + edge->weight;
					room->path->path_next = edge->out->path;
					room->path->path_next->path_prev = room->path;
					room->path->edge = edge;
					add_path_edge(edge, room->path);
					add_path_edge(edge->same_edge, room->path);
					changed = 1;
				}
				edge = edge->edge_next;
			}
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

void	add_path_room(t_room *room, t_path *new)
{
	new->next_path_in_room = room->path;
	room->path = new;
}

void	add_path_edge(t_edge *edge, t_path *new)
{
	new->next_path_in_edge = edge->belongs_to_path;
	edge->belongs_to_path = new;
}

t_path	*init_path(t_room *room)
{
	t_path *path;

	if (!(path = (t_path*)ft_memalloc(sizeof(t_path))))
		return (NULL);
	path->length = INT_MAX - 1;
	path->belongs_to = room;
	path->edge = NULL;
	path->path_next = NULL;
	path->path_prev = NULL;
	path->next_path_in_edge = NULL;
	path->next_path_in_room = NULL;
	return (path);
}
