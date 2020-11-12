/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_lem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlintill <rlintill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 12:45:23 by rlintill          #+#    #+#             */
/*   Updated: 2020/10/30 13:37:24 by rlintill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_lemin	*init_lem(void)
{
	t_lemin	*lem;

	if (!(lem = (t_lemin*)ft_memalloc(sizeof(t_lemin))))
		return (NULL);
	lem->ants = 0;
	lem->curr_ant = 1;
	lem->ants_on_road = 0;
	lem->rooms = 0;
	lem->start = NULL;
	lem->end = NULL;
	lem->graph = NULL;
	lem->bonus_print_path = false;
	lem->bonus_print_graph = false;
	lem->bonus_print_errors = false;
	lem->bonus_print_count_paths = false;
	lem->bonus_print_room_count = false;
	lem->bonus_print_count_ants = false;
	lem->bonus_print_line_count = false;
	return (lem);
}
