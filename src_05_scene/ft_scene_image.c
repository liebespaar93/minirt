/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scene_image.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 10:41:30 by kyoulee           #+#    #+#             */
/*   Updated: 2023/02/17 05:02:56 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <errno.h>

#include "ft_scene_image.h"
#include "ft_minirt_tool.h"

t_scn_image	*ft_image_set(void)
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
	if (!ft_zeromalloc((void **)&image->rchannel, \
			sizeof(double) * (image->buffer_size)) || \
		!ft_zeromalloc((void **)&image->gchannel, \
			sizeof(double) * (image->buffer_size)) || \
		!ft_zeromalloc((void **)&image->bchannel, \
			sizeof(double) * (image->buffer_size)) || \
		!ft_zeromalloc((void **)&image->back_buffer, \
			sizeof(t_color) * (image->buffer_size)))
		ft_image_free(&image);
	return (image);
}
