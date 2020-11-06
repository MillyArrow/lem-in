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
** Adding new edges to the certian rooms.
*/

void	add_edges_next(t_room *out, t_room *to, t_edge *edge)
{
	if (edge != NULL)
	{
		edge->prev = out;
		edge->next = to;
		edge->edge_next = out->edge_next;
		out->edge_next = edge;
	}
}

void	add_edges_prev(t_room *out, t_room *to, t_edge *edge)
{
	if (edge != NULL)
	{
		edge->next = to;
		edge->prev = out;
		edge->edge_next = to->edge_prev;
		to->edge_prev = edge;
	}
}

void	add_edges_to_rooms(t_room *one, t_room *two)
{
	t_edge	*to_one;
	t_edge	*to_two;
	t_edge	*out_one;
	t_edge	*out_two;

	if (!(to_one = new_edge(two, one)))
		return ;
	if (!(to_two = new_edge(one, two)))
		return ;
	if (!(out_one = new_edge(one, two)))
		return ;
	if (!(out_two = new_edge(two, one)))
		return ;
	add_edges_next(two, one, to_one);
	add_edges_next(one, two, to_two);
	add_edges_prev(two, one, out_two);
	add_edges_prev(one, two, out_one);
}

/*
** Returns a pointer to the rooms we search for. We search for the room
** with ~name~ in the graph.
*/

static t_room	*search(t_room *graph, char *name)
{
	t_room	*p;

	p = graph;
	while (p)
	{
		if (ft_strcmp(name, p->name) == 0)
			return (p);
		p = p->room_next;
	}
	return (NULL);
}

t_edge	*new_edge(t_room *src, t_room *dst)
{
	t_edge	*new;

	if(!(new = (t_edge*)ft_memalloc(sizeof(t_edge))))
		return (NULL);
	new->weight = 1;
	new->next = dst;
	new->prev = src;
	new->edge_next = NULL;
	return (new);
}

/*
** Adding connection between rooms. Making new copis of room(src)
** and room(dst). With function search we find every of these rooms,
** and using the add_room function add new copy to the end of the list
** of the rooms the src point to. The same we do in the another direction.
*/

void			add_edge(t_room *graph, char *src, char *dst)
{
	t_room	*one_room;
	t_room	*two_room;

	one_room = search(graph, src);
	two_room = search(graph, dst);
	add_edges_to_rooms(one_room, two_room);
}
