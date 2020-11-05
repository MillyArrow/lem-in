/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlintill <rlintill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 12:45:23 by rlintill          #+#    #+#             */
/*   Updated: 2020/10/13 13:37:24 by rlintill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUEUE_H
# define QUEUE_H

# include <stdlib.h>
# include "libft.h"

typedef struct			s_node
{
	void 				*room;
	struct s_node 		*next;
	struct s_node		*head;
	struct s_node		*tail;
}						t_node;



t_node					*malloc_node(void *item);
void					queue_add_end(t_node *node, void *item);
void					*queue_del_top(t_node *node);
int 					is_empty(t_node *queue);
t_node					*malloc_queue(void);
#endif
