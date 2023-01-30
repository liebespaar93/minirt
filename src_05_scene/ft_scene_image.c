/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scene_image.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 10:41:30 by kyoulee           #+#    #+#             */
/*   Updated: 2023/01/30 22:58:26 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <errno.h>

#include "mlx.h"

#include "ft_scene_image.h"
#include "ft_minirt_tool.h"

t_scn_image	*ft_image_set()
{
	t_scn_image	*image;

	if (!ft_zeromalloc((void **)&image, sizeof(t_scn_image)))
		ft_exit_print_error(ENOMEM, "ft_image_set()");
	image->x_size = 0;
	image->y_size = 0;
	image->buffer_size = 0;
	image->rchannel = NULL;
	image->gchannel = NULL;
	image->bchannel = NULL;
	image->back_buffer = NULL;
	return (image);	
}

void	ft_image_free(t_scn_image **image_ptr)
{
	t_scn_image	*image;

	if (!image_ptr)
		return ;
	image = *image_ptr;
	if (image->rchannel)
		free(image->rchannel);
	if (image->gchannel)
		free(image->gchannel);
	if (image->bchannel)
		free(image->bchannel);
	if (image->back_buffer)
		free(image->back_buffer);
	free(*image_ptr);
	*image_ptr = NULL;
}

t_scn_image	*ft_image_init(const int x_size, const int y_size)
{
	t_scn_image	*image;

	image = ft_image_set();

	image->x_size = x_size;
	image->y_size = y_size;
	image->buffer_size = x_size * y_size;

	if (!ft_zeromalloc((void **)&image->rchannel, sizeof(double) * (x_size * y_size )) || \
		!ft_zeromalloc((void **)&image->gchannel, sizeof(double) * (x_size * y_size )) || \
		!ft_zeromalloc((void **)&image->bchannel, sizeof(double) * (x_size * y_size )) || \
		!ft_zeromalloc((void **)&image->back_buffer, sizeof(t_color) * (x_size * y_size )))
		ft_image_free(&image);
	return (image);
}

void	ft_image_set_pixel(t_scn_image *image, const int l, const t_vec3 *color)
{
	image->rchannel[l] = color->x;
	image->gchannel[l] = color->y;
	image->bchannel[l] = color->z;
}

void	ft_image_unset_pixel(t_scn_image *image, const int l)
{
	image->rchannel[l] = 0.0;
	image->gchannel[l] = 0.0;
	image->bchannel[l] = 0.0;
}
void	ft_image_convert_color(t_scn_image *image, int point, bool endian)
{
	if (!endian)
	{
		image->back_buffer[point].bit.a = (unsigned char)((image->bchannel[point]) * 255.0);
		image->back_buffer[point].bit.r = (unsigned char)((image->gchannel[point]) * 255.0);
		image->back_buffer[point].bit.g = (unsigned char)((image->rchannel[point]) * 255.0);
		image->back_buffer[point].bit.b = 0;
	}
	else
	{
		image->back_buffer[point].bit.a = 0;
		image->back_buffer[point].bit.r = (unsigned char)((image->rchannel[point]) * 255.0);
		image->back_buffer[point].bit.g = (unsigned char)((image->gchannel[point]) * 255.0);
		image->back_buffer[point].bit.b = (unsigned char)((image->bchannel[point]) * 255.0);
	}
}

void	ft_image_display(t_scn_image *image, bool endian)
{
	int l;
	l = 0;
	
	while (l < image->buffer_size)
		ft_image_convert_color(image, l++, endian);
}
