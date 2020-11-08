/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlintill <rlintill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 12:45:23 by rlintill          #+#    #+#             */
/*   Updated: 2020/10/30 13:37:24 by rlintill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

/*
** All the functions which are needed for the room structure are placed here.
*/

t_room	*new_room(char *name, char *x, char *y)
{
	t_room *room;

	if (!(room = (t_room*)ft_memalloc(sizeof(t_room))))
		return (NULL);
	room->name = name;
	room->visited = 0;
	room->x = ft_atoi(x);
	room->y = ft_atoi(y);
	room->path = init_path(room);
	room->edge_next = NULL;
	room->edge_prev = NULL;
	room->room_next = NULL;
	return (room);
}

/*
** Adding new room to the graph. Adding in the beginning.
** flag - shows as whether new room is start, end or a regular room.
**     0 - regular room
** 	   1 - the start
**     2 - the end
** In case flag is not 0, assign the pointer of the start/end
*/

void	add_new_room(t_lemin *lem, t_room *room, int flag)
{
	room->room_next = lem->graph;
	lem->graph = room;
	if (flag == 1)
	{
		
		lem->start = room;
	}
	else if (flag == 2)
	{
		room->path->length = 0;
		lem->end = room;
	}
	lem->rooms += 1;
}
