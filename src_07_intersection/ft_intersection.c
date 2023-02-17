/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intersection.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 23:06:55 by kyoulee           #+#    #+#             */
/*   Updated: 2023/02/17 08:39:50 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "ft_intersection.h"

#include <stdio.h>

void	ft_intersection(t_scene *scene)
{
	t_intersection	ip;
	t_vec3			ray_point;
	t_vec3			v3_target;
	int				l;

	l = 0;
	v3_target = ft_vector_3(0.0, 0.0, 1.0);
	while (l < scene->pixel_size)
	{
		ray_point = ft_quaternion_rotate_vec3(scene->pixel_q[l], v3_target);
		if (ft_intersection_obj(scene, \
			&scene->camera_list->camera->coord, &ray_point, &ip))
		{
			ft_intersection_light(scene, &ray_point, &ip);
			ft_image_set_pixel(scene->image, l, &ip.color);
		}
		else
			ft_image_unset_pixel(scene->image, l);
		l++;
	}
}

/*
void	ft_intersection(t_scene *scene)
{
	int test;
	
	test = 0;
	int l;
	t_vec3	ray_point;
	t_vec3	v3_target;
	t_intersection	ip;

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
		if (ft_intersection_obj(scene, 
		&scene->camera_list->camera->coord, &ray_point, &ip))
		{
			ft_intersection_light(scene, &ray_point, &ip);
			ft_image_set_pixel(scene->image, l, &ip.color);
			if (test)
			{
				test = 0;
				ip.color.x = 1.0;
				ip.color.y = 0.0;
				ip.color.z = 0.0;
				ft_image_set_pixel(scene->image, l, &ip.color);
			}

		}
		else
			ft_image_unset_pixel(scene->image, l);
		l++;
	}
}
*/