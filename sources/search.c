/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlintill <rlintill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 12:45:23 by rlintill          #+#    #+#             */
/*   Updated: 2020/10/30 13:37:24 by rlintill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

/*
** We search the graph whether there was a room with the same coordinates.
*/

int	search_coord(t_lemin *lem, int x, int y)
{
	t_room	*r;

	r = lem->graph;
	while (r)
	{
		if (r->x == x && r->y == y)
			return (1);
		r = r->room_next;
	}
	return (0);
}

/*
** We search the graph whether there was a room with the same name.
*/

int	search_name(t_lemin *lem, char *room_name)
{
	t_room	*r;

	r = lem->graph;
	while (r)
	{
		if (!ft_strcmp(room_name, r->name))
			return (1);
		r = r->room_next;
	}
	return (0);
}
