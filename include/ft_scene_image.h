/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scene_image.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 10:28:26 by kyoulee           #+#    #+#             */
/*   Updated: 2023/02/18 02:21:03 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SCENE_IMAGE_H
# define FT_SCENE_IMAGE_H

# include <stdbool.h>
# include "ft_minirt_tool.h"
# include "ft_vector.h"

typedef struct s_scene_image
{
	int		x_size;
	int		y_size;
	int		buffer_size;

	double	*rchannel;
	double	*gchannel;
	double	*bchannel;

	t_color	*back_buffer;
}	t_scn_image;

t_scn_image	*ft_image_set(void);

void		ft_image_free(t_scn_image **image_ptr);
t_scn_image	*ft_image_init(const int x_size, const int y_size);
void		ft_image_set_pixel(\
	t_scn_image *image, const int l, const t_vec3 *color);
void		ft_image_unset_pixel(t_scn_image *image, const int l);
void		ft_image_display(t_scn_image *image, bool endian);
void		ft_image_convert_color(t_scn_image *image, int point, bool endian);

#endif
