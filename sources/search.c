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
** We search the graph whether there was a room with the same coordinates or name.
*/

int	search_same(t_lemin *lem, int x, int y, char *name)
{
	t_room	*r;

	r = lem->graph;
	while (r)
	{
		if (r->x == x && r->y == y)
			return (1);
		if (!ft_strcmp(name, r->name))
			return (1);
		r = r->room_next;
	}
	return (0);
}

/*
** We search whether the graph has two rooms to make edges between them.
*/

int	search_names(t_lemin *lem, char *one, char *two)
{
	t_room	*r;
	int		i;

	i = 0;
	r = lem->graph;
	while (r)
	{
		if (!ft_strcmp(one, r->name))
			i++;
		else if (!ft_strcmp(two, r->name))
			i++;
		if (i == 2)
			break ;
		r = r->room_next;
	}
	return (i);
}

