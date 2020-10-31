/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.c                                            :+:      :+:    :+:   */
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
 * Needed for the debug. Delete later.
 */

void print_graph(t_edge *graph)
{
	t_edge	*p;
	t_room	*r;

	p = graph;
	r = NULL;
	while (p)
	{
		r = p->room;
		while (r)
		{
			printf("%s -> ",r->name);
			r = r->next;
		}
		printf("NULL\n");
		p = p->next;
	}
	printf("\n");
}

int	main(int argc, char **argv)
{
	t_lemin	*lem;

	lem = parse_lem();
	print_graph(lem->graph);
	
	return (0);
}