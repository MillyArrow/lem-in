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
	return (node);
}

t_queue			*malloc_queue(void)
{
	t_queue 	*queue;

	if (!(queue = (t_queue*)ft_memalloc(sizeof(t_queue))))
		return (NULL);
	queue->head = NULL;
	queue->tail = NULL;
	return (queue);
}

void			queue_add_end(t_queue *queue, void *item)
{
	t_node	*new_node;

	if (!(new_node = malloc_node(item)))
		return ;
	if (queue->tail == NULL && queue->head == NULL)
	{
		queue->head = new_node;
		queue->tail = new_node;
	}
	else
	{
		queue->tail->next = new_node;
		queue->tail = new_node;
	}
}

void			*queue_del_top(t_queue *queue)
{
	t_node			*tmp;
	void			*item;

	tmp = queue->head;
	if (tmp == NULL)
		return (NULL);
	item = tmp->room;
	queue->head = tmp->next;
	if (queue->head == NULL)
		queue->tail = NULL;
	free(tmp);
	return (item);
}

int 			is_empty(t_queue *queue)
{
	if (queue->head == NULL && queue->tail == NULL)
		return(TRUE);
	else
		return(FALSE);
}
