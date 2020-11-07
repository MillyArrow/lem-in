#include "lemin.h"

void		lock_path(t_room *out, t_room *to)
{
	t_edge *edge;

	edge = out->edge_next;
	while(edge)
	{
		if (edge->next == to)
			edge->locked = 1;
		edge = edge->edge_next;
	}
	edge = to->edge_prev;
	while(edge)
	{
		if (edge->prev == out)
			edge->locked = 1;
		edge = edge->edge_next;
	}
}

void		bhandari(t_lemin *le_min)
{
	t_edge	*edge;
	t_room	*room;

	search_path(le_min);
	ft_printf("PATH:\n");
	print_path(le_min);
	edge = le_min->start->path->edge;
	room = le_min->start;
	//lock_path(edge->next,edge->prev);
	while (edge)
	{
		edge->weight = -1;
		lock_path(edge->prev, edge->next);
		edge = edge->prev->path->edge;
	}
	while (room)
	{
		room->path->length = INT_MAX - 1;
		room = room->room_next;
	}
	search_path(le_min);
	ft_printf("NEW PATH:\n");
	print_path(le_min);
}
