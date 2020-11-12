/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlintill <rlintill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 12:45:23 by rlintill          #+#    #+#             */
/*   Updated: 2020/10/27 13:37:24 by rlintill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

/*
** In the first line we are getting the number of the ants.
*/

static int			get_num_of_ants(t_lemin *lem)
{
	char	*line;
	int		ants;

	line = NULL;
	ants = get_next_line(0, &line);
	if (ants < 0 || line[0] == '\0' || line == NULL)
		error_w_del(&line, "misplaced number of ants or line", lem);
	if (!ft_isint(line))
		error_w_del(&line, "misplaced number of ants", lem);
	ants = ft_atoi(line);
	if (ants <= 0)
		error_w_del(&line, "misplaced number of ants", lem);
	ft_putstr(line);
	ft_putchar('\n');
	ft_strdel(&line);
	return (ants);
}

/*
** Checks if there is the start and the end room.
*/

static void			is_start_end(t_lemin *lem, char **line)
{
	if (lem->start == NULL || lem->end == NULL)
	{
		ft_strdel(line);
		error("wrong start or end", lem);
	}
}

static void			fill_graph_continue(t_lemin *lem, char **line)
{
	while (check_edge_line(line) && *line != NULL)
	{
		adding_edges(lem, *line);
		ft_strdel(line);
	}
}

/*
** Reads the input. First cycle is for the new rooms information, the
** second one is for connection information.
*/

static void			fill_graph(t_lemin *lem)
{
	char	*line;
	int		check;

	check = 0;
	while (check_line(&line, lem) && line != NULL)
	{
		if (ft_strchr(line, '-') != NULL)
			break ;
		if (ft_strcmp(line, "##start") == 0)
			check = 1;
		else if (ft_strcmp(line, "##end") == 0)
			check = 2;
		else
		{
			add_rooom(lem, check, line);
			check = 0;
		}
		ft_strdel(&line);
	}
	is_start_end(lem, &line);
	adding_edges(lem, line);
	ft_strdel(&line);
	fill_graph_continue(lem, &line);
}

t_lemin				*parse_lem(t_lemin *lem)
{
	int		ants_num;

	ants_num = get_num_of_ants(lem);
	lem->ants = ants_num;
	fill_graph(lem);
	ft_putchar('\n');
	if (lem->bonus_print_count_ants)
		ft_printf("{black}NUMBER OF ANTS: %d{eoc}\n", lem->ants);
	if (lem->bonus_print_room_count)
		ft_printf("{black}NUMBER OF ROOMS: %d{eoc}\n", lem->rooms);
	if (lem->bonus_print_graph)
	{
		ft_printf("{cyan}GRAPH:{eoc}\n");
		print_graph(lem->graph);
	}
	return (lem);
}
