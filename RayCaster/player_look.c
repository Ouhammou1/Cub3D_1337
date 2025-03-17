/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_look.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bouhammo <bouhammo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 01:24:52 by bouhammo          #+#    #+#             */
/*   Updated: 2025/03/10 01:04:46 by bouhammo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

bool	is_looking_down(double angle)
{
	if (angle > 0 && angle < M_PI)
		return (true);
	return (false);
}

bool	is_looking_up(double angle)
{
	if (is_looking_down(angle) == false)
		return (true);
	return (false);
}

bool	is_looking_right(double angle)
{
	if (angle < (0.5 * M_PI) || angle > (1.5 * M_PI))
		return (true);
	return (false);
}

bool	is_looking_left(double angle)
{
	if (is_looking_right(angle) == false)
		return (true);
	return (false);
}
