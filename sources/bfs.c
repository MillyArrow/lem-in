/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrow <marrow@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 18:25:06 by marrow            #+#    #+#             */
/*   Updated: 2020/11/11 04:58:47 by marrow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void			adj_list(t_queue *queue)
{
	t_edge			*edge_next;
	t_room			*room_tmp;

	room_tmp = (t_room *)queue->head->room;
	edge_next = room_tmp->edge_prev;
	while (edge_next)
	{
		if (edge_next->locked == 0 && edge_next->same_edge->locked == 0)
		{
			room_tmp = edge_next->out;
			if (room_tmp->visited == 0)
				queue_add_end(queue, room_tmp);
		}
		edge_next = edge_next->edge_next;
	}
}

void				bfs(t_lemin *lem_in)
{
	t_queue			*queue;
	t_room			*room_tmp;

	if (!(queue = malloc_queue()))
		return ;
	room_tmp = NULL;
	queue_add_end(queue, lem_in->start);
	while (!is_empty(queue) && lem_in->end->visited != 1)
	{
		adj_list(queue);
		room_tmp = (t_room *)queue_del_top(queue);
		room_tmp->visited = 1;
	}
	free_queue(&queue);
}
