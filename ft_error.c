/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-mora <rel-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 15:51:14 by rel-mora          #+#    #+#             */
/*   Updated: 2025/03/17 15:51:31 by rel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ft_put_error(char *s, t_start *var, t_data *to)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(s, 2);
	if (var)
		free_start(var);
	if (to)
		free_trim(to);
	exit(1);
}

void	ft_just_print_error(char *s)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(s, 2);
	exit(1);
}

void	ft_free_when_exit(char *s, t_start *var, t_data *to, t_data_2 *d)
{
	if (s)
		ft_put_error(s, var, to);
	free(d->native);
	free_double(d->split_sub);
}
