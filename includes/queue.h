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
	void				*node;
	struct s_node 		*next;
}						t_node;

typedef struct			s_queue
{
	t_node				*first;
	t_node				*last;
}						t_queue;

t_queue					*malloc_queue();
t_node					*malloc_queue_node(void *item);
void					queue_add_end(t_queue *queue, void *item);
void					*queue_del_top(t_queue *queue);

#endif
