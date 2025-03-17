/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rgb_cnfg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-mora <rel-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 18:28:05 by rel-mora          #+#    #+#             */
/*   Updated: 2025/03/17 15:52:11 by rel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ft_check_rgb(t_start *var, t_elements *ele)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (!(ele->floor[i] >= 0 && ele->floor[i] <= 255))
		{
			ft_put_error("Error: RGB values must be between 0 and 255.\n", var,
				NULL);
		}
		if (!(ele->ceiling[i] >= 0 && ele->ceiling[i] <= 255))
		{
			ft_put_error("Error: RGB values must be between 0 and 255.\n", var,
				NULL);
		}
		i++;
	}
}

void	ft_three_rgb(t_start *var, t_data *to, t_data_2 *d)
{
	int	i;
	int	k;

	d->k = 0;
	d->i = 0;
	i = 0;
	k = 0;
	while (to->set[i])
	{
		if (to->set[i] == ',')
			k++;
		i++;
	}
	if (k != 2)
		ft_put_error("Error: RGB not work like that.", var, to);
}

int	ft_check_element(char **sub, t_data_2 *d)
{
	char	*trim;

	trim = ft_strtrim(sub[d->i], " \t");
	while (trim[d->j] != '\0')
	{
		if (!ft_isdigit(trim[d->j]))
		{
			free(trim);
			return (1);
		}
		d->j++;
	}
	free(trim);
	return (0);
}

void	ft_set_rgb(t_start *var, t_data *to, char c)
{
	t_data_2	d;

	ft_three_rgb(var, to, &d);
	d.native = ft_strtrim(to->set, " \t");
	d.split_sub = ft_split(d.native, ',');
	if (!d.split_sub)
		ft_free_when_exit("Error: in rgb", var, to, &d);
	while (d.split_sub[d.i] != NULL)
	{
		d.j = 0;
		if (ft_check_element(d.split_sub, &d))
			ft_free_when_exit("Error: there is alpha", var, to, &d);
		if (c == 'F')
			var->config.floor[d.k++] = ft_atoi(d.split_sub[d.i]);
		else
			var->config.ceiling[d.k++] = ft_atoi(d.split_sub[d.i]);
		d.i++;
	}
	if (d.i != 3)
		ft_free_when_exit("Error: lack of data.", var, to, &d);
	ft_check_rgb(var, &var->config);
	ft_free_when_exit(NULL, NULL, NULL, &d);
}

void	ft_config_rgb(t_start *var, t_data *to, int *count)
{
	if (to->trim[0] == 'F')
	{
		ft_set_rgb(var, to, 'F');
		(*count)++;
	}
	else if (to->trim[0] == 'C')
	{
		ft_set_rgb(var, to, 'C');
		(*count)++;
	}
}
