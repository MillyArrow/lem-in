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
		lock_path(edge->out, edge->to); // out to
		edge = edge->out->path->edge;
	}	
}

void change_paths(t_room *search_in, t_room *out, t_path **temp)
{
	t_path *path;
	t_path *tmp;

	path = search_in->path;
	while (path && path->edge == NULL)
		path = search_in->path->next_path;
	while (path)
	{
		if (path->edge->out == out)
		{
			tmp = path->path->path;
			path->edge->locked = 0;
			path->path = *temp;
			*temp = tmp;
			break ;
		}
		path = path->next_path;
	}
}

void delete_links(t_lemin *lem)
{
	t_path *pointer;
	t_path *path;
	t_room *room;
	t_edge *edge;
	t_path *temp;

	path = 	lem->start->path->next_path;
	while (path)
	{
		pointer = path->path;
		room = pointer->belongs_to;
		while (room != lem->end)
		{
			edge = pointer->edge;
			if (edge->locked == 1 && edge->oppos_edge->locked == 1)
			{
				temp = pointer->path->path;
				change_paths(pointer->edge->out, pointer->edge->to, &temp);
				pointer->path =temp;
			}
			pointer = pointer->path;
			room = pointer->belongs_to;
		}
		path = path->next_path;
	}
}

int count_length(t_path *path)
{
	int 	count;
	t_path *p;

	count = 1;
	p = path->path;
	while (p)
	{
		if (p->length == 0)
			break ;
		count += 1;
		p = p->path;
	}
	return (count);
}

void recount(t_path *paths)
{
	t_path *path;

	path = paths->next_path;
	while (path)
	{
		path->length = count_length(path) + 1;
		path = path->next_path;
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
	print_path(le_min); // to delete
}
