/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edge.c                                            :+:      :+:    :+:   */
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
		edge->out = out;
		edge->to = to;
		edge->edge_next = out->edge_next;
		out->edge_next = edge;
	}
}

void	add_edges_prev(t_room *out, t_room *to, t_edge *edge)
{
	if (edge != NULL)
	{
		edge->to = to;
		edge->out = out;
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
	to_one->same_edge = out_two;
	to_two->same_edge = out_one;
	out_one->same_edge = to_two;
	out_two->same_edge = to_one;
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
	new->locked = 0;
	new->to = dst;
	new->out = src;
	new->same_edge = NULL;
	new->edge_next = NULL;
	return (new);
}

int			check_edge(t_room *one, t_room *two)
{
	t_edge	*edge;

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
	t_room	*one_room;
	t_room	*two_room;

	one_room = search(lem->graph, one);
	two_room = search(lem->graph, two);
	add_edges_to_rooms(one_room, two_room);
}
