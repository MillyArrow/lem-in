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

t_lemin	*init_lem(void)
{
	t_lemin	*lem;

	if (!(lem = (t_lemin*)ft_memalloc(sizeof(t_lemin))))
		return (NULL);
	lem->ants = 0;
	lem->rooms = 0;
	lem->start = NULL;
	lem->end = NULL;
	lem->graph = NULL;
	return (lem);
}

t_graph *search(t_graph *graph, char *name)
{
	t_graph	*p;

	p = graph;
	while (p)
	{
		if (ft_strcmp(name, p->room->name) == 0)
			return (p);
		p = p->next;
	}
	return (NULL);
}

t_room	*new_room(char *name)
{
	t_room *room;

	if (!(room = (t_room*)ft_memalloc(sizeof(t_room))))
		return (NULL);
	room->name = name;
	room->next = NULL;
	return (room);
}

/*
** Тут пока нет учета start/end
*/

void	add_new_room(t_graph **graph, t_room *room)
{
	t_graph	*new;

	if (!(new = (t_graph*)ft_memalloc(sizeof(t_graph))))
		return ;
	new->room = room;
	new->next = *graph;
	*graph = new;
}

void	add_room(t_graph *graph, t_room *new)
{
	t_room	*p;

	p = graph->room;
	while (p->next)
	{
		p = p->next;
	}
	p->next = new;
}

void add_edge(t_graph *graph, char *src, char *dst)
{
	t_room	*new;

	new = new_room(dst);
	add_room(search(graph,src), new);
	new = new_room(src);
	add_room(search(graph,dst), new);
}

void print_graph(t_graph *graph)
{
	t_graph	*p;
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

	if (!(lem = init_lem()))
		return (1);
	add_new_room(&lem->graph, new_room("3"));
	add_new_room(&lem->graph, new_room("start"));
	add_new_room(&lem->graph, new_room("end"));
	add_new_room(&lem->graph, new_room("4"));
	add_new_room(&lem->graph, new_room("1"));
	add_new_room(&lem->graph, new_room("2"));
	add_new_room(&lem->graph, new_room("5"));
	add_new_room(&lem->graph, new_room("6"));
	print_graph(lem->graph);
	add_edge(lem->graph, "3", "4");
	add_edge(lem->graph, "start", "1");
	add_edge(lem->graph, "2", "4");
	add_edge(lem->graph, "1", "5");
	add_edge(lem->graph, "6", "5");
	add_edge(lem->graph, "end", "6");
	add_edge(lem->graph, "1", "2");
	add_edge(lem->graph, "2", "end");
	add_edge(lem->graph, "3", "start");
	print_graph(lem->graph);
	return (0);
}