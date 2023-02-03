/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intersection_obj.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 14:21:04 by kyoulee           #+#    #+#             */
/*   Updated: 2023/02/03 09:18:19 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <math.h>

#include "ft_intersection.h"

#include <stdio.h>

//http://www.songho.ca/math/line/line.html
bool	ft_obj_plane_intersection(t_pl *obj, t_C *camera, const t_vec3 *ray_point, t_intersection *intersection)
{

	double d = ft_vec3_dot(obj->axis, obj->coord);
	
	double test1 = ft_vec3_dot(camera->coord, obj->axis) + d;
	double t = -1 * test1 / (ft_vec3_dot(obj->axis, *ray_point));

	if (t > 0.0)
	{
		intersection->dist = t;
		intersection->type = obj->type;
		intersection->obj = (t_rt *)obj;
		intersection->color = ft_vector_3(obj->color.bit.r / 255, obj->color.bit.g / 255, obj->color.bit.b/ 255);
		intersection->hit_point = ft_vec3_add(camera->coord, ft_vec3_mult(*ray_point, t));
		// intersection->out_point = 
		// 	ft_vec3_add(*ray_point,
		// 		ft_vec3_mult( ft_vec3_mult(obj->axis ,2), 
		// 			ft_vec3_dot(ft_vec3_mult(*ray_point, -1), obj->axis)));
		return (true);
	}
	return (false);
}

//https://m.blog.naver.com/hermet/68084286
bool	ft_obj_sphere_intersection(t_sp *obj, t_C *camera, const t_vec3 *ray_point, t_intersection *intersection)
{
	t_vec3	cam_to_obj_v3 = ft_vec3_sub(obj->coord, camera->coord); // 원과의 방향
	double	cam_to_obj_dist = ft_vec3_dot(cam_to_obj_v3, cam_to_obj_v3); // 원가의 거리
	double	cam_to_inner_dist = ft_vec3_dot(cam_to_obj_v3, *ray_point); // 내적 길이
	t_vec3	inner_coord = ft_vec3_add(camera->coord, ft_vec3_mult(*ray_point, cam_to_inner_dist));
	t_vec3	obj_to_inner_v3 = ft_vec3_sub(inner_coord, obj->coord); // 원과 내적의 방향
	double	obj_to_inner_dist = ft_vec3_dot(obj_to_inner_v3, obj_to_inner_v3); // 원과 내적의 거리
	double	r = obj->diameter / 2; // 반지름
	double	q = sqrt(pow(obj_to_inner_dist, 2.0) + pow(r, 2.0));

	if (cam_to_inner_dist < 0)
		return (false);
	if (fabs(obj_to_inner_dist) > r)
		return (false);
	if (cam_to_obj_dist < r)
	{
		//원 안에 있을때 
		return (false);
	}
	double a = cam_to_inner_dist - q;
	double b = cam_to_inner_dist + q;
	if (a > 0.0 && b > 0.0)
	{
		//원 밖에 서 2점을 만날때
		if (a < b)
			intersection->dist = a;
		else
			intersection->dist = b;
		intersection->type = obj->type;
		intersection->obj = (t_rt *)obj;
		intersection->color = ft_vector_3(obj->color.bit.r / 255, obj->color.bit.g / 255, obj->color.bit.b/ 255);
		intersection->hit_point = ft_vec3_add(camera->coord, ft_vec3_mult(*ray_point, intersection->dist));
		intersection->hit_axis = ft_vec3_sub(intersection->hit_point, obj->coord);
		return (true);
	}


	return (false);
}


// bool	ft_obj_cylinder_intersection(t_pl *obj, t_C *camera, const t_vec3 *ray_point, t_intersection *intersection)
// {
// 	return (false);
// }

bool	ft_scn_obj_intersection(t_rt *obj, t_C *camera, const t_vec3 *ray_point, t_intersection *intersection)
{
	bool	result;

	result = false;
	if (!ft_strcmp(obj->type, "sp"))
		result = ft_obj_sphere_intersection((t_sp *)obj, camera, ray_point, intersection);
	// else if (!ft_strcmp(obj->type, "pl"))
	// 	result = ft_obj_plane_intersection((t_pl *)obj, camera, ray_point, intersection);
	// else if (!ft_strcmp(obj->type, "cy"))
	// 	result = ft_obj_cylinder_intersection((t_cy *)obj, camera, ray_point, intersection);
	
	return (result);
}

bool	ft_obj_intersection(t_scene *scene, const t_vec3 *ray_point, t_intersection *result_intersection)
{
	t_intersection	intersection;
	bool	intersection_found;
	int i;
	double	min_dist;


	intersection_found = false;
	min_dist = 10000;
	i = 0;
	while (i < scene->obj_list->max_index)
	{
		ft_memset(&intersection, 0, sizeof(t_intersection));
		if (ft_scn_obj_intersection(scene->obj_list->rt[i], scene->camera_list->camera, ray_point, &intersection))
		{
			if (intersection.dist < min_dist)
			{
				intersection_found = true;
				min_dist = intersection.dist;
				*result_intersection = intersection;
			}
		}
		i++;
	}
	return (intersection_found);

}