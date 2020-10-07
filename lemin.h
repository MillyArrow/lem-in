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

typedef struct		s_room
{
	char			*name;
	struct s_room	*next;
}					t_room;

typedef struct 		s_graph
{
	t_room			*room;
	struct s_graph	*next;
}					t_graph;

typedef struct	s_lemin
{
	unsigned	ants;
	unsigned	rooms;
	t_room		*start;
	t_room		*end;
	t_graph		*graph;
}				t_lemin;

#endif
