/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrow <marrow@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 12:45:23 by rlintill          #+#    #+#             */
/*   Updated: 2020/11/12 09:59:52 by marrow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int			check_number(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	count_length(t_path *path)
{
	int		count;
	t_path	*p;

	count = 1;
	p = path->path_next;
	while (p)
	{
		if (p->length == 0 || p->edge == NULL)
			break ;
		count += 1;
		p = p->path_next;
	}
	return (count);
}

void		recount(t_path *paths)
{
	t_path	*path;

	path = paths->next_path_in_room;
	while (path)
	{
		path->length = count_length(path);
		path = path->next_path_in_room;
	}
}

int			count_paths(t_path *path)
{
	int count;

	count = 0;
	path = path->next_path_in_room;
	while (path)
	{
		++count;
		path = path->next_path_in_room;
	}
	return (count);
}
