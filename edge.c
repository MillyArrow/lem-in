/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edge.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlintill <rlintill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 12:45:23 by rlintill          #+#    #+#             */
/*   Updated: 2020/10/30 13:37:24 by rlintill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

/*
 * Returns a pointer to the rooms we search for. We search for the room
 * with ~name~ in the graph.
 */

static t_edge *search(t_edge *graph, char *name)
{
	t_edge	*p;

	p = graph;
	while (p)
	{
		if (ft_strcmp(name, p->room->name) == 0)
			return (p);
		p = p->next;
	}
	return (NULL);
}

/*
 * Adding connection between rooms. Making new copis of room(src)
 * and room(dst). With function search we find every of these rooms,
 * and using the add_room function add new copy to the end of the list
 * of the rooms the src point to. The same we do in the another direction.
 */

void add_edge(t_edge *graph, char *src, char *dst)
{
	t_room	*new;

	new = new_room(dst);
	add_room(search(graph,src), new);
	new = new_room(src);
	add_room(search(graph,dst), new);
}
