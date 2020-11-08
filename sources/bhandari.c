#include "lemin.h"

void		lock_path(t_room *out, t_room *to)
{
	t_edge *edge;

	edge = out->edge_next;
	while(edge)
	{
		if (edge->to == to)
		{
			edge->locked = 1;
			edge->same_edge->locked = 1;
			break ;
		}
		edge = edge->edge_next;
	}
}

void		unlock_path(t_room *out, t_room *to)
{
	t_edge *edge;

	edge = out->edge_next;
	while(edge)
	{
		if (edge->to == to)
		{
			edge->locked = 0;
			edge->same_edge->locked = 0;
			break ;
		}
		edge = edge->edge_next;
	}
}

void		initialize_before(t_lemin *lem)
{
	t_room	*room;

	room = lem->graph;
	while (room)
	{
		room->visited = 0;
		add_path(room, init_path(room));
		room = room->room_next;
	}
	lem->end->path->length = 0;
}


void		lock_all_pathes(t_edge *edge)
{
	while (edge)
	{
		edge->weight = -1;
	//	lock_path(edge->to,edge->out); // 0 2
		lock_path(edge->out, edge->to); // out to
		edge = edge->out->path->edge;
	}	
}


void		bhandari(t_lemin *le_min)
{
	t_edge	*edge;
	t_room	*room;

	search_path(le_min);
	lock_all_pathes(le_min->start->path->edge);
	initialize_before(le_min);
	bfs(le_min);

	while (le_min->end->visited)
	{
		search_path(le_min);
		lock_all_pathes(le_min->start->path->edge);
		initialize_before(le_min);
		bfs(le_min);
	}
	print_path(le_min);
}
