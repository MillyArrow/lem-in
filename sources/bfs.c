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

void			bfs(t_lemin *lem_in)
{
	t_queue *queue;
	t_node	*node;
	t_room	*room_tmp;

	if (!(queue = (t_queue *)malloc_queue()))
		return ;
	queue_add_end(queue, lem_in->start);
	node = queue->first;
	room_tmp = (t_room *)node->room;
	while (!is_empty(queue))
	{
		print_queue(queue);
		room_tmp->visited = 1;
		ft_printf("Visited : %s\n",room_tmp->name);
		// adj list

		queue_del_top(queue);

	}

}

void			print_queue(t_queue *queue)
{
	t_room		*room_tmp;
	t_node 		*node_tmp;

	node_tmp = queue->first;
	ft_printf("Queue: ");
	while (node_tmp)
	{
		room_tmp = (t_room *)node_tmp->room;
		ft_printf("%s ", room_tmp->name);
		node_tmp = node_tmp->next;
	}
}

void			adj_list(t_node *node, t_lemin *lem_in)
{

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
