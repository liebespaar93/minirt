/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intersection_obj.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 14:21:04 by kyoulee           #+#    #+#             */
/*   Updated: 2023/02/07 03:47:29 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <math.h>

#include "ft_intersection.h"

#include <stdio.h>

//http://matrix.skku.ac.kr/M-calculus/W2/

//http://www.songho.ca/math/line/line.html
bool	ft_obj_plane_intersection(t_pl *obj, t_vec3 coord, const t_vec3 *ray_point, t_intersection *intersection)
{	
	double t;
	
	t = - 1.0 * (ft_vec3_dot(coord, obj->axis) + ft_vec3_dot(obj->axis, obj->coord)) / (ft_vec3_dot(obj->axis, *ray_point));
	if (t <= 0.0)
		return (false);
	intersection->dist = t;
	intersection->type = obj->type;
	intersection->obj = (t_rt *)obj;
	intersection->color = obj->color;
	intersection->hit_coord = ft_vec3_add(coord, ft_vec3_mult(*ray_point, t));
	intersection->hit_axis = obj->axis;
	return (true);
}

//https://m.blog.naver.com/hermet/68084286
bool	ft_obj_sphere_intersection(t_sp *obj, t_vec3 coord, const t_vec3 *ray_point, t_intersection *intersection)
{
	t_vec3	cam_to_obj_v3;
	double	cam_to_obj_dist;
	double	cam_to_inner_dist;
	t_vec3	cam_to_inner_v3;
	t_vec3 inner_point;
	t_vec3	obj_to_inner_v3;
	double	obj_to_inner_dist;
	double	q;

	cam_to_obj_v3 =  ft_vec3_sub(obj->coord, coord); // 원과의 방향
	cam_to_obj_dist = sqrt(ft_vec3_dot(cam_to_obj_v3, cam_to_obj_v3)); 
	if (cam_to_obj_dist < obj->radius) //원 안에 있을때
	{
		coord = ft_vec3_add(coord, ft_vec3_mult(*ray_point, -1 * obj->diameter));
		cam_to_obj_v3 =  ft_vec3_sub(obj->coord, coord); // 원과의 방향
		inner_point = ft_vec3_add(coord, ft_vec3_mult(*ray_point, ft_vec3_dot(cam_to_obj_v3, *ray_point))); // 내적 위치
		cam_to_inner_v3 = ft_vec3_sub(inner_point, coord);
		cam_to_inner_dist = sqrt(ft_vec3_dot(cam_to_inner_v3, cam_to_inner_v3)); // 원과의 길이(= 내적과의 길이)
		obj_to_inner_v3 = ft_vec3_sub(inner_point, obj->coord); // 원과 내적의 방향
		obj_to_inner_dist = sqrt(ft_vec3_dot(obj_to_inner_v3, obj_to_inner_v3)); // 원과 내적의 길이
		q = sqrt(pow(obj->radius, 2.0) - pow(obj_to_inner_dist, 2.0));
		// if (ft_vec3_dot(cam_to_obj_v3, *ray_point) > 0.0)
		// 	return (false);
		intersection->dist = fabs(cam_to_inner_dist + q - obj->diameter);
		intersection->type = obj->type;
		intersection->obj = (t_rt *)obj;
		intersection->color = obj->color;
		intersection->hit_coord = ft_vec3_add(coord, ft_vec3_mult(*ray_point, cam_to_inner_dist + q));
		intersection->hit_axis = ft_vec3_normalize(ft_vec3_sub(obj->coord, intersection->hit_coord));
		return (true);
	}

	if (ft_vec3_dot(cam_to_obj_v3, *ray_point) < 0.0) // 방행 백터가 반대일때
		return (false);

	inner_point = ft_vec3_add(coord, ft_vec3_mult(*ray_point, ft_vec3_dot(cam_to_obj_v3, *ray_point))); // 내적 위치
	cam_to_inner_v3 = ft_vec3_sub(inner_point, coord); // 내적과의 백터
	obj_to_inner_v3 = ft_vec3_sub(inner_point, obj->coord); // 원과 내적의 방향
	obj_to_inner_dist = sqrt(ft_vec3_dot(obj_to_inner_v3, obj_to_inner_v3)); // 원과 내적의 길이

	if (obj_to_inner_dist > obj->radius) // 내적이 원 밖임
		return (false);
	
	cam_to_inner_dist = sqrt(ft_vec3_dot(cam_to_inner_v3, cam_to_inner_v3)); // 내적과의 길이
	q = sqrt(pow(obj->radius, 2.0) - pow(obj_to_inner_dist, 2.0));
	//원 밖에 서 2점을 만날때
	intersection->dist = cam_to_inner_dist - q;
	intersection->type = obj->type;
	intersection->obj = (t_rt *)obj;
	intersection->color = obj->color;
	intersection->hit_coord = ft_vec3_add(coord, ft_vec3_mult(*ray_point, intersection->dist));
	intersection->hit_axis = ft_vec3_normalize(ft_vec3_sub(intersection->hit_coord, obj->coord));
	return (true);
}


// bool	ft_obj_cylinder_intersection(t_cy *obj, t_C *camera, const t_vec3 *ray_point, t_intersection *intersection)
// {
// 	t_vec3	cam_to_obj_v3;
// 	double	cam_to_inner_dist;
// 	t_vec3	obj_to_inner_v3;
// 	double	obj_to_inner_dist;
// 	double	q;
	
	
// 	cam_to_obj_v3 =  ft_vec3_sub(obj->coord, camera->coord); // 기둥과의 방향
// 	cam_to_inner_dist = ft_vec3_dot(cam_to_obj_v3, *ray_point); // 내적 길이
// 	if (cam_to_inner_dist < 0.0)
// 		return (false);
	
// 	//몸통
	

// 	obj_to_inner_v3 = ft_vec3_sub(ft_vec3_add(camera->coord, ft_vec3_mult(*ray_point, cam_to_inner_dist)), obj->coord); // 원과 내적의 방향
// 	obj_to_inner_dist = ft_vec3_dot(obj_to_inner_v3, obj_to_inner_v3); // 원과 내적의 거리
// 	q = sqrt(pow(obj_to_inner_dist, 2.0) + pow(obj->radius, 2.0));

// 	intersection->dist = cam_to_inner_dist - q;
// 	intersection->type = obj->type;
// 	intersection->obj = (t_rt *)obj;
// 	intersection->color = obj->color;
// 	intersection->hit_coord = ft_vec3_add(camera->coord, ft_vec3_mult(*ray_point, intersection->dist));
// 	intersection->hit_axis = ft_vec3_normalize(ft_vec3_sub(intersection->hit_coord, obj->coord));
	
// 	return (true);
// }

bool	ft_scn_obj_intersection(t_rt *obj, t_vec3 *coord, const t_vec3 *ray_point, t_intersection *intersection)
{
	if (!ft_strcmp(obj->type, "sp"))
		return (ft_obj_sphere_intersection((t_sp *)obj, *coord, ray_point, intersection));
	else if (!ft_strcmp(obj->type, "pl"))
		return (ft_obj_plane_intersection((t_pl *)obj, *coord, ray_point, intersection));
	// else if (!ft_strcmp(obj->type, "cy"))
	// 	return (ft_obj_cylinder_intersection((t_cy *)obj, camera, ray_point, intersection));
	
	return (false);
}

bool	ft_obj_intersection(t_scene *scene, t_vec3 *coord, const t_vec3 *ray_point, t_intersection *result_intersection)
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
		if (ft_scn_obj_intersection(scene->obj_list->rt[i], coord, ray_point, &intersection))
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