/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-mora <rel-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 15:51:40 by rel-mora          #+#    #+#             */
/*   Updated: 2025/03/17 15:51:54 by rel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	free_double(char **array)
{
	int	i;

	i = 0;
	if (array == NULL)
	{
		return ;
	}
	while (array[i] != NULL)
	{
		free(array[i]);
		array[i] = NULL;
		i++;
	}
	free(array);
	array = NULL;
}

void	free_trim(t_data *to)
{
	if (to)
	{
		if (to->trim)
		{
			free(to->trim);
			to->trim = NULL;
		}
		if (to->sub)
		{
			free(to->sub);
			to->sub = NULL;
		}
		if (to->set)
		{
			free(to->set);
			to->set = NULL;
		}
		to = NULL;
	}
}

void	free_image_pxl(int **table, unsigned int height)
{
	unsigned int	i;

	i = 0;
	if (table)
	{
		while (i < height)
		{
			free(table[i]);
			table[i] = NULL;
			i++;
		}
		free(table);
	}
	table = NULL;
}

void	free_image(t_elements *config)
{
	if (config->pxl_image.west_pxl.west_pxl
		|| config->pxl_image.east_pxl.east_pxl
		|| config->pxl_image.north_pxl.north_pxl
		|| config->pxl_image.south_pxl.south_pxl)
	{
		free_image_pxl(config->pxl_image.west_pxl.west_pxl,
			config->pxl_image.west_pxl.height);
		free_image_pxl(config->pxl_image.east_pxl.east_pxl,
			config->pxl_image.east_pxl.height);
		free_image_pxl(config->pxl_image.north_pxl.north_pxl,
			config->pxl_image.north_pxl.height);
		free_image_pxl(config->pxl_image.south_pxl.south_pxl,
			config->pxl_image.south_pxl.height);
	}
	free_double(config->element);
}

void	free_start(t_start *var)
{
	if (var)
	{
		free_double(var->content);
		free_image(&(var->config));
		if (var->map)
			free_double(var->map);
		var = NULL;
	}
}
