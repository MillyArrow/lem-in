/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_queue.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrow <marrow@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 12:45:23 by rlintill          #+#    #+#             */
/*   Updated: 2020/11/11 05:04:22 by marrow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"

static void			free_node(t_node **node)
{
	(*node)->room = NULL;
	while ((*node)->next)
		free_node(&((*node)->next));
	ft_memdel((void**)&(*node));
}

void				free_queue(t_queue **queue)
{
	if ((*queue)->head)
		free_node(&((*queue)->head));
	(*queue)->tail = NULL;
	ft_memdel((void**)&(*queue));
}
