#include "lemin.h"

/*Это мини-алгоритм, который помогает выбрать путь для каждого муравья.

Чтобы принять решение, мы должны знать, сколько муравьев осталось в начале,
и сумму разностей между длиной текущего пути и длиной более коротких путей.
 На каждом шаге мы будем перебирать пути по их длине в порядке
 возрастания и принимать решение - двигать муравья по этому пути или нет.*/

int 			best_way(int ants, t_path *path, t_path *start_path)
{
	int			best_length;

	best_length = 0;
	while (path != start_path)
	{
		if (start_path)
			best_length += path->length - start_path->next_path_in_room->length;
		start_path = start_path->next_path_in_room;
	}
	if (ants > best_length)
		return (TRUE);
	else
		return (FALSE);
}

void 			move_for_start(t_lemin *le_min, t_path *path)
{
	int			curr_ant;
	char		*room_name;
	t_room 		*curr_room;

	curr_ant = le_min->curr_ant;
	curr_room = path->path_next->belongs_to;
	room_name = curr_room->name;
	if (curr_room != le_min->end)
	{
		curr_room->occupied = TRUE;
		curr_room->ant = curr_ant;
		++le_min->ants_on_road;
	}
	++le_min->curr_ant;
	--le_min->ants;
	ft_printf("L%d-%s ", curr_ant, room_name);
}

void			move_ant_from_start(t_lemin *le_min, t_queue *free_rooms)
{
	t_path		*paths;

	paths = le_min->start->path->next_path_in_room;
	while (paths && le_min->ants)
	{
		if (best_way(le_min->ants, paths, le_min->start->path) && !paths->edge->out->occupied)
		{
			queue_add_end(free_rooms, paths->path_next->belongs_to\
			->path->next_path_in_room->path_next->belongs_to);
			move_for_start(le_min, paths);
		}
		paths = paths->next_path_in_room;
	}
}

//CHECK HERE
//
t_queue 			*get_free_rooms(t_node *node)
{
	t_queue *free_rooms;
	t_room	*room;

	if (!(free_rooms = malloc_queue()))
		return (NULL);
	while(node)
	{
		room = node->room;
		if (room->path->next_path_in_room->path_next)
			queue_add_end(free_rooms, room->path->next_path_in_room->path_next->belongs_to);
		node = node->next;
	}
	return (free_rooms);
}

/*void			move_ant_on_road(t_lemin *le_min, t_queue **free_rooms)
{
	t_node		*node;
	t_room 		*curr_room;
	t_room 		*prev_room;
	t_queue		*tmp_que;

	node = (*free_rooms)->head;
	tmp_que = get_free_rooms(node);
	while(node)
	{
		curr_room = node->room;
		prev_room = curr_room->path->next_path_in_room->path_prev->belongs_to;
		if (prev_room == le_min->end)
		{
			node = node->next;
			continue ;
		}
		prev_room->occupied = true;
		if (curr_room == le_min->end)
			--le_min->ants_on_road;
		while(prev_room)
		{
			if (prev_room->occupied || curr_room == le_min->end)
			{
				curr_room->ant = prev_room->ant;
				curr_room->occupied = true;
				prev_room->occupied = false;
				ft_printf("L%d-%s ", curr_room->ant, curr_room->name);
				curr_room = prev_room;
			}
			if (prev_room->path->next_path_in_room->path_prev->belongs_to)
				prev_room = prev_room->path->next_path_in_room->path_prev->belongs_to;
			else
				break ;
			if (prev_room == le_min->start)
				break ;
		}
		node = node->next;
	}
	*free_rooms = tmp_que;
}*/

void 			move_ant_on_road(t_lemin *le_min)
{
	t_path		*path;
	t_room		*curr_room;
	t_room		*prev_room;
	t_room		*end_room;

	path = le_min->end->path->next_path_in_room;
	end_room = le_min->end;
	while(path)
	{
		curr_room = path->path_prev->belongs_to;
		if (curr_room->ant != 0)
		{
			end_room->ant = curr_room->ant;
			--le_min->ants_on_road;
			ft_printf("L%d-%s ", end_room->ant, end_room->name);
		}
		while(curr_room != le_min->start)
		{
			if (curr_room->path->next_path_in_room->path_prev)
				prev_room = curr_room->path->next_path_in_room->path_prev->belongs_to;
			else
				break ;
			curr_room->ant = prev_room->ant;
			if (curr_room->ant != 0)
				ft_printf("L%d-%s ", curr_room->ant, curr_room->name);
			curr_room = prev_room;
		}
		path = path->next_path_in_room;
	}
}

void 			room_cleaning(t_lemin *le_min)
{
	t_room		*room;

	room = le_min->graph;
	while (room)
	{
		room->occupied = FALSE;
		room = room->room_next;
	}
}

void			solver(t_lemin *le_min)
{
	t_queue		*free_rooms;

	//Здесь моет быть утечка если память под очередь не выделится
	if (!(free_rooms = malloc_queue()))
		return ;
	bhandari(le_min);
	int count = 1;
	int a = 10;
	while(le_min->ants || le_min->ants_on_road && a--)
	{
		ft_printf("--------%d--------\n", count++);
		if (count == 4)
			1;
		room_cleaning(le_min);
		if (le_min->ants_on_road)
			move_ant_on_road(le_min);
		move_ant_from_start(le_min, free_rooms);
		ft_printf("\n");
	}
}