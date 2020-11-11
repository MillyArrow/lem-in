/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlintill <rlintill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 12:45:23 by rlintill          #+#    #+#             */
/*   Updated: 2020/11/11 05:00:15 by rlintill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	print_graph(t_room *graph)
{
	t_room	*p;
	t_edge	*r;

	p = graph;
	r = NULL;
	while (p)
	{
		r = p->edge_next;
		ft_printf("%s -> ", p->name);
		while (r)
		{
			ft_printf("%s -> ", r->to->name);
			r = r->edge_next;
		}
		ft_printf("NULL\n");
		p = p->room_next;
	}
	ft_printf("\n");
}

void	print_path(t_lemin *lem)
{
	t_path		*pointer;
	t_path		*path;
	t_room		*room;

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
