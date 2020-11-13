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

int			check_room(t_room **arr_room, t_room *room, int size)
{
	int		result;

	result = 0;
	while (result < size && arr_room[result] != NULL)
	{
		if (arr_room[result] == room)
			return -1;
		++result;
	}
	return result;
}

void			find_solution(t_path *path,t_lemin *lemin)
{
	t_path	*tmp_path;
	t_path	*path_prev;
	t_room 	**arr_room;//array of room
	int 	number;
/*	char *name;
	char *name1;*/

	number = 0;
	arr_room = ft_memalloc(sizeof(arr_room) * (lemin->rooms - 2));
	path_prev = path;
	path = path->next_path_in_room;
	while (path)
	{
		tmp_path = path->path_next;
/*		if (!ft_strcmp(tmp_path->belongs_to->name,"Sm_3"))
			name = "Sm_3";
		if (!ft_strcmp(tmp_path->belongs_to->name,"Fvs6"))
			name1 = "Fvs6";*/
		while(tmp_path)
		{
/*			if (!ft_strcmp(name,"Sm_3") && !ft_strcmp(tmp_path->belongs_to->name,"Nip1"))
				3;
			if (!ft_strcmp(name1,"Fvs6") && !ft_strcmp(tmp_path->belongs_to->name,"Nip1"))
				3;*/
			if (tmp_path->belongs_to->is_used > 1)
			{
				number = check_room(arr_room, tmp_path->belongs_to, lemin->rooms - 2);
				if (number >= 0)
					arr_room[number] = tmp_path->belongs_to;
				else if (number == -1)
				{
					path_prev->next_path_in_room = path->next_path_in_room;
					path = path_prev;
					break ;
				}
			}
			tmp_path = tmp_path->path_next;
		}
		path_prev = path;
		path = path->next_path_in_room;
	}

}