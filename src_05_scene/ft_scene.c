/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scene.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 13:52:16 by kyoulee           #+#    #+#             */
/*   Updated: 2023/01/30 22:30:14 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <errno.h>

#include "ft_scene.h"
#include "ft_minirt_tool.h"

t_scene	*ft_scene_init(t_rt *rt, int x_size, int y_size)
{
	t_scene	*scene;

	if (!ft_zeromalloc((void **)&scene, sizeof(t_scene)))
		ft_exit_print_error(ENOMEM, "ft_scene_init()");
	scene->w = x_size;
	scene->h = y_size;
	scene->pixel_size = x_size * y_size;
	if (!ft_zeromalloc((void **)&scene->pixel_q, sizeof(t_quaternion) * (scene->pixel_size)))
		ft_exit_print_error(ENOMEM, "ft_scene_init()");
	scene->image = ft_image_init(x_size, y_size);
	scene->camera_list = ft_scn_camera_set(rt);
	scene->light_list = ft_scn_light_set(rt);
	scene->obj_list = ft_scn_obj_set(rt);
	return (scene);
}

void	ft_scene_free(t_scene **scene_ptr)
{
	t_scene	*scene;

	if (!scene_ptr)
		return ;
	scene = *scene_ptr;
	if (scene->image)
		ft_image_free(&scene->image);
	if (scene->camera_list)
		ft_scn_camera_free(&scene->camera_list);
	if (scene->light_list)
		ft_scn_light_free(&scene->light_list);
	if (scene->obj_list)
		ft_scn_obj_free(&scene->obj_list);
	if (scene->pixel_q)
		free(scene->pixel_q);
	free(*scene_ptr);
	*scene_ptr = NULL;
}