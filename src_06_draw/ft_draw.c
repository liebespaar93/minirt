/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 13:25:40 by kyoulee           #+#    #+#             */
/*   Updated: 2023/01/29 18:48:18 by kyoulee          ###   ########.fr       */
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
	
	camera = scene->camera_list->camera;
	if (scene->w > scene->h)
		angle = camera->fov / 360.0 / scene->w * M_PI;
	else
		angle = camera->fov / 360.0 / scene->h * M_PI;
	
	q = ft_quaternion_from_euler_angles(camera->axis);

	t_quaternion	r_x;
	t_quaternion	r_y;
	t_quaternion	out_1;
	t_quaternion	out_2;

	t_vec3	v3;
	l=0;
	y = -scene->h / 2;
	while (y < scene->h / 2)
	{
		x = -scene->w / 2;
		while (x < scene->w / 2)
		{
			r_x = ft_quaternion_rotation_y(x * angle);
			r_y = ft_quaternion_rotation_x(y * angle);
			out_1 = ft_quaternion_multiply(q, r_x);
			out_2 = ft_quaternion_multiply(out_1, r_y);

			v3 = ft_quaternion_to_euler_angles(out_2);
			scene->pixel_axis[l++] = v3;
			// printf("(%+d, %+d)  ", y, x);
			x++;
		}
		//printf("\n");
		y++;
	}
	// l=0;
	// y = -scene->h / 2;
	// while (y <= scene->h / 2)
	// {
	// 	x = -scene->w / 2;
	// 	while (x <= scene->w / 2)
	// 	{
	// 		printf("%+.2f %+.2f %+.2f  ", scene->pixel_axis[l].x, scene->pixel_axis[l].y, scene->pixel_axis[l].z );
	// 		x++;l++;
	// 	}
	// 	printf("\n");
	// 	y++;
	// }
}


typedef struct s_intersection
{
	/* data */
	t_rt	*obj;
	t_vec3	int_point;
	t_vec3	local_normal;
	t_vec3	color;
}	t_intersection;


#include "ft_rt.h"

bool	ft_scn_obj_intersection(t_scene *scene, int obj_index, t_vec3 *ray_point, t_intersection *intersection)
{
	(void)obj_index;
	(void)intersection;
	t_vec3	a;
	double	b;
	double	c;
	//t_vec3 obj = ft_vector_3(0,0,0);
	
	t_vec3 camera_coord = scene->camera_list->camera->coord;

	(void)camera_coord;
	a = ft_vec3_normalize(*ray_point);

	b = 2.0 * ft_vec3_dot(camera_coord, a);
	c = ft_vec3_dot(camera_coord, camera_coord) - 1.0;

	double int_test = (b * b) - (4.0 * c);

	if (int_test > 0.0)
	{
		return (true);
	}
	return (0);
}

bool	ft_obj_intersection(t_scene *scene, t_vec3 *ray_point, t_intersection *close)
{
	(void)close;
	t_intersection	intersection;
	//double	dist;
	double	min_dist;
	bool	intersection_found;
	bool	validint;
	
	min_dist = 100000;
	intersection_found = false;

	ft_memset(&intersection, 0, sizeof(t_intersection));

	int i;
	i = 0;
	validint = false;
	// while (i < scene->obj_list->max_index)
	// {
		validint = ft_scn_obj_intersection(scene, i, ray_point , &intersection);
	// }
	return (validint);

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
	t_vec3	ray_point;
	t_vec3	v3_target;
	bool	validint;
	
	t_intersection	intersection;
	
	v3_target = ft_vector_3(0.0,0.0,1.0);
	l=0;
	while (l < (scene->h) * (scene->w))
	{
		q = ft_quaternion_from_euler_angles(scene->pixel_axis[l]);

		ray_point = ft_quaternion_rotate_vec3(q,v3_target);
		// if (l && l % (scene->w) == 0)
		// 	printf("\n");
		// printf("%+.2f %+.2f %+.2f  ", v3.x, v3.y ,v3.z );
		
		validint = false;
		validint = ft_obj_intersection(scene, &ray_point, &intersection);
		if (validint)
		{
			scene->image->rchannel[l] = 0.0;//1.0 * ((l % (scene->w + 1)) / (float)(scene->w + 1));
			scene->image->gchannel[l] = 0.0;
			scene->image->bchannel[l] = 1.0;
		}
		else
		{

			scene->image->rchannel[l] = 0.0;//1.0 * ((l % (scene->w + 1)) / (float)(scene->w + 1));
			scene->image->gchannel[l] = 0.0;
			scene->image->bchannel[l] = 0.0;
		}
		l++;
	}
	l=0;
	ft_image_compute_max_values(scene->image);
	while (l < (scene->h) * (scene->w))
	{
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
