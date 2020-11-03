/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlintill <rlintill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 12:45:23 by rlintill          #+#    #+#             */
/*   Updated: 2020/10/07 13:37:24 by rlintill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include <stdio.h>

/*
** Needed for the debug. Delete later.
*/

void	print_graph(t_room *graph)
{
	t_room	*p;
	t_edge	*r;

	p = graph;
	r = NULL;
	while (p)
	{
		r = p->edge_next;
		printf("%s -> ", p->name);
		while (r)
		{
			printf("%s -> ", r->next->name);
			r = r->edge_next;
		}
		printf("NULL\n");
		p = p->room_next;
	}
	printf("\n");
}

int		main(int argc, char **argv)
{
	t_lemin	*lem;

	lem = parse_lem();
	print_graph(lem->graph);
	free_lemin(&lem);
	while (1)
	{
	}
	return (0);
}