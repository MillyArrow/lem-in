/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_rooms.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlintill <rlintill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 12:45:23 by rlintill          #+#    #+#             */
/*   Updated: 2020/10/27 13:37:24 by rlintill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

/*
** Check whether line is correct. With GNL we read from the input,
** if the line is correct we change the pointer to the line and break the cycle.
** If the line is comment - we igonre it. If something is wrong with the
** input (res < 0, new_line is "\0", it's the special input ##
** but not start/end) - error.
*/

int		check_line(char **line)
{
	int		res;
	char	*new_line;

	while ((res = get_next_line(0, &new_line)))
	{
		if (res < 0 || new_line[0] == '\0')
			error_w_del(&new_line);
		if (new_line[0] == '#' && new_line[1] == '#' &&
			ft_strcmp("##start", new_line) && ft_strcmp("##end", new_line))
			error_w_del(&new_line);
		if (new_line[0] != '#' || !ft_strcmp("##end", new_line)
					|| !ft_strcmp("##start", new_line))
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
** Checking the correctness of the input. Check if the x, y are numbers.
** Check wherether there was no room with the same pair of coordinates and name.
*/

void	check_input(t_lemin *lem, char **str)
{
	int		x;
	int		y;
	char	*x_str;
	char	*y_str;

	x_str = str[1];
	y_str = str[2];
	if (!check_number(x_str) || !check_number(y_str))
		error();
	x = ft_atoi(x_str);
	y = ft_atoi(y_str);
	if (search_coord(lem, x, y))
		error();
	if (search_name(lem, str[0]))
		error();
}

/*
** First of all we check the correctness of the input.
** We check wherether there only one ~start~ or ~end~ room.
** Check the input with check_input(...) and finally adding it.
*/

void	add_rooom(t_lemin *lem, int check, char *line)
{
	char	**str;
	char	*new_line;
	int		res;
	int		len;
	t_room	*room;

	if (check == 1 && lem->start != NULL)
		error();
	if (check == 2 && lem->end != NULL)
		error();
	new_line = line;
	len = ft_strlen(new_line);
	if (*new_line == ' ' || new_line[len - 1] == ' ')
		error();
	str = ft_strsplit(new_line, ' ');
	if (str == NULL || str[0] == NULL || str[0][0] == 'L')
		error();
	if (!str[1] || !str[2] || str[3] || str[0][0] == '#')
		error();
	check_input(lem, str);
	room = new_room(ft_strdup(str[0]));
	room->x = ft_atoi(str[1]);
	room->y = ft_atoi(str[2]);
	add_new_room(lem, room, check);
	free_arr(str);
}
