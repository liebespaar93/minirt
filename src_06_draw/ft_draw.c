/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 13:25:40 by kyoulee           #+#    #+#             */
/*   Updated: 2023/01/08 01:24:00 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "ft_param.h"
#include "ft_draw.h"
#include "ft_quaternion.h"


#include <stdio.h>
void	ft_pixel_axis(t_screen *screen)
{
	t_quaternion	q;
	t_quaternion	temp_q;
	t_C				*camera;
	double			angle;
	double			temp;
	int				i, k, l;
	
	camera = screen->camera[screen->index];

	angle = camera->fov / screen->w;
	
	q = ft_quaternion_euler_from_angles((t_angles){camera->axis.x * 180, camera->axis.y * 180, camera->axis.z * 180});


	l=0;
	i = -screen->h / 2;
	while (i <= screen->h / 2)
	{
		k = -screen->w / 2;
		while (k <= screen->w / 2)
		{
			temp_q = q;
			temp_q = ft_quaternion_multiply(temp_q, ft_quaternion_rotation_x(k * angle));
			temp_q = ft_quaternion_multiply(temp_q, ft_quaternion_rotation_y(i * angle));


			screen->pixel_axis[l++] = ft_quaternion_euler_to_angles(temp_q);
			printf("(%+d, %+d)  ", i, k);
			k++;
		}
		printf("\n");
		i++;
	}
	
	l=0;
	i = -screen->h / 2;
	while (i <= screen->h / 2)
	{
		k = -screen->w / 2;
		while (k <= screen->w / 2)
		{
			printf("%+.2f %+.2f %+.2f  ", screen->pixel_axis[l].x, screen->pixel_axis[l].y, screen->pixel_axis[l].z );
			k++;l++;
		}
		printf("\n");
		i++;
	}
}

// 각도를 픽샐로 나눔

//

void	ft_draw_ply(t_param *param)
{
	t_C *eye;

	eye = param->screen->camera[param->screen->index];
	ft_pixel_axis(param->screen);

}

