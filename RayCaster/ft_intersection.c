/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intersection.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bouhammo <bouhammo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 21:58:25 by bouhammo          #+#    #+#             */
/*   Updated: 2025/03/10 00:59:17 by bouhammo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	get_horizontal_intersection(t_intersection *horiz, t_start *var,
		double ray_angle)
{
	horiz->a = 0;
	while (check_len_map_valid(var, horiz->x_inter, horiz->y_inter) == 1)
	{
		horiz->a = check_direction_horizontal(ray_angle);
		if (is_wall(var, horiz->x_inter, (horiz->y_inter - horiz->a)) == 1)
			break ;
		horiz->x_inter += horiz->x_step;
		horiz->y_inter += horiz->y_step;
	}
	if (var->ray != NULL)
	{
		var->ray->x_inter_horizontal = horiz->x_inter;
		var->ray->y_inter_horizontal = horiz->y_inter;
	}
}

void	find_horizontal_intersection(t_start *var, double ray_angle)
{
	t_intersection	horiz;

	horiz.x_inter = 0;
	horiz.y_inter = 0;
	horiz.x_step = 0;
	horiz.y_step = 0;
	horiz.y_inter = floor(var->move->coor_y / TILE_SIZE) * TILE_SIZE;
	if (is_looking_down(ray_angle) == true)
		horiz.y_inter += TILE_SIZE;
	horiz.x_inter = var->move->coor_x + (horiz.y_inter - var->move->coor_y)
		/ tan(ray_angle);
	horiz.y_step = TILE_SIZE;
	if (is_looking_down(ray_angle) == false)
		horiz.y_step *= -1;
	horiz.x_step = TILE_SIZE / tan(ray_angle);
	if ((is_looking_right(ray_angle) == false && horiz.x_step > 0)
		|| (is_looking_right(ray_angle) == true && horiz.x_step < 0))
		horiz.x_step *= -1;
	get_horizontal_intersection(&horiz, var, ray_angle);
}

void	get_vertical_intersection(t_intersection *vert, t_start *var,
		double ray_angle)
{
	vert->a = 0;
	while (check_len_map_valid(var, vert->x_inter, vert->y_inter) == 1)
	{
		vert->a = check_direction_vertical(ray_angle);
		if (is_wall(var, (vert->x_inter - vert->a), vert->y_inter) == 1)
			break ;
		vert->x_inter += vert->x_step;
		vert->y_inter += vert->y_step;
	}
	if (var->ray != NULL)
	{
		var->ray->x_inter_vertical = vert->x_inter;
		var->ray->y_inter_vartical = vert->y_inter;
	}
	return ;
}

void	find_vertical_intersection(t_start *var, double ray_angle)
{
	t_intersection	vert;

	vert.x_inter = 0;
	vert.y_inter = 0;
	vert.x_step = 0;
	vert.y_step = 0;
	vert.x_inter = floor(var->move->coor_x / TILE_SIZE) * TILE_SIZE;
	if (is_looking_right(ray_angle))
		vert.x_inter += TILE_SIZE;
	vert.y_inter = var->move->coor_y + (vert.x_inter - var->move->coor_x)
		* tan(ray_angle);
	vert.x_step = TILE_SIZE;
	if (!is_looking_right(ray_angle))
		vert.x_step *= -1;
	vert.y_step = TILE_SIZE * tan(ray_angle);
	if ((is_looking_down(ray_angle) == false && vert.y_step > 0)
		|| (is_looking_down(ray_angle) == true && vert.y_step < 0))
		vert.y_step *= -1;
	get_vertical_intersection(&vert, var, ray_angle);
	return ;
}

void	ft_intersection(t_start *var)
{
	int		ray;
	double	d_h;
	double	d_v;

	draw_floor_ceiling(var);
	var->ray->ray_angle = var->draw->angle - deg_to_rad(rad_to_deg(FOV_ANGLE)
			/ 2);
	var->ray->ray_angle = normalize_angle(var->ray->ray_angle);
	ray = 0;
	d_h = 0;
	d_v = 0;
	while (ray < WINDOW_WIDTH)
	{
		find_horizontal_intersection(var, var->ray->ray_angle);
		find_vertical_intersection(var, var->ray->ray_angle);
		d_h = sqrt(pow(var->move->coor_x - var->ray->x_inter_horizontal, 2)
				+ pow(var->move->coor_y - var->ray->y_inter_horizontal, 2));
		d_v = sqrt(pow(var->move->coor_x - var->ray->x_inter_vertical, 2)
				+ pow(var->move->coor_y - var->ray->y_inter_vartical, 2));
		check_distance(var, d_h, d_v, ray);
		build_walls(var, ray);
		var->ray->ray_angle += deg_to_rad(rad_to_deg(FOV_ANGLE) / WINDOW_WIDTH);
		var->ray->ray_angle = normalize_angle(var->ray->ray_angle);
		ray++;
	}
}
