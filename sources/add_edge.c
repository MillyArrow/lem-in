/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_edge.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrow <marrow@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 05:01:01 by marrow            #+#    #+#             */
/*   Updated: 2020/11/11 05:01:48 by marrow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

/*
** Returns a pointer to the rooms we search for. We search for the room
** with ~name~ in the graph.
*/

static t_room	*search(t_room *graph, char *name)
{
	t_room		*p;

	p = graph;
	while (p)
	{
		if (ft_strcmp(name, p->name) == 0)
			return (p);
		p = p->room_next;
	}
	return (NULL);
}

int				check_edge(t_room *one, t_room *two)
{
	t_edge		*edge;

	edge = one->edge_next;
	while (edge)
	{
		if (edge->to == two)
			return (1);
		edge = edge->edge_next;
	}
	return (0);
}

/*
** Adding connection between rooms. Making new copis of room(src)
** and room(dst). With function search we find every of these rooms,
** and using the add_room function add new copy to the end of the list
** of the rooms the src point to. The same we do in the another direction.
*/

void			add_edge(t_lemin *lem, char *one, char *two)
{
	t_room		*one_room;
	t_room		*two_room;

	one_room = search(lem->graph, one);
	two_room = search(lem->graph, two);
	if (check_edge(one_room, two_room))
		return ;
	add_edges_to_rooms(one_room, two_room);
}
