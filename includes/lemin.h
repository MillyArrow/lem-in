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
# include "queue.h"

typedef struct		s_room
{
	short			visited;
	char			*name;
	int				x;
	int				y;
	struct s_path	*path;
	struct s_edge  	*edge_next;
	struct s_edge	*edge_prev;
	struct s_room	*room_next;
}					t_room;

typedef struct		s_edge
{
	int				id;
	int				locked;
	int				weight;
	t_room			*next;
	t_room			*prev;
	struct s_edge	*edge_next;
}					t_edge;

typedef struct		s_path
{
	int				length;
	t_edge			*edge;
	struct s_path	*next_path;
}					t_path;

typedef struct		s_lemin
{
	int				ants;
	int				rooms;
	int				edges;
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
t_edge				*new_edge(t_room *src, t_room *dst, int id);

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

int					search_coord(t_lemin *lem, int x, int y);
int					search_name(t_lemin *lem, char *room_name);

/*
** utils.c
*/

int					check_number(char *str);

/*
**	path.c
*/

t_path				*init_path(void);
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
#endif
