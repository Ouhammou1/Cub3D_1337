/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-mora <rel-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 16:43:06 by rel-mora          #+#    #+#             */
/*   Updated: 2025/03/17 15:51:56 by rel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	get_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

void	ft_image_to_pxl(int ***table, uint8_t *pixels, unsigned int height,
		unsigned int width)
{
	unsigned int	i;
	unsigned int	j;
	int				t;

	t = 0;
	i = 0;
	*table = (int **)malloc((height * sizeof(int *)));
	while (i < height)
	{
		(*table)[i] = (int *)malloc(width * sizeof(int));
		j = 0;
		while (j < width)
		{
			(*table)[i][j] = get_rgba(pixels[t], pixels[t + 1], pixels[t + 2],
					pixels[t + 3]);
			t = t + 4;
			j++;
		}
		i++;
	}
}

void	ft_initialize_size_img(t_start *var)
{
	var->config.pxl_image.west_pxl.width = (int)var->config.west_g->width;
	var->config.pxl_image.west_pxl.height = (int)var->config.west_g->height;
	var->config.pxl_image.east_pxl.width = (int)var->config.east_g->width;
	var->config.pxl_image.east_pxl.height = (int)var->config.east_g->height;
	var->config.pxl_image.north_pxl.width = (int)var->config.north_g->width;
	var->config.pxl_image.north_pxl.height = (int)var->config.north_g->height;
	var->config.pxl_image.south_pxl.width = (int)var->config.south_g->width;
	var->config.pxl_image.south_pxl.height = (int)var->config.south_g->height;
}

void	ft_convert_image(t_start *var)
{
	ft_initialize_size_img(var);
	ft_image_to_pxl(&(var->config.pxl_image.west_pxl.west_pxl),
		var->config.west_g->pixels, var->config.west_g->height,
		var->config.west_g->width);
	ft_image_to_pxl(&var->config.pxl_image.east_pxl.east_pxl,
		var->config.east_g->pixels, var->config.east_g->height,
		var->config.east_g->width);
	ft_image_to_pxl(&var->config.pxl_image.north_pxl.north_pxl,
		var->config.north_g->pixels, var->config.north_g->height,
		var->config.north_g->width);
	ft_image_to_pxl(&var->config.pxl_image.south_pxl.south_pxl,
		var->config.south_g->pixels, var->config.south_g->height,
		var->config.south_g->width);
}

int	main(int ac, char **av)
{
	t_start	var;

	if (ac == 2)
	{
		ft_initialize(&var);
		ft_validate(av[1], &var);
		ft_start_game(&var);
	}
	else
		ft_put_error("Error: The argument is not valid\n", NULL, NULL);
	free_start(&var);
}
