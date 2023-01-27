/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scene_image.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 10:28:26 by kyoulee           #+#    #+#             */
/*   Updated: 2023/01/27 14:46:17 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SCENE_IMAGE_H
# define FT_SCENE_IMAGE_H

# include <stdbool.h>
# include "ft_minirt_tool.h"

typedef struct s_scene_image
{
	/* data */
	int		x_size;
	int		y_size;
	
	double	*rchannel;
	double	*gchannel;
	double	*bchannel;

	double	max_red;
	double	max_green;
	double	max_blue;
	double	max_overall;

	t_color		*back_buffer;
}	t_scn_image;


t_scn_image	*ft_image_set();

void	ft_image_free(t_scn_image **image_ptr);
t_scn_image	*ft_image_init(const int x_size, const int y_size);
int		ft_image_set_pixel(t_scn_image *image, const int x, const int y, const double color[3]);
void	ft_image_display(t_scn_image *image, bool endian);
void	ft_image_convert_color(t_scn_image *image, int point, bool endian);
void	ft_image_compute_max_values(t_scn_image *image);

#endif
