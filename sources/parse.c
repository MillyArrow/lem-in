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
 * In the first line we are getting the number of the ants.
 */

int get_num_of_ants(void)
{
	char *line;
	int ants;
	int i;

	i = 0;
	ants = get_next_line(0, &line);
	if (ants < 0 || line[0] == '\0')
	{
		ft_strdel(&line);
		error();
	}
	if (!check_number(line))
		error();
	ants = ft_atoi(line);
	ft_strdel(&line);
	return (ants);
}

/*
 * Reads the input. First cycle is for the new rooms information, the 
 * second one is for connection information. 
 */

void fill_graph(t_lemin *lem)
{
	char *line;
	int check;

	check = 0;
	while (check_line(&line) && line != NULL)
	{
		if (ft_strchr(line, '-') != NULL)
			break;
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
	adding_edges(lem, line);
	ft_strdel(&line);
	while (check_edge_line(&line) && line != NULL)
	{
		adding_edges(lem, line);
		ft_strdel(&line);
	}
}

t_lemin *parse_lem(void)
{
	int 	ants_num;
	t_lemin	*lem;

	ants_num = get_num_of_ants();
	if (!(lem = init_lem()))
		return (NULL);
	lem->ants = ants_num;
	fill_graph(lem);
	return (lem);
}