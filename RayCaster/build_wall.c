/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_wall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bouhammo <bouhammo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 17:34:00 by bouhammo          #+#    #+#             */
/*   Updated: 2025/03/17 17:04:20 by bouhammo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	draw_ceil(t_start *var)
{
	int	i;
	int	j;

	i = 0;
	while (i < var->move->height_y / 2)
	{
		j = 0;
		while (j < var->move->width_x)
		{
			ft_put_pixel_color(var, j, i, get_rgba(var->config.ceiling[0],
					var->config.ceiling[1], var->config.ceiling[2], 100));
			j++;
		}
		i++;
	}
}

void	draw_floor_ceiling(t_start *var)
{
	int	i;
	int	j;

	draw_ceil(var);
	i = var->move->height_y / 2;
	while (i < var->move->height_y)
	{
		j = 0;
		while (j < var->move->width_x)
		{
			ft_put_pixel_color(var, j, i, get_rgba(var->config.floor[0],
					var->config.floor[1], var->config.floor[2], 150));
			j++;
		}
		i++;
	}
}

int	get_bottom_p(t_start *var, int line)
{
	int	get_b_pxl;

	get_b_pxl = (var->move->height_y / 2) + (line / 2);
	if (get_b_pxl > var->move->height_y)
		get_b_pxl = var->move->height_y;
	return (get_b_pxl);
}

int	get_top_p(t_start *var, int line)
{
	int	get_tp_pxl;

	get_tp_pxl = (var->move->height_y / 2) - (line / 2);
	if (get_tp_pxl > var->move->height_y)
		get_tp_pxl = var->move->height_y;
	return (get_tp_pxl);
}

void	build_walls(t_start *var, int ray)
{
	double			distance;
	double			dis_projection_plan;
	double			get_top;
	t_info_texture	info;

	distance = var->wall[ray].distance * cos(var->ray->ray_angle
			- var->draw->angle);
	dis_projection_plan = ((var->move->width_x / 2.0) / (tan(FOV_ANGLE / 2.0)));
	info.line = (TILE_SIZE / distance) * dis_projection_plan;
	get_top = (int)info.line;
	ft_check_direction(var, ray);
	info.y = get_top_p(var, get_top);
	info.get_buttom = get_bottom_p(var, info.line);
	info.top_const = info.y;
	if (info.y < 0)
		info.y = 0;
	info.buttom_const = (var->move->height_y / 2) + (info.line / 2);
	info.texture_x = ft_calc_pos_pxl(var, ray);
	while (info.y < info.get_buttom)
	{
		ft_put_pixel_color(var, ray, info.y, ft_put_texture(var, ray, info));
		info.y++;
	}
}
