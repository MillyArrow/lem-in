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

t_room	*new_room(char *name)
{
	t_room *room;

	if (!(room = (t_room*)ft_memalloc(sizeof(t_room))))
		return (NULL);
	room->name = name;
	room->x = 0;
	room->y = 0;
	room->next = NULL;
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
	t_edge	*new;
	t_edge	**graph;

	graph = &(lem->graph);
	if (!(new = (t_edge*)ft_memalloc(sizeof(t_edge))))
		return ;
	new->visited = 0;
	new->room = room;
	new->next = *graph;
	*graph = new;
	if (flag == 1)
		lem->start = room;
	else if (flag == 2)
		lem->end = room;
	lem->rooms += 1;
}

/*
** Adding a new room to the end of the list of the rooms the original
** room point to.
** Is used when we add edges.
*/

void	add_room(t_edge *graph, t_room *new)
{
	t_room	*p;

	p = graph->room;
	while (p->next)
	{
		p = p->next;
	}
	p->next = new;
}
