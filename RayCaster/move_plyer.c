/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_plyer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bouhammo <bouhammo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 19:31:31 by bouhammo          #+#    #+#             */
/*   Updated: 2025/03/10 00:51:41 by bouhammo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	ft_put_pixel_color(t_start *var, double x, double y, int color)
{
	if (x >= 0 && x < var->move->width_x && y >= 0 && y < var->move->height_y)
		mlx_put_pixel(var->img, x, y, color);
}

int	check_is_wall(t_start *var, double x, double y)
{
	int	x_m;
	int	y_m;
	int	tmp;

	tmp = -5;
	x_m = floor(x);
	y_m = floor(y);
	while (tmp < 5)
	{
		if (var->map[((y_m + tmp) / TILE_SIZE)][(x_m / TILE_SIZE)] == '1')
			return (0);
		tmp++;
	}
	tmp = -5;
	while (tmp < 5)
	{
		if (var->map[(y_m / TILE_SIZE)][((x_m + tmp) / TILE_SIZE)] == '1')
			return (0);
		tmp++;
	}
	return (1);
}

void	check_move_player(t_start *var, double rotated_x, double rotated_y)
{
	double	x;
	double	y;

	x = var->move->coor_x;
	y = var->move->coor_y;
	if (check_is_wall(var, (x + rotated_x), (y + rotated_y)) == 0)
		return ;
	var->move->coor_x += rotated_x;
	var->move->coor_y += rotated_y;
}

void	move_player(t_start *var)
{
	double	move_x;
	double	move_y;
	double	rotated_x;
	double	rotated_y;

	move_x = 0;
	move_y = 0;
	if (mlx_is_key_down(var->mlx, MLX_KEY_A))
		move_y -= PLAYER_SPEED;
	else if (mlx_is_key_down(var->mlx, MLX_KEY_D))
		move_y += PLAYER_SPEED;
	if (mlx_is_key_down(var->mlx, MLX_KEY_S) || mlx_is_key_down(var->mlx,
			MLX_KEY_DOWN))
		move_x -= PLAYER_SPEED;
	else if (mlx_is_key_down(var->mlx, MLX_KEY_W) || mlx_is_key_down(var->mlx,
			MLX_KEY_UP))
		move_x += PLAYER_SPEED;
	rotated_x = (move_x * cos(var->draw->angle)) - (move_y
			* sin(var->draw->angle));
	rotated_y = (move_x * sin(var->draw->angle)) + (move_y
			* cos(var->draw->angle));
	check_move_player(var, rotated_x, rotated_y);
	ft_intersection(var);
}

void	change_deriction(t_start *var)
{
	if (mlx_is_key_down(var->mlx, MLX_KEY_RIGHT))
	{
		var->draw->angle += ROTATION_SPEED;
	}
	else if (mlx_is_key_down(var->mlx, MLX_KEY_LEFT))
	{
		var->draw->angle -= ROTATION_SPEED;
	}
	var->draw->angle = normalize_angle(var->draw->angle);
	ft_intersection(var);
}
