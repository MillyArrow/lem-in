/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlintill <rlintill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 12:45:23 by rlintill          #+#    #+#             */
/*   Updated: 2020/11/05 13:37:24 by rlintill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_path 	*sm_dir(t_path *a, t_path *b)
{
	t_path *result;

	result = NULL;
	if (a == NULL)
		return (b);
	else if (b == NULL)
		return (a);
	if (a->length < b->length)
	{
		result = a;
		result->next_path_in_room = sm_dir(a->next_path_in_room, b);
	}
	else
	{
		result = b;
		result->next_path_in_room = sm_dir(a, b->next_path_in_room);
	}
	return (result);
}

void	front_back_split_help(t_path **fast, t_path **slow)
{
	while (*fast != NULL)
	{
		*fast = (*fast)->next_path_in_room;
		if (*fast != NULL)
		{
			*slow = (*slow)->next_path_in_room;
			*fast = (*fast)->next_path_in_room;
		}
	}
}

void	frontback_split(t_path *src, t_path **front, t_path **back)
{
	t_path 	*fast;
	t_path 	*slow;

	slow = src;
	fast = NULL;
	fast = src->next_path_in_room;
	front_back_split_help(&fast, &slow);
	*front = src;
	*back = slow->next_path_in_room;
	slow->next_path_in_room = NULL;
}

void	merge_sort(t_path **pathes)
{
	t_path	*head;
	t_path	*a;
	t_path	*b;

	head = *pathes;
	a = NULL;
	b = NULL;
	if (head == NULL || head->next_path_in_room == NULL)
		return ;
	frontback_split(head, &a, &b);
	merge_sort(&a);
	merge_sort(&b);
	*pathes = sm_dir(a, b);
}


