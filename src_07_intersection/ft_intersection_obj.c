/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intersection_obj.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 14:21:04 by kyoulee           #+#    #+#             */
/*   Updated: 2023/02/11 17:13:32 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <math.h>

#include "ft_intersection.h"

#include <stdio.h>

//http://matrix.skku.ac.kr/M-calculus/W2/

//http://www.songho.ca/math/line/line.html
bool	ft_obj_plane_intersection(t_pl *obj, t_vec3 coord, const t_vec3 *ray_point, t_intersection *intersection)
{	
	t_vec3	cam_to_obj_v3;
	t_vec3	hit_point;
	t_vec3	hit_coord;
	
	double	cam_to_obj_scaler;
	double	cam_to_ray_scaler;
	
	cam_to_obj_v3 = ft_vec3_sub(obj->coord, coord);
	cam_to_obj_scaler = ft_vec3_dot(obj->point, cam_to_obj_v3);
	cam_to_ray_scaler = ft_vec3_dot(obj->point, *ray_point);
	hit_coord = ft_vec3_add(coord, ft_vec3_mult(*ray_point, cam_to_obj_scaler / cam_to_ray_scaler));
	t_vec3 hit_v3 = ft_vec3_sub(hit_coord, coord);
	
	if (ft_vec3_dot(cam_to_obj_v3, obj->point) > 0.0) // 방향같을때
	{
		hit_point = ft_vec3_mult(obj->point, -1.0);
		intersection->inside = 1;
	}
	else
	{
		hit_point = obj->point;
		intersection->inside = 0;
	}	

	if (ft_vec3_dot(hit_point, *ray_point) > 0.0) // 방행 같을때
		return (false);

	intersection->dist = sqrt(ft_vec3_dot(hit_v3, hit_v3));
	intersection->type = obj->type;
	intersection->obj = (t_rt *)obj;
	intersection->color = obj->color;
	intersection->hit_coord = hit_coord;
	intersection->hit_point = hit_point;
	return (true);
}

//https://m.blog.naver.com/hermet/68084286
bool	ft_obj_sphere_intersection(t_sp *obj, t_vec3 coord, const t_vec3 *ray_point, t_intersection *intersection)
{
	t_vec3	cam_to_obj_v3;
	double	cam_to_obj_dist;
	double	cam_to_inner_dist;
	t_vec3	cam_to_inner_v3;
	t_vec3	inner_point;
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

		intersection->dist = fabs(cam_to_inner_dist + q - obj->diameter);
		intersection->type = obj->type;
		intersection->obj = (t_rt *)obj;
		intersection->color = obj->color;
		intersection->hit_coord = ft_vec3_add(coord, ft_vec3_mult(*ray_point, cam_to_inner_dist + q));
		intersection->hit_point = ft_vec3_normalize(ft_vec3_sub(obj->coord, intersection->hit_coord));
		intersection->inside = 1;
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
	intersection->hit_point = ft_vec3_normalize(ft_vec3_sub(intersection->hit_coord, obj->coord));
	intersection->inside = 0;
	return (true);
}


bool	ft_obj_cylinder_intersection(t_cy *obj, t_vec3 coord, const t_vec3 *ray_point, t_intersection *intersection)
{
	// 최적화
	t_vec3	obj_to_cam_v3 = ft_vec3_sub(coord, obj->coord);
	
	t_vec3	obj_to_cam_inner_v3 = ft_vec3_mult(obj->point, ft_vec3_dot(obj_to_cam_v3, obj->point));
	t_vec3	obj_to_cam_inner_coord = ft_vec3_add(obj->coord, obj_to_cam_inner_v3);
	t_vec3	cam_to_obj_inner_v3 = ft_vec3_sub(obj_to_cam_inner_coord, coord);
	t_vec3	cam_to_obj_inner_v3_norm = ft_vec3_normalize(cam_to_obj_inner_v3);
	
	if (ft_vec3_dot(*ray_point, cam_to_obj_inner_v3_norm) < 0.0)
		return (false);

	double	cam_to_obj_inner_dist = ft_vec3_dot(cam_to_obj_inner_v3, cam_to_obj_inner_v3_norm);

	t_vec3	cam_to_some_v3 = ft_vec3_mult(*ray_point, cam_to_obj_inner_dist / ft_vec3_dot(cam_to_obj_inner_v3_norm, *ray_point));
	t_vec3	cam_to_some_coord = ft_vec3_add(coord, cam_to_some_v3);

	t_vec3	obj_to_some_v3 = ft_vec3_sub(cam_to_some_coord, obj->coord);
	t_vec3	obj_to_some_inner_v3 = ft_vec3_mult(obj->point, ft_vec3_dot(obj_to_some_v3, obj->point));
	t_vec3	obj_to_some_inner_coord = ft_vec3_add(obj->coord, obj_to_some_inner_v3);

	t_vec3	some_v3 = ft_vec3_sub(cam_to_some_coord, obj_to_some_inner_coord);
	double	some_dist = ft_vec3_dot(some_v3, some_v3);
	// if (sqrt(some_dist) > obj->radius)
	// 	return (false);
	
	double q = sqrt(pow(obj->radius, 2.0) - some_dist );
	
	double len = sqrt(ft_vec3_dot(cam_to_some_v3, cam_to_some_v3)) - q;
	t_vec3	hit_v3 = ft_vec3_mult(*ray_point, len);
	t_vec3	hit_coord = ft_vec3_add(coord, hit_v3);
	
	t_vec3	obj_to_hit_v3 = ft_vec3_sub(hit_coord, obj->coord);
	t_vec3	obj_to_hit_inner_v3 = ft_vec3_mult(obj->point, ft_vec3_dot(obj_to_hit_v3, obj->point));
	t_vec3	obj_to_hit_inner_coord = ft_vec3_add(obj->coord, obj_to_hit_inner_v3);
	
	//t_vec3	hit_to_obj_inner_v3 = ft_vec3_sub(obj_to_hit_inner_coord, hit_coord);
	if ( sqrt(ft_vec3_dot(obj_to_hit_inner_v3, obj_to_hit_inner_v3)) > obj->height / 2.0)
		return (false);
	intersection->dist = sqrt(ft_vec3_dot(hit_v3,hit_v3));
	intersection->type = obj->type;
	intersection->obj = (t_rt *)obj;
	intersection->color = obj->color;
	intersection->hit_coord = hit_coord;
	intersection->hit_point = ft_vec3_normalize(ft_vec3_sub(hit_coord, obj_to_hit_inner_coord));
	intersection->inside = 0;
	return (true);
}


























bool	ft_scn_obj_intersection(t_rt *obj, t_vec3 *coord, const t_vec3 *ray_point, t_intersection *intersection)
{
	if (!ft_strcmp(obj->type, "sp"))
		return (ft_obj_sphere_intersection((t_sp *)obj, *coord, ray_point, intersection));
	else if (!ft_strcmp(obj->type, "pl"))
		return (ft_obj_plane_intersection((t_pl *)obj, *coord, ray_point, intersection));
	else if (!ft_strcmp(obj->type, "cy"))
		return (ft_obj_cylinder_intersection((t_cy *)obj, *coord, ray_point, intersection));
	
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