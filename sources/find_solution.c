/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_solution.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlintill <rlintill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 12:45:23 by rlintill          #+#    #+#             */
/*   Updated: 2020/11/12 09:59:52 by rlintill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int		check_room(t_room **arr_room, t_room *room, int size)
{
	int		result;

	result = 0;
	while (result < size && arr_room[result] != NULL)
	{
		if (arr_room[result] == room)
			return (-1);
		++result;
	}
	return (result);
}

static void		find_solution_help(t_path **path, t_path *prev,
									t_room **arr_room, int size)
{
	t_path	*tmp_path;
	t_path	*path_prev;
	int		number;

	number = 0;
	tmp_path = (*path)->path_next;
	path_prev = prev;
	while (tmp_path)
	{
		if (tmp_path->belongs_to->is_used > 1)
		{
			number = check_room(arr_room,
				tmp_path->belongs_to, size);
			if (number >= 0)
				arr_room[number] = tmp_path->belongs_to;
			else if (number == -1)
			{
				ft_memdel((void*)&(path_prev->next_path_in_room));
				path_prev->next_path_in_room = (*path)->next_path_in_room;
				*path = path_prev;
				break ;
			}
		}
		tmp_path = tmp_path->path_next;
	}
}

void			find_solution(t_path *path, t_lemin *lemin)
{
	t_path	*path_prev;
	t_room	**arr_room;

	arr_room = ft_memalloc(sizeof(arr_room) * (lemin->rooms - 2));
	path_prev = path;
	path = path->next_path_in_room;
	while (path)
	{
		find_solution_help(&path, path_prev, arr_room, lemin->rooms - 2);
		path_prev = path;
		path = path->next_path_in_room;
	}
	ft_memdel((void*)&(arr_room));
}
