/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scene_image_set.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 05:02:22 by kyoulee           #+#    #+#             */
/*   Updated: 2023/02/17 05:05:29 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_scene_image.h"

void	ft_image_set_pixel(t_scn_image *image, const int l, const t_vec3 *color)
{
	image->rchannel[l] = color->x;
	image->gchannel[l] = color->y;
	image->bchannel[l] = color->z;
}

void	ft_image_unset_pixel(t_scn_image *image, const int l)
{
	image->rchannel[l] = 0.2;
	image->gchannel[l] = 0.2;
	image->bchannel[l] = 1.0;
}

void	ft_image_convert_color(t_scn_image *image, int point, bool endian)
{
	if (!endian)
	{
		image->back_buffer[point].bit.a = \
			(unsigned char)((image->bchannel[point]) * 255.0);
		image->back_buffer[point].bit.r = \
			(unsigned char)((image->gchannel[point]) * 255.0);
		image->back_buffer[point].bit.g = \
			(unsigned char)((image->rchannel[point]) * 255.0);
		image->back_buffer[point].bit.b = 0;
	}
	else
	{
		image->back_buffer[point].bit.a = 0;
		image->back_buffer[point].bit.r = \
			(unsigned char)((image->rchannel[point]) * 255.0);
		image->back_buffer[point].bit.g = \
			(unsigned char)((image->gchannel[point]) * 255.0);
		image->back_buffer[point].bit.b = \
			(unsigned char)((image->bchannel[point]) * 255.0);
	}
}

void	ft_image_display(t_scn_image *image, bool endian)
{
	int	l;

	l = 0;
	while (l < image->buffer_size)
	{
		ft_image_convert_color(image, l, endian);
		l++;
	}
}
