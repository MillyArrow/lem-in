/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlintill <rlintill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 12:45:23 by rlintill          #+#    #+#             */
/*   Updated: 2020/10/07 13:37:24 by rlintill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		main(int argc, char **argv)
{
	t_lemin	*lem;

	if (!(lem = init_lem()))
		exit(0);
	if (argc > 1)
		bonus(argv, lem);
	parse_lem(lem);
	bfs(lem);
	if (!(lem->end->visited))
		error("{red}path to end not exist{eoc}\n", lem);
	solver(lem);
	free_lemin(&lem);
//	while(1){}
	return (0);
}
