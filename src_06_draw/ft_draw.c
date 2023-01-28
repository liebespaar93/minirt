/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 13:25:40 by kyoulee           #+#    #+#             */
/*   Updated: 2023/01/28 23:27:45 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdbool.h>

#include "ft_param.h"
#include "ft_draw.h"
#include "ft_quaternion.h"


#include <stdio.h>
void	ft_pixel_axis(t_scene *scene)
{
	t_quaternion	q;
	t_C				*camera;
	double			angle;
	int				y, x, l;
	
	camera = (t_C *)scene->camera_list->rt[scene->camera_list->index];
	if (scene->w > scene->h)
		angle = camera->fov / 180.0 / scene->w * M_PI;
	else
		angle = camera->fov / 180.0 / scene->h * M_PI;
	
	q = ft_quaternion_from_euler_angles(camera->axis);

	t_quaternion	r_x;
	t_quaternion	r_y;
	t_quaternion	out_1;
	t_quaternion	out_2;

	t_vec3	v3;
	l=0;
	y = -scene->h / 2;
	while (y <= scene->h / 2)
	{
		x = -scene->w / 2;
		while (x <= scene->w / 2)
		{
			r_x = ft_quaternion_rotation_y(x * angle);
			r_y = ft_quaternion_rotation_x(y * angle);
			out_1 = ft_quaternion_multiply(q, r_x);
			out_2 = ft_quaternion_multiply(out_1, r_y);

			v3 = ft_quaternion_to_euler_angles(out_2);
			scene->pixel_axis[l++] = v3;
			printf("(%+d, %+d)  ", y, x);
			x++;
		}
		printf("\n");
		y++;
	}
	l=0;
	y = -scene->h / 2;
	while (y <= scene->h / 2)
	{
		x = -scene->w / 2;
		while (x <= scene->w / 2)
		{

			printf("%+.2f %+.2f %+.2f  ", scene->pixel_axis[l].x, scene->pixel_axis[l].y, scene->pixel_axis[l].z );
			x++;l++;
		}
		printf("\n");
		y++;
	}
}


/**
 * @brief 
 * 
 * @param screen 
 * @link https://quaternions.online/
 */
void	ft_pixel_ray(t_scene *scene, int endian)
{
	t_quaternion	q;
	int				l;
	t_vec3	v3;
	t_vec3	v3_target;

	

	v3_target = ft_vector_3(0.0,0.0,1.0);
	l=0;
	while (l < (scene->h) * (scene->w))
	{
		q = ft_quaternion_from_euler_angles(scene->pixel_axis[l]);

		v3 = ft_quaternion_rotate_vec3(q,v3_target);
		if (l && l % (scene->w) == 0)
			printf("\n");
		printf("%+.2f %+.2f %+.2f  ", v3.x, v3.y ,v3.z );
		
		scene->image->rchannel[l] = 1;
		scene->image->gchannel[l] = 0;
		scene->image->bchannel[l] = 0;
		ft_image_convert_color(scene->image, l, endian);
		l++;
	}
}

void	ft_draw_ply(t_param *param)
{
	// 픽셀 하나하나의 위치를 만듬
	ft_pixel_axis(param->scene);

	printf("\n");
	// 레이져 테스트
	ft_pixel_ray(param->scene, param->renderer->endian);
	//ft_light_to_eye(param);
}
