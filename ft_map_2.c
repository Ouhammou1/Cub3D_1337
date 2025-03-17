/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-mora <rel-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 00:56:25 by rel-mora          #+#    #+#             */
/*   Updated: 2025/03/17 15:52:08 by rel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	fill(t_start *var)
{
	int	i;
	int	j;

	i = 6;
	j = 0;
	while (var->content[i])
	{
		i++;
		j++;
	}
	var->map = malloc((j + 1) * sizeof(char *));
	i = 6;
	j = 0;
	while (var->content[i])
	{
		var->map[j] = ft_strdup(var->content[i]);
		i++;
		j++;
	}
	var->map[j] = NULL;
}

void	ft_check_least(char **map, char c, int *count)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == c)
				(*count)++;
			j++;
		}
		i++;
	}
}

void	validate_start_position(t_start *var, char **map)
{
	int	count;

	count = 0;
	ft_check_least(map, 'N', &count);
	ft_check_least(map, 'E', &count);
	ft_check_least(map, 'S', &count);
	ft_check_least(map, 'W', &count);
	if (count != 1)
		ft_put_error("invalide player position\n", var, NULL);
}

void	verify_input(t_start *var)
{
	int	i;
	int	j;

	i = 0;
	while (var->map[i] != NULL)
	{
		j = 0;
		while (var->map[i][j])
		{
			if ((var->map[i][j] != '0' && var->map[i][j] != '1')
				&& var->map[i][j] != ' ' && (var->map[i][j] != 'N'
					&& var->map[i][j] != 'S' && var->map[i][j] != 'W'
					&& var->map[i][j] != 'E'))
				ft_put_error("invalid character", var, NULL);
			j++;
		}
		i++;
	}
}

int	ft_search(char *s, char *d)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 0;
	len = ft_strlen(s);
	while (s[i] && s[i])
	{
		if (s[i] == d[j])
			j++;
		if (len == j && s[i + 1] == d[j])
			return (1);
		i++;
	}
	return (0);
}
