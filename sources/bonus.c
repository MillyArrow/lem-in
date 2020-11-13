/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrow <marrow@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 09:58:39 by marrow            #+#    #+#             */
/*   Updated: 2020/11/12 10:00:16 by marrow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void			print_graph(t_room *graph)
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

void			print_path(t_lemin *lem)
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

static void		bonus_help(void)
{
	ft_printf("Usage: ./lem-in < map_file\nOptions:\n");
	ft_printf("-e to prints errors\n");
	ft_printf("-g to prints graph\n");
	ft_printf("-p to prints paths\n");
	ft_printf("-c to print count paths\n");
	ft_printf("-r to print room count\n");
}

void			bonus(char **argv, t_lemin *le_min)
{
	if (!ft_strcmp("--help", argv[1]))
	{
		bonus_help();
		free_lemin(&le_min);
		exit(0);
	}
	else if (argv[1][0] == '-')
	{
		if (ft_strchr(argv[1], 'a'))
			le_min->bonus_print_count_ants = true;
		if (ft_strchr(argv[1], 'e'))
			le_min->bonus_print_errors = true;
		if (ft_strchr(argv[1], 'g'))
			le_min->bonus_print_graph = true;
		if (ft_strchr(argv[1], 'p'))
			le_min->bonus_print_path = true;
		if (ft_strchr(argv[1], 'c'))
			le_min->bonus_print_count_paths = true;
		if (ft_strchr(argv[1], 'r'))
			le_min->bonus_print_room_count = true;
		if (ft_strchr(argv[1], 'l'))
			le_min->bonus_print_line_count = true;
	}
	else
	{
		bonus_help();
		free_lemin(&le_min);
		exit(0);
	}
}
