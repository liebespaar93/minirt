/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 12:37:48 by kyoulee           #+#    #+#             */
/*   Updated: 2022/09/13 08:24:11 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_param.h>
#include <ft_mlx_color.h>
#include <ft_math.h>

int	ft_get_color(float percentage, int color1, int color2)
{
	int		mix_color;
	int		red;
	int		green;
	int		blue;

	red = (int)((1 - percentage) * ((color1 >> 16) & 0xFF) \
		+ percentage * ((color2 >> 16) & 0xFF));
	green = (int)((1 - percentage) * ((color1 >> 8) & 0xFF) \
		+ percentage * ((color2 >> 8) & 0xFF));
	blue = (int)((1 - percentage) * ((color1) & 0xFF) \
		+ percentage * ((color2) & 0xFF));
	mix_color = (red << 16) | (green << 8) | blue;
	return (mix_color);
}

int	ft_color_maker(t_ply *ply, float z)
{
	double	percentage;

	percentage = ft_percent(ply->min_v3.z, ply->max_v3.z, z);
	if (-0.5 >= percentage && percentage >= -1)
		return (ft_get_color(ft_percent(-50, -100, percentage * 100), \
			COLOR_PURPLE, COLOR_BLUE));
	else if (0 > percentage && percentage >= -0.5)
		return (ft_get_color(ft_percent(0, -50, percentage * 100), \
			COLOR_BLUE, COLOR_GREEN));
	else if (percentage == 0)
		return (COLOR_GREEN);
	else if (0 <= percentage && percentage <= 0.5)
		return (ft_get_color(ft_percent(0, 50, percentage * 100), \
			COLOR_GREEN, COLOR_YELLOW));
	else if (0.5 <= percentage && percentage <= 1)
		return (ft_get_color(ft_percent(0, 100, percentage * 100), \
			COLOR_YELLOW, COLOR_RED));
	return (0);
}
