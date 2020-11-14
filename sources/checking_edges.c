/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_edges.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrow <marrow@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 12:45:23 by rlintill          #+#    #+#             */
/*   Updated: 2020/11/11 05:02:20 by marrow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

/*
** Ignoring the comments.
*/

void	check_edge_line_help(char **new_line)
{
	if ((*new_line)[0] == '#' && (*new_line)[1] == '#')
	{
		ft_strdel(new_line);
		write(2, "ERROR\n", 6);
		exit(0);
	}
	if ((*new_line)[0] == '#')
	{
		ft_putstr(*new_line);
		ft_putchar('\n');
		ft_strdel(new_line);
	}
}

int		check_edge_line(char **line)
{
	int		res;
	char	*new_line;

	while ((res = get_next_line(0, &new_line)))
	{
		if (new_line[0] == '\0')
		{
			ft_strdel(&new_line);
			break ;
		}
		if (new_line[0] == '#')
			check_edge_line_help(&new_line);
		else
		{
			*line = new_line;
			ft_putstr(*line);
			ft_putchar('\n');
			break ;
		}
	}
	return (res);
}

/*
** First of all we check the correctness of the input. Make sure
** that all of the room are existing, and finally adding the edge.
*/

void	adding_edges(t_lemin *lem, char *line)
{
	char	**str;

	str = ft_strsplit(line, '-');
	if (str == NULL || str[0] == NULL || str[0][0] == 'L' || !str[1])
		error_w_del(&line, "wrong line", lem);
	if (search_names(lem, str[0], str[1]) != 2)
		error_w_del(&line, "misnames of rooms in links", lem);
	add_edge(lem, str[0], str[1]);
	ft_arrdel((void ***)&str);
}
