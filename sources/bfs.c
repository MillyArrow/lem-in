/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrow <marrow@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 18:25:06 by marrow            #+#    #+#             */
/*   Updated: 2020/11/04 20:46:00 by marrow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int			search_n(t_queue *queue, char *room_name)
{
	t_node			*n;
	t_room			*r;

	n = queue->head;
	while (n)
	{
		r = n->room;
		if (!ft_strcmp(room_name, r->name))
			return (TRUE);
		n = n->next;
	}
	return (FALSE);
}

static void			print_queue(t_queue *queue)
{
	t_room			*room_tmp;
	t_node 			*node_tmp;

	node_tmp = queue->head;
	ft_printf("Queue: \n");
	while (node_tmp)
	{
		room_tmp = (t_room *)node_tmp->room;
		ft_printf("%s \n", room_tmp->name);
		node_tmp = node_tmp->next;
	}
}

static void			adj_list(t_queue *queue, t_lemin *lem_in)
{
	t_edge 			*edge_next;
	t_room 			*room_tmp;

	room_tmp = (t_room *)queue->head->room;
	edge_next = room_tmp->edge_next;
	while (edge_next)
	{
		if (edge_next->next)
		{
			room_tmp = edge_next->next;
			if (room_tmp->visited == 0 && !search_n(queue, room_tmp->name))
				queue_add_end(queue, room_tmp);
		}
		edge_next = edge_next->edge_next;
	}
}

void				bfs(t_lemin *lem_in)
{
	t_queue 		*queue;
	t_room			*room_tmp;

	if(!(queue = malloc_queue()))
		return ;
	room_tmp = NULL;
	queue_add_end(queue, lem_in->start);
	while (!is_empty(queue))
	{
		print_queue(queue);
		adj_list(queue, lem_in);
		room_tmp = (t_room *)queue_del_top(queue);
		room_tmp->visited = 1;
		ft_printf("Visited : %s\n", room_tmp->name);
	}
}
/*
 * Обход графа в ширину.
Помещаем каждую вершину графа в одну из категорий:
1. Посещено
2. Не посещено
Цель алгоритма пометить каждую вершину "Посещенной", избегая циклов.
Работа алгоритма:
1.Помещаем одну из вершин графа в конец очереди.
2.Берем первый эл-т очереди и добавляем его в список посещенных.
3.Создаем список соседних узлов этой вершины.Добавляем те,
 которых нет в списке посещенных в конец очереди.
4. Повторяем шаги 2 и 3 пока очередь не опустеет
 void bfs(struct Graph* graph, int startVertex)
{
	struct queue* q = createQueue();

	graph->visited[startVertex] = 1;
	enqueue(q, startVertex);

	while (!isEmpty(q)) {
		printQueue(q);
		int currentVertex = dequeue(q);
		printf("Visited %d\n", currentVertex);

		struct node* temp = graph->adjLists[currentVertex];

		while (temp)
		{
			int adjVertex = temp->vertex;

			if (graph->visited[adjVertex] == 0)
			{
				graph->visited[adjVertex] = 1;
				enqueue(q, adjVertex);
			}
			temp = temp->next;
		}
	}
}*/
