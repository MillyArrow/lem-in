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
	t_room *room;

	room = lem->start;
	while (room != lem->end)
	{
		printf("%s -> ", room->name);
		room = room->path->edge->prev;
	}
	printf("%s\n", room->name);
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
				if (edge->prev->path->length + edge->weight < room->path->length)
				{
					room->path->length = edge->prev->path->length + edge->weight;
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

t_path	*init_path(void)
{
	t_path *path;

	if (!(path = (t_path*)ft_memalloc(sizeof(t_path))))
		return (NULL);
	path->length = 2147483646;
	path->edge = NULL;
	return (path);
}
