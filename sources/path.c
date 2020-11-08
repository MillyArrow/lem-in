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
/*
void print_path(t_lemin *lem)
{
	t_room *room;

	room = lem->start;
	while (room != lem->end)
	{
		ft_printf("%s -> ", room->name);
		room = room->path->edge->out;
	}
	ft_printf("%s\n", room->name);
}
*/
void print_path(t_lemin *lem)
{
	t_path *pointer;
	t_path *path;
	t_room *room;

	path = lem->start->path->next_path;
	while (path)
	{
		ft_printf("%s -> ", lem->start->name);
		pointer = path->path;
		room = pointer->belongs_to;
		while (room != lem->end)
		{
			ft_printf("%s -> ", room->name);
			pointer = pointer->path;
			room = pointer->belongs_to;
		}
		ft_printf("%s\n", room->name);
		path = path->next_path;
	}
}

void search_path(t_lemin *lem)
{
	t_room	*room;
	t_edge *edge;
	int		i;

	i = 0;
	while (i < lem->rooms - 1)
	{
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
				if (edge->out->path->length + edge->weight < room->path->length
				&& edge->locked == 0)
				{
					room->path->length = edge->out->path->length + edge->weight;
					room->path->path = edge->out->path;
					room->path->edge = edge;
				}
				edge = edge->edge_next;
			}
			room = room->room_next;
		}
		i++;
	}
}

/*
** length = infinity = max_int - 1;
*/

void	add_path(t_room *room, t_path *new)
{
	new->next_path = room->path;
	room->path = new;
}

t_path	*init_path(t_room *room)
{
	t_path *path;

	if (!(path = (t_path*)ft_memalloc(sizeof(t_path))))
		return (NULL);
	path->length = INT_MAX - 1;
	path->belongs_to = room;
	path->edge = NULL;
	path->path = NULL;
	path->next_path = NULL;
	return (path);
}
