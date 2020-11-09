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

void		initialize_before(t_lemin *lem)
{
	t_room	*room;

	room = lem->graph;
	while (room)
	{
		room->visited = 0;
		add_path_room(room, init_path(room));
		room = room->room_next;
	}
	lem->end->path->length = 0;
}


void		lock_all_pathes(t_edge *edge)
{
	while (edge)
	{
		edge->weight = -1;
		lock_path(edge->out, edge->to); // out to
		edge = edge->out->path->edge;
	}	
}

void delete_links(t_lemin *lem)
{
	t_path *pointer;
	t_path *path;
	t_path *temp_path;
	t_path *temp;

	path = 	lem->start->path->next_path_in_room;
	while (path)
	{
		pointer = path->path_next;
		while (pointer->belongs_to != lem->end)
		{
			temp = NULL;
			if (pointer->edge->locked == 1 && pointer->edge->oppos_edge->locked == 1)
			{
				temp = pointer->path_next;
				temp_path = pointer->edge->oppos_edge->belongs_to_path->path_next;
				pointer->edge->locked = 0;
				pointer->edge->same_edge->locked = 0;

				pointer->path_prev->path_next = temp_path;
				pointer->path_prev->edge->same_edge->belongs_to_path->path_next = temp_path;
				pointer->edge->oppos_edge->belongs_to_path->path_next->path_prev = pointer->path_prev;

				pointer->edge->oppos_edge->belongs_to_path->path_prev->path_next = temp;
				pointer->edge->oppos_edge->same_edge->belongs_to_path->path_prev->path_next = temp;
				temp->path_prev = pointer->edge->oppos_edge->belongs_to_path->path_prev;
			}
			if (temp != NULL)
				pointer = temp;
			else
				pointer = pointer->path_next;
		}
		path = path->next_path_in_room;
	}
}

int count_length(t_path *path)
{
	int 	count;
	t_path	*p;

	count = 1;
	p = path->path_next;
	while (p)
	{
		if (p->length == 0 || p->edge == NULL)
			break ;
		count += 1;
		p = p->path_next;
	}
	return (count);
}

void recount(t_path *paths)
{
	t_path *path;

	path = paths->next_path_in_room;
	while (path)
	{
		path->length = count_length(path) + 1;
		path = path->next_path_in_room;
	}
}

void		bhandari(t_lemin *le_min)
{
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
	print_path(le_min); // to delete
	delete_links(le_min);
	recount(le_min->start->path);
	merge_sort(&(le_min->start->path->next_path_in_room));
	print_path(le_min); // to delete
}
