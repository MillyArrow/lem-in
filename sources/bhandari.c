#include "lemin.h"

void		bhandari(t_lemin *le_min)
{
	t_edge	*edge;
	t_room	*room;

	search_path(le_min);
	ft_printf("PATH:\n");
	print_path(le_min);
	edge = le_min->start->path->edge;
	room = le_min->start;
	while(edge)
	{
		edge->weight = -1;
		ft_printf("ID EDGE:%d\n",edge->id);
		edge = edge->prev->path->edge;
	}
	search_path(le_min);
	ft_printf("PATH:\n");
	print_path(le_min);
}

void		lock_path(t_lemin *le_min)
{
	t_edge *edge;

	edge = le_min->start->path->edge->edge_next;
	while(edge)
	{
		edge->locked = 1;

	}
}
