/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intersection_obj.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 14:21:04 by kyoulee           #+#    #+#             */
/*   Updated: 2023/02/05 05:58:34 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <math.h>

#include "ft_intersection.h"

#include <stdio.h>

//http://matrix.skku.ac.kr/M-calculus/W2/

//http://www.songho.ca/math/line/line.html
bool	ft_obj_plane_intersection(t_pl *obj, t_C *camera, const t_vec3 *ray_point, t_intersection *intersection)
{	
	double t;
	
	t = - 1.0 * (ft_vec3_dot(camera->coord, obj->axis) + ft_vec3_dot(obj->axis, obj->coord)) / (ft_vec3_dot(obj->axis, *ray_point));
	if (t > 0.0)
	{
		intersection->dist = t;
		intersection->type = obj->type;
		intersection->obj = (t_rt *)obj;
		intersection->color = obj->color;
		intersection->hit_point = ft_vec3_add(camera->coord, ft_vec3_mult(*ray_point, t));
		intersection->hit_axis = obj->axis;
		return (true);
	}
	return (false);
}

//https://m.blog.naver.com/hermet/68084286
bool	ft_obj_sphere_intersection(t_sp *obj, t_C *camera, const t_vec3 *ray_point, t_intersection *intersection)
{
	t_vec3	cam_to_obj_v3;
	double	cam_to_inner_dist;
	t_vec3	obj_to_inner_v3;
	double	obj_to_inner_dist;
	double	q;

	cam_to_obj_v3 =  ft_vec3_sub(obj->coord, camera->coord); // 원과의 방향
	cam_to_inner_dist = ft_vec3_dot(cam_to_obj_v3, *ray_point); // 내적 길이
	if (cam_to_inner_dist < 0.0)
		return (false);
	if (ft_vec3_dot(cam_to_obj_v3, cam_to_obj_v3) < obj->radius) //원 안에 있을때
		return (false);
	obj_to_inner_v3 = ft_vec3_sub(ft_vec3_add(camera->coord, ft_vec3_mult(*ray_point, cam_to_inner_dist)), obj->coord); // 원과 내적의 방향
	obj_to_inner_dist = ft_vec3_dot(obj_to_inner_v3, obj_to_inner_v3); // 원과 내적의 거리
	q = sqrt(pow(obj_to_inner_dist, 2.0) + pow(obj->radius, 2.0));
	if (fabs(obj_to_inner_dist) > obj->radius) // 내적이 원 밖임
		return (false);
	
	//원 밖에 서 2점을 만날때
	intersection->dist = cam_to_inner_dist - q;
	intersection->type = obj->type;
	intersection->obj = (t_rt *)obj;
	intersection->color = obj->color;
	intersection->hit_point = ft_vec3_add(camera->coord, ft_vec3_mult(*ray_point, intersection->dist));
	intersection->hit_axis = ft_vec3_normalize(ft_vec3_sub(intersection->hit_point, obj->coord));
	return (true);
}

// bool	ft_obj_cylinder_intersection(t_pl *obj, t_C *camera, const t_vec3 *ray_point, t_intersection *intersection)
// {
// 	return (false);
// }

bool	ft_scn_obj_intersection(t_rt *obj, t_C *camera, const t_vec3 *ray_point, t_intersection *intersection)
{
	if (!ft_strcmp(obj->type, "sp"))
		return (ft_obj_sphere_intersection((t_sp *)obj, camera, ray_point, intersection));
	else if (!ft_strcmp(obj->type, "pl"))
		return (ft_obj_plane_intersection((t_pl *)obj, camera, ray_point, intersection));
	// else if (!ft_strcmp(obj->type, "cy"))
	// 	result = ft_obj_cylinder_intersection((t_cy *)obj, camera, ray_point, intersection);
	
	return (false);
}

bool	ft_obj_intersection(t_scene *scene, const t_vec3 *ray_point, t_intersection *result_intersection)
{
	t_intersection	intersection;
	bool	intersection_found;
	int i;
	double	min_dist;

	intersection_found = false;
	min_dist = 10000.0;
	i = 0;
	while (i < scene->obj_list->max_index)
	{
		// ft_memset(&intersection, 0, sizeof(t_intersection)); 최적화
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