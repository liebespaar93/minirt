/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scene_image.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 10:41:30 by kyoulee           #+#    #+#             */
/*   Updated: 2023/01/27 19:11:54 by kyoulee          ###   ########.fr       */
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

	if (!ft_zeromalloc((void **)&image->rchannel, sizeof(double) * (x_size * y_size )) || \
		!ft_zeromalloc((void **)&image->gchannel, sizeof(double) * (x_size * y_size )) || \
		!ft_zeromalloc((void **)&image->bchannel, sizeof(double) * (x_size * y_size )) || \
		!ft_zeromalloc((void **)&image->back_buffer, sizeof(t_color) * (x_size * y_size )))
		ft_image_free(&image);
	return (image);
}

int	ft_image_set_pixel(t_scn_image *image, const int x, const int y, const double color[3])
{
	int	point;

	point = y * image->x_size + x;
	image->rchannel[point] = color[0];
	image->gchannel[point] = color[1];
	image->bchannel[point] = color[2];
	return (1);
}

void	ft_image_display(t_scn_image *image, bool endian)
{
	int	x;
	int	y;

	ft_image_compute_max_values(image);
	y = 0;
	while (y < image->y_size)
	{
		x = 0;
		while (x < image->x_size)
		{
			ft_image_convert_color(image, y * image->x_size + x, endian);
			x++;
		}
		y++;
	}
}

void	ft_image_convert_color(t_scn_image *image, int point, bool endian)
{


	if (!endian)
	{
		image->back_buffer[point].bit.a = (unsigned char)((image->bchannel[point] / image->max_overall) * 255.0);
		image->back_buffer[point].bit.r = (unsigned char)((image->gchannel[point] / image->max_overall) * 255.0);
		image->back_buffer[point].bit.g = (unsigned char)((image->rchannel[point] / image->max_overall) * 255.0);
		image->back_buffer[point].bit.b = 0;
	}
	else
	{
		image->back_buffer[point].bit.a = 0;
		image->back_buffer[point].bit.r = (unsigned char)((image->rchannel[point] / image->max_overall) * 255.0);
		image->back_buffer[point].bit.g = (unsigned char)((image->gchannel[point] / image->max_overall) * 255.0);
		image->back_buffer[point].bit.b = (unsigned char)((image->bchannel[point] / image->max_overall) * 255.0);
	}
}

void	ft_image_compute_max_values(t_scn_image *image)
{
	int x;
	int y;
	double	red_value;
	double	green_value;
	double	blue_value;
	
	image->max_red = 0.0;
	image->max_green = 0.0;
	image->max_blue = 0.0;
	image->max_overall = 0.0;
	y = 0;
	while (y < image->y_size)
	{
		x = 0;
		while (x < image->x_size)
		{
			red_value = image->rchannel[y * image->x_size + x];
			green_value = image->gchannel[y * image->x_size + x];
			blue_value = image->bchannel[y * image->x_size + x];

			if (red_value > image->max_red)
				image->max_red = red_value;
			if (green_value > image->max_green)
				image->max_green = green_value;
			if (blue_value > image->max_blue)
				image->max_blue = blue_value;
			if (red_value > image->max_red)
				image->max_red = red_value;
			if (image->max_red > image->max_overall)
				image->max_overall = image->max_red;
			if (image->max_green > image->max_overall)
				image->max_overall = image->max_green;
			if (image->max_blue > image->max_overall)
				image->max_overall = image->max_blue;
			x++;
		}
		y++;
	}
}