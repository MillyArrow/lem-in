#ifndef LEMIN_H
# define LEMIN_H

typedef struct	s_room
{
	char		*name;
	t_room		*next;
}				t_room;

typedef struct	s_lemin
{
	unsigned	ants;
	t_room		*start;
	t_room		*end;
	unsigned	rooms;
	t_room		**roomList;
}				t_lemin;

#endif
