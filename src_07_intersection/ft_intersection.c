/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intersection.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 23:06:55 by kyoulee           #+#    #+#             */
/*   Updated: 2023/02/09 03:02:25 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <math.h>

#include "ft_intersection.h"

#include <stdio.h>

void	ft_intersection(t_scene *scene)
{
	int test;
	test = 0;
	
	int l;
	t_vec3	ray_point;
	t_vec3	v3_target;
	t_intersection	intersection;

	l = 0;
	v3_target = ft_vector_3(0.0, 0.0, 1.0);
	while (l < scene->pixel_size)
	{
		ray_point = ft_quaternion_rotate_vec3(scene->pixel_q[l], v3_target);
		if (l == (scene->w * scene->h) / 2 + (scene->w / 2))
		{
			test = 1;
			printf("center\n");
		}
		if (ft_obj_intersection(scene, &scene->camera_list->camera->coord, &ray_point, &intersection))
		{
			// 물체 표면에 따라 다음에 만들기
			//if (obj_option)
			// {
			//		ft_material_base_compute_color;
			// }
			//else
			// {
			ft_light_intersection(scene, &ray_point, &intersection);
			ft_image_set_pixel(scene->image, l, &intersection.color);
			if (test)
			{
				test = 0;
				intersection.color.x = 1.0;
				intersection.color.y = 0.0;
				intersection.color.z = 0.0;
				ft_image_set_pixel(scene->image, l, &intersection.color);
			}


			// }

		}
		else
			ft_image_unset_pixel(scene->image, l);
		l++;
	}
}

