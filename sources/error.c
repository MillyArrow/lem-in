/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrow <marrow@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 12:45:23 by rlintill          #+#    #+#             */
/*   Updated: 2020/11/12 10:01:04 by marrow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	error_w_del(char **line, char *err, t_lemin *lem)
{
	ft_strdel(line);
	if (lem->bonus_print_errors)
		ft_printf("{red}%s{eoc}\n", err);
	write(2, "ERROR\n", 6);
	exit(0);
}

void	error(char *err, t_lemin *lem)
{
	if (lem->bonus_print_errors)
		ft_printf("{red}%s{eoc}\n", err);
	write(2, "ERROR\n", 6);
	exit(0);
}
