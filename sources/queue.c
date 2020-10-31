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
 * Tried to release a structure for the bfs. Leave for the later.
 */

t_queue			*malloc_queue()
{
	t_queue	*queue;

	if (!(queue = (t_queue*)ft_memalloc(sizeof(t_queue))))
		return (NULL);
	queue->first = NULL;
	queue->last = NULL;
	return (queue);
}

t_queue_node	*malloc_queue_node(void *item)
{
	t_queue_node	*node;

	if (!(node = (t_queue_node*)ft_memalloc(sizeof(t_queue_node))))
		return (NULL);
	node->node = item;
	node->next = NULL;
	return (node);
}

void	add_queue(t_queue *queue, void *item)
{
	t_queue_node	*node;

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

void	*pop_queue(t_queue *queue)
{
	t_queue_node	*node;
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
