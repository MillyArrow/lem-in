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

void	free_room(t_room **room)
{
	ft_strdel(&((*room)->name));
	while ((*room)->next)
		free_room(&((*room)->next));
	ft_memdel((void **)&(*room));
}

void	free_edge(t_edge **edge)
{
	if ((*edge)->room)
		free_room(&((*edge)->room));
	while ((*edge)->next)
		free_edge(&((*edge)->next));
	ft_memdel((void **)&(*edge));
}

void	free_lemin(t_lemin **lem)
{
	free_edge(&(*lem)->graph);
	free(*lem);
}
