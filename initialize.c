/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-mora <rel-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 15:00:06 by rel-mora          #+#    #+#             */
/*   Updated: 2025/03/17 15:52:47 by rel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ft_initialize(t_start *var)
{
	ft_memset(&var->config, 0, sizeof(t_elements));
	var->mlx = NULL;
	var->content = NULL;
	var->map = NULL;
	var->cpy_map = NULL;
	var->img = NULL;
	var->move = NULL;
	var->draw = NULL;
	var->ray = NULL;
	var->wall = NULL;
	var->inter = NULL;
	var->x = 0;
	var->y = 0;
	var->len_x = 0;
	var->len_y = 0;
	var->p_x = 0;
	var->p_y = 0;
	var->offset = 0;
	var->len_map = 0;
	var->player = '\0';
	var->flag_up = false;
	var->flag_down = false;
}
