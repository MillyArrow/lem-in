/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlintill <rlintill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 12:45:23 by rlintill          #+#    #+#             */
/*   Updated: 2020/10/13 13:37:24 by rlintill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"

/*
** Tried to release a structure for the bfs. Leave for the later.
*/

t_node			*malloc_node(void *item)
{
	t_node	*node;

	if (!(node = (t_node*)ft_memalloc(sizeof(t_node))))
		return (NULL);
	node->room = item;
	node->next = NULL;
	node->head = NULL;
	node->tail = NULL;
	return (node);
}

t_node			*malloc_queue(void)
{
	t_node	*node;

	if (!(node = (t_node*)ft_memalloc(sizeof(t_node))))
		return (NULL);
	node->room = NULL;
	node->next = NULL;
	node->head = NULL;
	node->tail = NULL;
	return (node);
}

void			queue_add_end(t_node *node, void *item)
{
	t_node	*new_node;

	if (!(new_node = malloc_node(item)))
		return ;
	if (node->tail == NULL && node->head == NULL)
	{
		node->head = new_node;
		node->tail = new_node;
	}
	else
	{
		node->tail->next = new_node;
		node->tail = new_node;
	}
}

void			*queue_del_top(t_node *node)
{
	t_node			*tmp;
	void			*item;

	tmp = node->head;
	if (tmp == NULL)
		return (NULL);
	item = tmp->room;
	node->head = node->next;
	if (node->head == NULL)
		node->tail = NULL;
	free(tmp);
	return (item);
}

int 			is_empty(t_node *queue)
{
	if (queue->head == NULL && queue->tail == NULL)
		return(TRUE);
	else
		return(FALSE);
}
