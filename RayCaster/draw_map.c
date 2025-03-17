/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bouhammo <bouhammo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:40:33 by bouhammo          #+#    #+#             */
/*   Updated: 2025/03/15 01:39:30 by bouhammo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	print_in_wall(t_start *var, int x_map, int y_map)
{
	int	k;
	int	len;

	k = y_map;
	while (k < y_map + TILE_SIZE)
	{
		len = x_map;
		while (len < x_map + TILE_SIZE)
		{
			mlx_put_pixel(var->img, len, k, 0x000004FF);
			len++;
		}
		k++;
	}
}

void	print_in_space(t_start *var, int x_map, int y_map)
{
	int	k;
	int	len;

	k = y_map;
	while (k < y_map + TILE_SIZE)
	{
		len = x_map;
		while (len < x_map + TILE_SIZE)
		{
			mlx_put_pixel(var->img, len, k, 0x6A5AF);
			len++;
		}
		k++;
	}
}

void	print_pixel(t_start *var)
{
	t_start	*tmp;
	int		i;
	int		y_map;
	int		j;
	int		x_map;

	tmp = var;
	i = 0;
	y_map = 0;
	while (tmp->map[i])
	{
		x_map = 0;
		j = 0;
		while (tmp->map[i][j])
		{
			if (tmp->map[i][j] == '1')
				print_in_wall(tmp, x_map, y_map);
			if (tmp->map[i][j] == '0' || ft_caracter(tmp->map[i][j]) == 1)
				print_in_space(tmp, x_map, y_map);
			x_map += TILE_SIZE;
			j++;
		}
		y_map += TILE_SIZE;
		i++;
	}
}

void	print_pixel_player(t_start *var)
{
	int	x_map;
	int	y_map;
	int	y;
	int	x;

	if (!var || !var->img || !var->map)
		return ;
	x_map = var->move->coor_x;
	y_map = var->move->coor_y;
	y = y_map;
	while (y < y_map + var->offset)
	{
		x = x_map;
		while (x < x_map + var->offset)
		{
			mlx_put_pixel(var->img, x, y, 0xFFFF00FF);
			x++;
		}
		y++;
	}
}

void	ft_check_direction(t_start *var, int ray)
{
	if (var->wall[ray].direction == 'v' && cos(var->wall[ray].ray_angle) < 0)
	{
		var->wall[ray].w_e_n_s = 'e';
	}
	else if (var->wall[ray].direction == 'v'
		&& cos(var->wall[ray].ray_angle) >= 0)
	{
		var->wall[ray].w_e_n_s = 'w';
	}
	else if (var->wall[ray].direction == 'h'
		&& sin(var->wall[ray].ray_angle) < 0)
	{
		var->wall[ray].w_e_n_s = 's';
	}
	else if (var->wall[ray].direction == 'h'
		&& sin(var->wall[ray].ray_angle) >= 0)
	{
		var->wall[ray].w_e_n_s = 'n';
	}
}
