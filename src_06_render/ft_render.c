/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 13:25:40 by kyoulee           #+#    #+#             */
/*   Updated: 2023/02/18 02:49:43 by kyoulee          ###   ########.fr       */
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
	double			angle;
	int				x;
	int				y;
	int				l;

	if (scene->w > scene->h)
		angle = scene->camera_list->camera->fov / 180.0 / scene->w * M_PI;
	else
		angle = scene->camera_list->camera->fov / 180.0 / scene->h * M_PI;
	l = 0;
	y = -scene->h * 0.5;
	while (y < scene->h * 0.5 + scene->h % 2)
	{
		x = -scene->w * 0.5;
		while (x < scene->w * 0.5 + scene->w % 2)
		{
			scene->pixel_q[l++] = \
				ft_quaternion_multiply(scene->camera_list->camera->q_axis, \
					ft_quaternion_rotation_xyz(\
						ft_vector_3(y * angle, x * angle, 0.0)));
			x++;
		}
		y++;
	}
}

void	ft_render(t_param *param)
{	
	ft_pixel_set_axis(param->scene);
	ft_intersection(param->scene);
	ft_image_display(param->scene->image, param->renderer->endian);
}

/*
#include <sys/time.h>

void	ft_render(t_param *param)
{
	struct timeval stop, start;
	gettimeofday(&start, NULL);
	
	//최적화 픽셀 방향 세팅 움직임이 없을시 스킵 나중에 변경
	ft_pixel_set_axis(param->scene);
	
	gettimeofday(&stop, NULL);
	printf("time : %ld\n", (stop.tv_sec - 
	start.tv_sec) * 1000000 + stop.tv_usec - start.tv_usec);

	//픽셀의 쿼터니언 을 이용해서 충돌을 구함
	ft_intersection(param->scene);

	gettimeofday(&stop, NULL);
	printf("time : %ld\n", (stop.tv_sec - 
	start.tv_sec) * 1000000 + stop.tv_usec - start.tv_usec);

	ft_image_display(param->scene->image, param->renderer->endian);
	gettimeofday(&stop, NULL);
	printf("time : %ld\n", (stop.tv_sec - 
	start.tv_sec) * 1000000 + stop.tv_usec - start.tv_usec);
	
}
*/