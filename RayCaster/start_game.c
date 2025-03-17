/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bouhammo <bouhammo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 16:38:12 by bouhammo          #+#    #+#             */
/*   Updated: 2025/03/17 16:48:50 by bouhammo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	key_press(void *param)
{
	t_start	*tmp_var;

	tmp_var = param;
	change_deriction(tmp_var);
	if ((mlx_is_key_down(tmp_var->mlx, MLX_KEY_W)
			|| mlx_is_key_down(tmp_var->mlx, MLX_KEY_UP)))
		move_player(tmp_var);
	if ((mlx_is_key_down(tmp_var->mlx, MLX_KEY_S)
			|| mlx_is_key_down(tmp_var->mlx, MLX_KEY_DOWN)))
		move_player(tmp_var);
	if (mlx_is_key_down(tmp_var->mlx, MLX_KEY_A))
		move_player(tmp_var);
	if (mlx_is_key_down(tmp_var->mlx, MLX_KEY_D))
		move_player(tmp_var);
	if (mlx_is_key_down(tmp_var->mlx, MLX_KEY_ESCAPE))
	{
		ft_game_free(tmp_var);
		exit(EXIT_SUCCESS);
	}
}

void	initialize_angle(t_start *var)
{
	double	angle;

	angle = 0;
	if (var->player == 'N')
		angle = 270;
	if (var->player == 'E')
		angle = 90;
	if (var->player == 'S')
		angle = 0;
	if (var->player == 'W')
		angle = 180;
	var->ray->ray_angle = normalize_angle(deg_to_rad(angle
				- (rad_to_deg(FOV_ANGLE))));
	var->draw->angle = normalize_angle(deg_to_rad(angle));
}

void	initialize_move_player(t_start *var)
{
	var->move = malloc(sizeof(t_move_player));
	var->draw = malloc(sizeof(t_draw_line));
	var->ray = malloc(sizeof(t_rays));
	var->inter = malloc(sizeof(t_position_intersec));
	var->wall = malloc((WINDOW_WIDTH + 1) * sizeof(t_build_walls));
	if (!var->move || !var->draw || !var->ray || !var->inter || !var->wall)
	{
		ft_game_free(var);
		ft_error("Error\n");
	}
	var->move->width_x = WINDOW_WIDTH;
	var->move->height_y = WINDOW_HEIGHT;
	var->move->coor_x = ((var->p_y * TILE_SIZE) + (TILE_SIZE / 2));
	var->move->coor_y = ((var->p_x * TILE_SIZE) + (TILE_SIZE / 2));
	initialize_angle(var);
}

void	ft_game_free(t_start *var)
{
	free(var->move);
	var->move = NULL;
	free(var->draw);
	var->draw = NULL;
	free(var->ray);
	var->ray = NULL;
	free(var->inter);
	var->inter = NULL;
	free(var->wall);
	var->wall = NULL;
	return ;
}

void	ft_start_game(t_start *var)
{
	var->offset = 5;
	var->player = var->map[var->p_x][var->p_y];
	initialize_move_player(var);
	var->mlx = mlx_init(WINDOW_WIDTH, WINDOW_HEIGHT, "CUB3D", false);
	ft_to_img(var);
	ft_convert_image(var);
	var->img = mlx_new_image(var->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (!var->img || mlx_image_to_window(var->mlx, var->img, 0, 0) < 0)
	{
		ft_game_free(var);
		ft_error("Error\n");
	}
	mlx_loop_hook(var->mlx, &key_press, var);
	mlx_loop(var->mlx);
	ft_game_free(var);
	mlx_terminate(var->mlx);
}
