#include "lemin.h"

/*Это мини-алгоритм, который помогает выбрать путь для каждого муравья.

Чтобы принять решение, мы должны знать, сколько муравьев осталось в начале,
и сумму разностей между длиной текущего пути и длиной более коротких путей.
 На каждом шаге мы будем перебирать пути по их длине в порядке
 возрастания и принимать решение - двигать муравья по этому пути или нет.*/

int 			best_way(int ants, t_path *path)
{
	int			best_length;

	best_length = 0;
	while (path)
	{
		if (path->next_path)
			best_length += path->length - path->next_path->length;
		path = path->next_path;
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
	room_name = path->edge->out->name;
	curr_room = path->edge->out;
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

	paths = le_min->start->path->next_path;
	while (paths && le_min->ants)
	{
		if (best_way(le_min->ants, paths) && !paths->edge->out->occupied)
		{
			queue_add_end(free_rooms, paths->path->edge->to);
			move_for_start(le_min, paths);
		}
		paths = paths->next_path;
	}
}

void			move_ant_on_road(t_lemin *le_min, t_queue *free_rooms)
{
	t_node		*node;
	t_room 		*curr_room;
	t_room 		*prev_room;

	node = free_rooms->head;
	while(node)
	{
		prev_room = node->room;
		curr_room = prev_room->path->next_path->edge->out;
		if (curr_room == le_min->end)
			--le_min->ants_on_road;
		while(prev_room)
		{
			curr_room->ant = prev_room->ant;
			ft_printf("L%d-%s ", curr_room->ant, curr_room->name);
			curr_room = prev_room;
			if (prev_room->path->next_path->edge->edge_next)
				prev_room = prev_room->path->next_path->edge->edge_next->out;
			else
				break ;
			if (prev_room == le_min->start)
				break ;
		}
		node = node->next;
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
	//while(le_min->ants || le_min->ants_on_road)
	room_cleaning(le_min);
	move_ant_from_start(le_min, free_rooms);
	ft_printf("\n");
	move_ant_on_road(le_min, free_rooms);
	ft_printf("\n");
}