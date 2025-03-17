/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_func_maths.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bouhammo <bouhammo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 21:50:39 by bouhammo          #+#    #+#             */
/*   Updated: 2025/03/15 01:32:13 by bouhammo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

double	normalize_angle(double angle)
{
	angle = fmod(angle, 2 * M_PI);
	if (angle <= 0)
		angle += 2 * M_PI;
	return (angle);
}

double	deg_to_rad(double deg)
{
	double	angle;

	angle = deg * (M_PI / 180.0);
	return (angle);
}

double	rad_to_deg(double red)
{
	return (red * (180.0 / M_PI));
}

void	ft_error(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(2, &str[i], 1);
		i++;
	}
	exit(EXIT_FAILURE);
}

int	ft_caracter(char Y)
{
	if (Y == 'N' || Y == 'S' || Y == 'W' || Y == 'E')
		return (1);
	return (0);
}
