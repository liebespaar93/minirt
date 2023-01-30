/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 13:25:40 by kyoulee           #+#    #+#             */
/*   Updated: 2023/01/30 23:16:27 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdbool.h>

#include "ft_param.h"
#include "ft_draw.h"
#include "ft_quaternion.h"
#include "ft_intersection.h"


#include <stdio.h>

void	ft_pixel_set_axis(t_scene *scene)
{
	t_quaternion	q;
	t_C				*camera;
	double			angle;
	int				y, x, l;
	t_quaternion	q_trans;
	int y_h;
	int x_h;
	
	
	camera = scene->camera_list->camera;
	if (scene->w > scene->h)
		angle = camera->fov / 360.0 / scene->w * M_PI;
	else
		angle = camera->fov / 360.0 / scene->h * M_PI;
	
	q = ft_quaternion_from_euler_angles(camera->axis);


	l=0;
	y_h = scene->h * 0.5;
	x_h = scene->w * 0.5;
	y = -y_h;
	while (y < y_h)
	{
		x = -x_h;
		while (x < y_h)
		{
			q_trans = ft_quaternion_multiply(q, ft_quaternion_rotation_y(x * angle));
			q_trans = ft_quaternion_multiply(q_trans, ft_quaternion_rotation_x(y * angle));
			scene->pixel_q[l++] = q_trans;
			x++;
		}
		y++;
	}
}

void	ft_pixel_to_image(t_scene *scene)
{
	int l;
	t_vec3	ray_point;
	t_vec3	v3_target;
	t_intersection	intersection;

	l = 0;
	v3_target = ft_vector_3(0.0,0.0,1.0);
	while (l < scene->pixel_size)
	{
		ft_memset(&intersection, 0, sizeof(t_intersection));
		ray_point = ft_quaternion_rotate_vec3(scene->pixel_q[l], v3_target);
		if (ft_obj_intersection(scene, &ray_point, &intersection))
			ft_image_set_pixel(scene->image, l, &intersection.color);
		else
			ft_image_unset_pixel(scene->image, l);
		l++;
	}
}

void	ft_draw_ply(t_param *param)
{
	//최적화
	ft_pixel_set_axis(param->scene);
	ft_pixel_to_image(param->scene);
	ft_image_display(param->scene->image, param->renderer->endian);
}
