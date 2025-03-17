/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_intersection.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bouhammo <bouhammo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 01:29:46 by bouhammo          #+#    #+#             */
/*   Updated: 2025/03/10 01:07:01 by bouhammo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int	check_direction_horizontal(double ray_angle)
{
	if (is_looking_down(ray_angle) == true)
		return (0);
	return (1);
}

int	check_direction_vertical(double ray_angle)
{
	if (is_looking_right(ray_angle) == true)
		return (0);
	return (1);
}

int	is_wall(t_start *var, double x, double y)
{
	int	map_x;
	int	map_y;

	map_x = (int)floor(x / TILE_SIZE);
	map_y = (int)floor(y / TILE_SIZE);
	if (map_y < 0 || map_x < 0 || map_y >= var->len_x
		|| map_x >= (int)ft_strlen(var->map[map_y]))
	{
		return (1);
	}
	if (map_y < 0 || map_x < 0 || map_y >= var->len_x
		|| map_x >= (int)ft_strlen(var->map[map_y]))
	{
		return (1);
	}
	if (var->map[map_y][map_x] == '1')
		return (1);
	return (0);
}

int	check_len_map_valid(t_start *var, double x_inter, double y_inter)
{
	int	map_x;
	int	map_y;

	map_x = (int)floor(x_inter / TILE_SIZE);
	map_y = (int)floor(y_inter / TILE_SIZE);
	if (map_y >= 0 || map_x >= 0 || map_y < var->len_x
		|| map_x < (int)ft_strlen(var->map[map_y]))
		return (1);
	if (var->map[map_y][map_x] == '1')
		return (0);
	return (1);
}

void	check_distance(t_start *var, double len_a, double len_b, int ray)
{
	if (len_a < len_b)
	{
		var->wall[ray].pos_x = var->ray->x_inter_horizontal;
		var->wall[ray].pos_y = var->ray->y_inter_horizontal;
		var->wall[ray].distance = len_a;
		var->wall[ray].direction = 'h';
	}
	else
	{
		var->wall[ray].pos_x = var->ray->x_inter_vertical;
		var->wall[ray].pos_y = var->ray->y_inter_vartical;
		var->wall[ray].distance = len_b;
		var->wall[ray].direction = 'v';
	}
	var->wall[ray].ray_angle = var->ray->ray_angle;
}
