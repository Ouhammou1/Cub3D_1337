/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-mora <rel-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 00:51:50 by rel-mora          #+#    #+#             */
/*   Updated: 2025/03/17 15:52:06 by rel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	count_len_map(t_start *var)
{
	t_data_2	idx;

	var->len_x = 0;
	var->len_y = 0;
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
	var->len_x = idx.i;
	var->len_y = idx.j;
}

void	ft_ini_val(int *k, int *i)
{
	*k = 0;
	*i = 0;
}

int	ft_check_begin(char **map, t_start *var)
{
	int	j;

	count_len_map(var);
	j = 0;
	while (map[0][j])
	{
		if ((map[0][j] == '1' || map[0][j] == '\t' || map[0][j] == ' '))
			j++;
		else
			return (1);
	}
	return (0);
}

int	ft_check_wall(char **map, t_start *var)
{
	int	j;
	int	i;
	int	res;

	ft_ini_val(&i, &res);
	if (ft_check_begin(map, var))
		return (1);
	while (map[i])
	{
		res = ft_strlen(map[i]);
		if ((map[i][res - 1] != '1' && map[i][res - 1] != ' ' && map[i][res
				- 1] != '\t') || (map[i][0] != '1' && map[i][0] != ' '
				&& map[i][0] != '\t'))
			return (1);
		i++;
	}
	j = 0;
	while (map[i - 1][j])
	{
		if (map[i - 1][j] != '1' && map[i - 1][j] != ' ' && map[i
			- 1][j] != '\t')
			return (1);
		j++;
	}
	return (0);
}
