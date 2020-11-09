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
# include "ft_printf.h"
# include "libft.h"
# include <stdbool.h>
# include "queue.h"

typedef struct		s_room
{
	bool			occupied;
	char			*name;
	short			visited;
	int				x;
	int				y;
	int 			ant;
	struct s_path	*path;
	struct s_edge  	*edge_next;
	struct s_edge	*edge_prev;
	struct s_room	*room_next;
}					t_room;

typedef struct		s_edge
{
	bool			locked;
	int				weight;
	t_room			*to;
	t_room			*out;
	struct s_edge	*oppos_edge;
	struct s_edge	*same_edge;
	struct s_edge	*edge_next;
}					t_edge;

typedef struct		s_path
{
	int				length;
	t_edge			*edge;
	t_room			*belongs_to;
	struct s_path	*path;
	struct s_path	*next_path;
}					t_path;

typedef struct		s_lemin
{
	int				ants;
	int 			curr_ant;
	int 			ants_on_road;
	int				rooms;
	t_room			*start;
	t_room			*end;
	t_room			*graph;
}					t_lemin;

t_lemin				*parse_lem(void);

/*
** room.c
*/

t_room				*new_room(char *name, char *x, char *y);
void				add_new_room(t_lemin *lem, t_room *room, int flag);

/*
** edge.c
*/

void				add_edge(t_lemin *lem, char *one, char *two);
t_edge				*new_edge(t_room *src, t_room *dst);

/*
** init_lem.c
*/

t_lemin				*init_lem(void);

/*
** error.c
*/

void				error(void);
void				error_w_del(char **line);

/*
** free.c
*/

void				free_arr(char **str);
void				free_lemin(t_lemin **lem);

/*
** checking_rooms.c
*/

int					check_line(char **line);
void				check_input(t_lemin *lem, char **str);
void				add_rooom(t_lemin *lem, int check, char *line);

/*
** checking_edges.c
*/

int					check_edge_line(char **line);
void				adding_edges(t_lemin *lem, char *line);

/*
** search.c
*/

int					search_same(t_lemin *lem, int x, int y, char *name);
int					search_names(t_lemin *lem, char *one, char *two);

/*
** utils.c
*/

int					check_number(char *str);

/*
**	path.c
*/

t_path				*init_path(t_room *room);
void				add_path(t_room *room, t_path *new);
void				search_path(t_lemin *lem);
void				print_path(t_lemin *lem);

/*
** To del
*/

void				print_graph(t_room *graph);

/*
 * BFS
 */

void					bfs(t_lemin *lem_in);

void					bhandari(t_lemin *le_min);
void					solver(t_lemin *le_min);
#endif
