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

int		check_edge_line(char **line)
{
	int		res;
	char	*new_line;

	while ((res = get_next_line(0, &new_line)))
	{
		if (new_line[0] == '\0')
			break ;
		if (new_line[0] != '#')
		{
			*line = new_line;
			ft_putstr(*line);
			ft_putchar('\n');
			break ;
		}
		else
			ft_strdel(&new_line);
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
		error_w_del(&line);
	if (search_names(lem, str[0], str[1]) != 2)
		error_w_del(&line);
	add_edge(lem, str[0], str[1]);
	free_arr(str);
}
