/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_texture.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bouhammo <bouhammo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 01:43:37 by rel-mora          #+#    #+#             */
/*   Updated: 2025/03/17 16:47:24 by bouhammo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

uint32_t	ft_put_east_texture(t_start *var, t_info_texture info)
{
	uint32_t	texture_y;

	texture_y = ft_get_texture_y(info.y, info.top_const, info.buttom_const,
			var->config.east_g->height);
	if (info.texture_x >= var->config.east_g->width)
		info.texture_x = info.texture_x - var->config.east_g->height;
	if (texture_y >= var->config.east_g->height)
		texture_y = var->config.east_g->height - 1;
	if (info.texture_x >= var->config.east_g->width)
		info.texture_x = var->config.east_g->width - 1;
	return (var->config.pxl_image.east_pxl.east_pxl[texture_y][info.texture_x]);
}

uint32_t	ft_put_west_texture(t_start *var, t_info_texture info)
{
	uint32_t	texture_y;

	texture_y = ft_get_texture_y(info.y, info.top_const, info.buttom_const,
			var->config.west_g->height);
	if (info.texture_x >= var->config.west_g->width)
		info.texture_x = info.texture_x - var->config.west_g->height;
	if (texture_y >= var->config.west_g->height)
		texture_y = var->config.west_g->height - 1;
	if (info.texture_x >= var->config.west_g->width)
		info.texture_x = var->config.west_g->width - 1;
	return (var->config.pxl_image.west_pxl.west_pxl[texture_y][info.texture_x]);
}

uint32_t	ft_put_south_texture(t_start *var, t_info_texture info)
{
	uint32_t	texture_y;
	uint32_t	pixel;

	texture_y = ft_get_texture_y(info.y, info.top_const, info.buttom_const,
			var->config.south_g->height);
	if (info.texture_x >= var->config.south_g->width)
		info.texture_x = info.texture_x - var->config.south_g->height;
	if (texture_y >= var->config.south_g->height)
		texture_y = var->config.south_g->height - 1;
	if (info.texture_x >= var->config.south_g->width)
		info.texture_x = var->config.south_g->width - 1;
	pixel = var->config.pxl_image.south_pxl
		.south_pxl[texture_y][info.texture_x];
	return (pixel);
}

uint32_t	ft_put_north_texture(t_start *var, t_info_texture info)
{
	uint32_t	texture_y;
	uint32_t	pixel;

	texture_y = ft_get_texture_y(info.y, info.top_const, info.buttom_const,
			var->config.north_g->height);
	if (info.texture_x >= var->config.north_g->width)
		info.texture_x = info.texture_x - var->config.north_g->height;
	if (texture_y >= var->config.north_g->height)
		texture_y = var->config.north_g->height - 1;
	if (info.texture_x >= var->config.north_g->width)
		info.texture_x = var->config.north_g->width - 1;
	pixel = var->config.pxl_image.north_pxl
		.north_pxl[texture_y][info.texture_x];
	return (pixel);
}

uint32_t	ft_put_texture(t_start *var, int ray, t_info_texture info)
{
	if (var->wall[ray].w_e_n_s == 'e')
		return (ft_put_east_texture(var, info));
	else if (var->wall[ray].w_e_n_s == 'w')
		return (ft_put_west_texture(var, info));
	else if (var->wall[ray].w_e_n_s == 's')
		return (ft_put_south_texture(var, info));
	else if (var->wall[ray].w_e_n_s == 'n')
		return (ft_put_north_texture(var, info));
	return (0);
}
