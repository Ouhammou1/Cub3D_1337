/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bouhammo <bouhammo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 09:33:17 by rel-mora          #+#    #+#             */
/*   Updated: 2025/03/17 16:47:39 by bouhammo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ft_check_around(t_start *var, int i, int j)
{
	if (!var->map[i - 1] || !var->map[i + 1] || !var->map[i][j + 1]
		|| !var->map[i][j - 1])
	{
		free_double(var->cpy_map);
		ft_put_error("Error: invalid map\n", var, NULL);
	}
	else if (ft_strlen(var->map[i - 1]) <= (size_t)j 
		|| ft_strlen(var->map[i + 1]) <= (size_t)j)
	{
		free_double(var->cpy_map);
		ft_put_error("Error: invalid map\n", var, NULL);
	}
	else if (!var->map[i - 1] || (var->map[i - 1][j] == ' ' || var->map[i
			+ 1][j] == ' ' || var->map[i][j - 1] == ' ' || var->map[i][j
			+ 1] == ' '))
	{
		free_double(var->cpy_map);
		ft_put_error("Error: invalid map\n", var, NULL);
	}
}

void	ft_check_empty(t_start *var)
{
	int	i;
	int	j;

	i = 0;
	while (var->map[i])
	{
		j = 0;
		while (var->map[i][j])
		{
			if (var->map[i][j] == '0')
			{
				ft_check_around(var, i, j);
			}
			j++;
		}
		i++;
	}
}

void	ft_check_pos(t_start *var)
{
	ft_check_around(var, var->p_x, var->p_y);
	ft_check_empty(var);
}

void	check_general(t_start *var)
{
	t_data_2	idx;

	idx.i = 0;
	idx.j = 0;
	while (var->map[idx.i])
	{
		idx.j = 0;
		while (var->map[idx.i][idx.j])
		{
			if (var->map[idx.i][idx.j] == 'E' || var->map[idx.i][idx.j] == 'N'
				|| var->map[idx.i][idx.j] == 'W'
				|| var->map[idx.i][idx.j] == 'S')
			{
				var->p_x = idx.i;
				var->p_y = idx.j;
			}
			idx.j++;
		}
		idx.i++;
	}
	ft_check_pos(var);
}

void	fill_map(t_start *var)
{
	fill(var);
	verify_input(var);
	validate_start_position(var, var->map);
	if (ft_check_wall(var->map, var))
	{
		ft_putstr_fd("Error: the map must surrounded by wall", 2);
		exit(1);
	}
	check_general(var);
}
