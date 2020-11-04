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

void bfs(t_lemin *lem_in)
{
	
}

/*void bfs(struct Graph* graph, int startVertex)
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
