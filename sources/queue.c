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

t_queue			*malloc_queue(void)
{
	t_queue	*queue;

	if (!(queue = (t_queue*)ft_memalloc(sizeof(t_queue))))
		return (NULL);
	queue->first = NULL;
	queue->last = NULL;
	return (queue);
}

t_node			*malloc_node(void *item)
{
	t_node	*node;

	if (!(node = (t_node*)ft_memalloc(sizeof(t_node))))
		return (NULL);
	node->node = item;
	node->next = NULL;
	return (node);
}

void			queue_add_end(t_queue *queue, void *item)
{
	t_node	*node;

	if (!(node = malloc_queue_node(item)))
		return ;
	if (queue->last == NULL && queue->first == NULL)
	{
		queue->last = node;
		queue->first = node;
	}
	else
	{
		queue->last->next = node;
		queue->last = node;
	}
}

void			*queue_del_top(t_queue *queue)
{
	t_node			*node;
	void			*item;

	node = queue->first;
	if (node == NULL)
		return (NULL);
	item = node->node;
	queue->first = node->next;
	if (queue->first == NULL)
		queue->last = NULL;
	free(node);
	return (item);
}
