/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_old.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 13:25:40 by kyoulee           #+#    #+#             */
/*   Updated: 2023/01/29 05:34:36 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdbool.h>

#include "ft_param.h"
#include "ft_draw.h"
#include "ft_quaternion.h"


#include <stdio.h>
void	ft_pixel_axis(t_screen *screen)
{
	t_quaternion	q;
	t_C				*camera;
	double			angle;
	//double			temp;
	int				y, x, l;
	
	camera = screen->camera[screen->index];

	angle = camera->fov /180.0 / screen->w * M_PI;
	
	q = ft_quaternion_from_euler_angles(camera->axis);

	t_quaternion	r_x;
	t_quaternion	r_y;
	t_quaternion	out_1;
	t_quaternion	out_2;

	t_vec3	v3;
	l=0;
	y = -screen->h / 2;
	while (y <= screen->h / 2)
	{
		x = -screen->w / 2;
		while (x <= screen->w / 2)
		{
			r_x = ft_quaternion_rotation_y(x * angle);
			r_y = ft_quaternion_rotation_x(y * angle);
			out_1 = ft_quaternion_multiply(q, r_x);
			out_2 = ft_quaternion_multiply(out_1, r_y);

			v3 = ft_quaternion_to_euler_angles(out_2);
			screen->pixel_axis[l++] = v3;
			printf("(%+d, %+d)  ", y, x);
			x++;
		}
		printf("\n");
		y++;
	}
	l=0;
	y = -screen->h / 2;
	while (y <= screen->h / 2)
	{
		x = -screen->w / 2;
		while (x <= screen->w / 2)
		{
			printf("%+.2f %+.2f %+.2f  ", screen->pixel_axis[l].x, screen->pixel_axis[l].y, screen->pixel_axis[l].z );
			x++;l++;
		}
		printf("\n");
		y++;
	}
}

bool ft_test_obj(t_vec3 v3, int x, int y)
{
	(void)v3;
	(void)x;
	(void)y;
	return (1);
}


void	ft_image_convert_color(t_scn_image *image, int point, bool endian)
{


	if (endian)
	{
		image->back_buffer[point].bit.a = (unsigned char)((image->bchannel[point] / image->max_overall) * 255.0);
		image->back_buffer[point].bit.r = (unsigned char)((image->gchannel[point] / image->max_overall) * 255.0);
		image->back_buffer[point].bit.g = (unsigned char)((image->rchannel[point] / image->max_overall) * 255.0);
		image->back_buffer[point].bit.b = 0;
	}
	else
	{
		image->back_buffer[point].bit.a = 0;
		image->back_buffer[point].bit.r = (unsigned char)((image->rchannel[point] / image->max_overall) * 255.0);
		image->back_buffer[point].bit.g = (unsigned char)((image->gchannel[point] / image->max_overall) * 255.0);
		image->back_buffer[point].bit.b = (unsigned char)((image->bchannel[point] / image->max_overall) * 255.0);
	}
}

/**
 * @brief 
 * 
 * @param screen 
 * @link https://quaternions.online/
 */
void	ft_pixel_ray(t_param *param)
{
	t_quaternion	q;
	//t_quaternion	q_c;
	
	int				l;
	

	t_vec3	v3;

	t_vec3	v3_target;
	t_color	color;

	

	v3_target = ft_vector_3(0.0,0.0,1.0);
	l=0;
	while (l < param->screen->h * param->screen->w)
	{
		q = ft_quaternion_from_euler_angles(param->screen->pixel_axis[l++]);

		v3 = ft_quaternion_rotate_vec3(q,v3_target);
		printf("%+.2f %+.2f %+.2f  ", v3.x, v3.y ,v3.z );
		if (l % param->screen->w == 0)
			printf("\n");
		color.bit.a = 0;
		color.bit.r = 255;
		color.bit.g = 255;
		color.bit.b = 0;
		ft_put_pixel_color(param->back_buffer, color, l);
	}
}

void	ft_draw_ply(t_param *param)
{
	// 픽셀 하나하나의 위치를 만듬
	ft_pixel_axis(param->screen);

	printf("\n");
	// 레이져 테스트
	ft_pixel_ray(param);
	//ft_light_to_eye(param);
}
