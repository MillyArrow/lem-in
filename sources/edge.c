/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edge.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrow <marrow@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 05:01:01 by marrow            #+#    #+#             */
/*   Updated: 2020/11/11 05:01:48 by marrow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

/*
** Adding new edges to the certian rooms.
*/

void			add_edges_next(t_room *out, t_room *to, t_edge *edge)
{
	if (edge != NULL)
	{
		edge->out = out;
		edge->to = to;
		edge->edge_next = out->edge_next;
		out->edge_next = edge;
	}
}

void			add_edges_prev(t_room *out, t_room *to, t_edge *edge)
{
	if (edge != NULL)
	{
		edge->to = to;
		edge->out = out;
		edge->edge_next = to->edge_prev;
		to->edge_prev = edge;
	}
}

void			add_edges_to_rooms(t_room *one, t_room *two)
{
	t_edge		*to_one;
	t_edge		*to_two;
	t_edge		*out_one;
	t_edge		*out_two;

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
	to_one->oppos_edge = out_one;
	to_two->oppos_edge = out_two;
	out_one->oppos_edge = to_one;
	out_two->oppos_edge = to_two;
	add_edges_next(two, one, to_one);
	add_edges_next(one, two, to_two);
	add_edges_prev(two, one, out_two);
	add_edges_prev(one, two, out_one);
}

t_edge			*new_edge(t_room *src, t_room *dst)
{
	t_edge		*new;

	if (!(new = (t_edge*)ft_memalloc(sizeof(t_edge))))
		return (NULL);
	new->weight = 1;
	new->locked = 0;
	new->to = dst;
	new->out = src;
	new->belongs_to_path = NULL;
	new->oppos_edge = NULL;
	new->same_edge = NULL;
	new->edge_next = NULL;
	return (new);
}
