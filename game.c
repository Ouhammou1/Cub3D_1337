/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-mora <rel-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:37:44 by rel-mora          #+#    #+#             */
/*   Updated: 2025/03/17 15:52:36 by rel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ft_to_img(t_start *var)
{
	var->config.north_g = mlx_texture_to_image(var->mlx, var->config.north_t);
	var->config.east_g = mlx_texture_to_image(var->mlx, var->config.east_t);
	var->config.south_g = mlx_texture_to_image(var->mlx, var->config.south_t);
	var->config.west_g = mlx_texture_to_image(var->mlx, var->config.west_t);
	mlx_delete_texture(var->config.east_t);
	mlx_delete_texture(var->config.north_t);
	mlx_delete_texture(var->config.south_t);
	mlx_delete_texture(var->config.west_t);
}

uint32_t	ft_calc_pos_pxl(t_start *var, int ray)
{
	double		hit_pos;
	uint32_t	texture_x;

	if (var->wall[ray].direction == 'v')
		hit_pos = var->wall[ray].pos_y / TILE_SIZE;
	else
		hit_pos = var->wall[ray].pos_x / TILE_SIZE;
	if (var->wall->w_e_n_s == 'e')
		texture_x = ((hit_pos - floor(hit_pos)) * var->config.east_g->width);
	else if (var->wall->w_e_n_s == 'w')
		texture_x = ((hit_pos - floor(hit_pos)) * var->config.west_g->width);
	else if (var->wall->w_e_n_s == 's')
		texture_x = ((hit_pos - floor(hit_pos)) * var->config.south_g->width);
	else
		texture_x = ((hit_pos - floor(hit_pos)) * var->config.north_g->width);
	return (texture_x);
}

uint32_t	ft_get_texture_y(int y, double top_const, double buttom_const,
		int texture_height)
{
	uint32_t	txt;

	txt = (y - top_const) / (buttom_const - top_const) * texture_height;
	return (txt);
}
