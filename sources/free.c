/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlintill <rlintill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 12:45:23 by rlintill          #+#    #+#             */
/*   Updated: 2020/10/30 13:37:24 by rlintill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	free_arr(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	free_edge(t_edge **edge)
{
	(*edge)->next = NULL;
	(*edge)->prev = NULL;
	while ((*edge)->edge_next)
		free_edge(&((*edge)->edge_next));
	ft_memdel((void **)&(*edge));
}

void	free_graph(t_room **graph)
{
	ft_strdel(&((*graph)->name));
	ft_memdel((void **)&((*graph)->path));
	if ((*graph)->edge_next)
		free_edge(&((*graph)->edge_next));
	if ((*graph)->edge_prev)
		free_edge(&((*graph)->edge_prev));
	while ((*graph)->room_next)
		free_graph(&((*graph)->room_next));
	ft_memdel((void **)&(*graph));
}

void	free_lemin(t_lemin **lem)
{
	free_graph(&(*lem)->graph);
	free(*lem);
}
