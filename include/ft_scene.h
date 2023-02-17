/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scene.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 13:50:06 by kyoulee           #+#    #+#             */
/*   Updated: 2023/02/18 02:07:37 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SCENE_H
# define FT_SCENE_H

# include <stdbool.h>

# include "ft_scene_image.h"

# include "ft_scene_camera.h"
# include "ft_scene_light.h"
# include "ft_scene_obj.h"
# include "ft_quaternion.h"

typedef struct s_scene
{
	int				w;
	int				h;
	int				pixel_size;

	t_quaternion	*pixel_q;
	t_scn_image		*image;
	t_scn_camera	*camera_list;
	t_scn_light		*light_list;
	t_scn_obj		*obj_list;
}	t_scene;

t_scene	*ft_scene_init(t_rt *rt, int x_size, int y_size);
void	ft_scene_free(t_scene **scene_ptr);

#endif