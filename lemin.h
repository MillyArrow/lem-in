/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlintill <rlintill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 12:45:23 by rlintill          #+#    #+#             */
/*   Updated: 2020/10/07 13:37:24 by rlintill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include <stdlib.h>
# include "libft.h"
# include "queue.h"
# include "get_next_line.h"

// Compile with:
// gcc lemin.c parse.c room.c edge.c init_lem.c checking_edges.c checking_rooms.c free.c search.c error.c utils.c libft/libft.a -I libft/includes -I .

typedef struct		s_room
{
	char			*name;
	int				x;
	int				y;
	struct s_room	*next;
}					t_room;

typedef struct 		s_edge
{
	short			visited;
	t_room			*room;
	struct s_edge	*next;
}					t_edge;

typedef struct	s_lemin
{
	int			ants;
	int			rooms;
	t_room		*start;
	t_room		*end;
	t_edge		*graph;
}				t_lemin;


t_lemin *parse_lem(void);

/*
 * room.c
 */

t_room	*new_room(char *name);
void	add_new_room(t_lemin *lem, t_room *room, int flag);
void	add_room(t_edge *graph, t_room *new);

/*
 * edge.c
 */

void 	add_edge(t_edge *graph, char *src, char *dst);


/*
 * init_lem.c
 */

t_lemin	*init_lem(void);

/*
 * error.c
 */

void	error(void);

/*
 * free.c
 */

void free_arr(char **str);

/*
 * checking_rooms.c
 */

int check_line(char **line);
void check_input(t_lemin *lem, char **str);
void add_rooom(t_lemin *lem, int check, char *line);

/*
 * checking_edges.c
 */

int check_edge_line(char **line);
void adding_edges(t_lemin *lem, char *line);

/*
 * search.c
 */

int search_coord(t_lemin *lem, int x, int y);
int search_name(t_lemin *lem, char *room_name);

/*
 * utils.c 
 */

int check_number(char *str);

/*
 * To del
 */

void print_graph(t_edge *graph);

#endif
