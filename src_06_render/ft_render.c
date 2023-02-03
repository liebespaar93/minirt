/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 13:25:40 by kyoulee           #+#    #+#             */
/*   Updated: 2023/02/02 17:43:25 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdbool.h>

#include "ft_param.h"
#include "ft_render.h"
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
	while (y <= y_h)
	{
		x = -x_h;
		while (x <= x_h)
		{
			q_trans = ft_quaternion_multiply(q, ft_quaternion_rotation_y(x * angle));
			q_trans = ft_quaternion_multiply(q_trans, ft_quaternion_rotation_x(y * angle));
			scene->pixel_q[l++] =  ft_quaternion_normalize(q_trans);
			x++;
		}
		y++;
	}
}

void	ft_render(t_param *param)
{
	//최적화 픽셀 방향 세팅 움직임이 없을시 스킵 나중에 변경
	ft_pixel_set_axis(param->scene);
	
	//픽셀의 쿼터니언 을 이용해서 충돌을 구함
	ft_intersection(param->scene);

	ft_image_display(param->scene->image, param->renderer->endian);
}
