/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intersection_obj.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 14:21:04 by kyoulee           #+#    #+#             */
/*   Updated: 2023/02/17 03:27:00 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <math.h>

#include "ft_intersection.h"

#include <stdio.h>

//http://matrix.skku.ac.kr/M-calculus/W2/

bool	ft_obj_plane_intersection(t_pl *obj, t_vec3 coord, t_vec3 *ray_point, t_intersection *intersection)
{	
	t_vec3	back_coord;
	double	t;
	double	l;

	back_coord = ft_vec3_sub(coord, obj->coord);
	l = ft_vec3_dot(*ray_point, obj->gt.point);
	if (l == 0.0)
		return (false);
	else if (l > 0.0)
		intersection->inside = 1;
	else
		intersection->inside = 0;
	t = - ft_vec3_dot(back_coord, obj->gt.point) / l;
	if (t <= 0.0)
		return (false);
	
	intersection->hit_coord = ft_vec3_add(coord, ft_vec3_mult(*ray_point, t));
	intersection->hit_point = ft_vec3_mult(obj->gt.point, 1.0 - intersection->inside * 2.0);
	intersection->dist = ft_vec3_to_vec3_dist(intersection->hit_coord, coord);
	intersection->color = obj->color;
	return (true);
}

bool	ft_obj_sphere_intersection(t_sp *obj, t_vec3 coord, const t_vec3 *ray_point, t_intersection *intersection)
{
	double a;
	double b;
	double c;
	double q;
	t_vec3 back_coord = ft_vec3_sub(coord, obj->coord);
	a = ft_vec3_dot(*ray_point, *ray_point);
	b = 2.0 * ft_vec3_dot(back_coord, *ray_point);
	c = ft_vec3_dot(back_coord, back_coord) - (obj->radius * obj->radius);

	q = (b * b) - (4.0 * a * c);
	if (q <= 0.0)
		return (false);
	q = sqrt(q);
	double t1 = (-b + q) / (2.0 * a);
	double t2 = (-b - q) / (2.0 * a);
	if (t2 < 0.0 && t1 < 0.0)
		return (false);
	if (t2 < 0.0 && ++intersection->inside)
		t2 = t1;
	intersection->hit_coord = ft_vec3_add(coord, ft_vec3_mult(*ray_point, t2));
	intersection->hit_point = ft_vec3_normalize(
			ft_vec3_mult(ft_vec3_sub(intersection->hit_coord, obj->coord), 1.0 - intersection->inside * 2.0));
	intersection->dist = ft_vec3_to_vec3_dist(intersection->hit_coord, coord);
	intersection->color = obj->color;
	return (true);
}

bool	ft_obj_cylinder_intersection_base(t_cy *obj, t_vec3 back_coord, const t_vec3 *ray_point, t_intersection *intersection)
{
	double	top;
	double	bottom;

	top = (back_coord.y - obj->height * 0.5) / -ray_point->y;
	bottom = (back_coord.y + obj->height * 0.5) / -ray_point->y;

	if (top < 0.0 && bottom < 0.0)
		return (false);
	double	t;
	t_vec3	top_coord = ft_vec3_add(back_coord, ft_vec3_mult(*ray_point, top));
	double	top_radius = sqrt(top_coord.x * top_coord.x + top_coord.z * top_coord.z);
	
	t_vec3	bottom_coord = ft_vec3_add(back_coord, ft_vec3_mult(*ray_point, bottom));
	double	bottom_radius = sqrt(bottom_coord.x * bottom_coord.x + bottom_coord.z * bottom_coord.z);

	intersection->inside = 0;
	if (top > 0.0 && bottom > 0.0)
	{
		intersection->inside = 0;
		if (top < bottom)
			t = top;
		else
			t = bottom;
	}
	else
	{
		intersection->inside = 1;
		if (top < 0.0)
			t = bottom;
		else
			t = top;
	}
	if (top_radius < obj->radius && t == top)
	{
		t = top;
	}
	else if (bottom_radius < obj->radius && t == bottom)
	{
		t = bottom;
	}
	else
		return (false);
	intersection->hit_coord = ft_vec3_add(back_coord, ft_vec3_mult(*ray_point, t));
	intersection->hit_point = ft_vector_3(0.0, 1.0, 0.0);
	intersection->hit_point = ft_vec3_mult(intersection->hit_point, 1.0 - 2.0 * intersection->inside);
	intersection->dist = ft_vec3_to_vec3_dist(intersection->hit_coord, back_coord);
	intersection->color = obj->color;
	return (true);
}

// https://mrl.cs.nyu.edu/~dzorin/rend05/lecture2.pdf 
bool	ft_obj_cylinder_intersection_side(t_cy *obj, t_vec3 back_coord, const t_vec3 *ray_point, t_intersection *intersection)
{
	double a;
	double b;
	double c;
	double q;

	a = ray_point->x * ray_point->x + ray_point->z * ray_point->z;
	b = 2.0 * (
			back_coord.x * ray_point->x 
			+ back_coord.z * ray_point->z);
	c = back_coord.x * back_coord.x
		+ back_coord.z *back_coord.z
		- obj->radius * obj->radius;

	q = (b * b) - (4.0 * a * c);
	if (q <= 0.0)
		return (false);
	q = sqrt(q);
	double t1 = (-b - q) / (2.0 * a);
	double t2 = (-b + q) / (2.0 * a);
	double t;

	if (t1 < 0.0 && t2 < 0.0)
		return (false);
	intersection->inside = 0;
	if (t1 > 0.0)
	{
		t = t1;
		if (fabs(back_coord.y + t1 * ray_point->y - obj->coord.y) > obj->height * 0.5)
		{
			if (fabs(back_coord.y + t2 * ray_point->y - obj->coord.y) > obj->height * 0.5)
				return (false);
			t = t2;
			intersection->inside = 1;
		}
	}
	else
	{
		t = t2;
		intersection->inside = 1;
		if (fabs(back_coord.y + t2 * ray_point->y - obj->coord.y) > obj->height * 0.5)
			return (false);
	}
		
	intersection->hit_coord = ft_vec3_add(back_coord, ft_vec3_mult(*ray_point, t));
	intersection->hit_point = ft_vec3_sub(intersection->hit_coord, obj->coord);
	intersection->hit_point.y = 0;
	intersection->hit_point = ft_vec3_normalize(intersection->hit_point);
	intersection->hit_point = ft_vec3_mult(intersection->hit_point, 1.0 - intersection->inside * 2.0);
	intersection->dist = ft_vec3_to_vec3_dist(intersection->hit_coord, back_coord);
	intersection->color = obj->color;
	return (true);
}

bool	ft_obj_cylinder_intersection(t_cy *obj, t_vec3 coord, const t_vec3 *ray_point, t_intersection *intersection)
{
	t_intersection intersection_base;
	t_intersection intersection_side;
	// t_vec3	back_coord = ft_vec3_sub(coord, obj->coord);
	// t_mtx3 m3 = ft_quaternion_rotate_matrix(obj->gt.q_rotation);
	// back_coord = ft_mtx3_mult_vec3(m3, back_coord);
	// t_vec3 back_ray = ft_mtx3_mult_vec3(m3, *ray_point);
	
	
	bool result_side = ft_obj_cylinder_intersection_side(obj, coord, ray_point, &intersection_side);
	bool result_base = ft_obj_cylinder_intersection_base(obj, coord, ray_point, &intersection_base);
	if (!result_side && !result_base)
		return (false);
	if (result_side && result_base)
	{
		if (intersection_side.dist < intersection_base.dist)
			*intersection = intersection_side;
		else
			*intersection = intersection_base;
	}
	else if (result_side)
		*intersection = intersection_side;
	else if (result_base)
		*intersection = intersection_base;
	// t_mtx3 m3_i = ft_mtx3_inverse(m3);
	// intersection->hit_coord = ft_mtx3_mult_vec3(m3_i, intersection->hit_coord);
	// intersection->hit_coord = ft_vec3_add(coord, intersection->hit_coord);
	// intersection->hit_point = ft_mtx3_mult_vec3(m3_i, intersection->hit_point);
	// intersection->dist = ft_vec3_to_vec3_dist(intersection->hit_coord, ray_point);
	return (true);
}

//http://www.songho.ca/math/line/line.html
// bool	ft_obj_plane_intersection(t_pl *obj, t_vec3 coord, const t_vec3 *ray_point, t_intersection *intersection)
// {	
// 	t_vec3	cam_to_obj_v3;
// 	t_vec3	hit_point;
// 	t_vec3	hit_coord;
	
// 	double	cam_to_obj_scaler;
// 	double	cam_to_ray_scaler;
	
// 	t_vec3	point = ft_quaternion_rotate_vec3(obj->gt.q_rotation, ft_vector_3(0.0, 0.0, 1.0));
// 	cam_to_obj_v3 = ft_vec3_sub(obj->coord, coord);
// 	cam_to_obj_scaler = ft_vec3_dot(point, cam_to_obj_v3);
// 	cam_to_ray_scaler = ft_vec3_dot(point, *ray_point);
// 	hit_coord = ft_vec3_add(coord, ft_vec3_mult(*ray_point, cam_to_obj_scaler / cam_to_ray_scaler));
// 	t_vec3 hit_v3 = ft_vec3_sub(hit_coord, coord);
	
// 	if (ft_vec3_dot(cam_to_obj_v3, point) > 0.0) // 방향같을때
// 	{
// 		hit_point = ft_vec3_mult(point, -1.0);
// 		intersection->inside = 1;
// 	}
// 	else
// 	{
// 		hit_point = point;
// 		intersection->inside = 0;
// 	}	

// 	if (ft_vec3_dot(hit_point, *ray_point) > 0.0) // 방행 같을때
// 		return (false);

// 	intersection->dist = sqrt(ft_vec3_dot(hit_v3, hit_v3));
// 	intersection->obj = (t_rt *)obj;
// 	intersection->color = obj->color;
// 	intersection->hit_coord = hit_coord;
// 	intersection->hit_point = hit_point;
// 	return (true);
// }

//https://m.blog.naver.com/hermet/68084286
// bool	ft_obj_sphere_intersection(t_sp *obj, t_vec3 coord, const t_vec3 *ray_point, t_intersection *intersection)
// {
// 	t_vec3	cam_to_obj_v3;
// 	double	cam_to_obj_dist;
// 	double	cam_to_inner_dist;
// 	t_vec3	cam_to_inner_v3;
// 	t_vec3	inner_point;
// 	t_vec3	obj_to_inner_v3;
// 	double	obj_to_inner_dist;
// 	double	q;
// 	double	radius = obj->diameter / 2.0;

// 	cam_to_obj_v3 =  ft_vec3_sub(obj->coord, coord); // 원과의 방향
// 	cam_to_obj_dist = sqrt(ft_vec3_dot(cam_to_obj_v3, cam_to_obj_v3)); 
// 	if (cam_to_obj_dist < radius) //원 안에 있을때
// 	{
// 		coord = ft_vec3_add(coord, ft_vec3_mult(*ray_point, -1 * obj->diameter));
// 		cam_to_obj_v3 =  ft_vec3_sub(obj->coord, coord); // 원과의 방향
// 		inner_point = ft_vec3_add(coord, ft_vec3_mult(*ray_point, ft_vec3_dot(cam_to_obj_v3, *ray_point))); // 내적 위치
// 		cam_to_inner_v3 = ft_vec3_sub(inner_point, coord);
// 		cam_to_inner_dist = sqrt(ft_vec3_dot(cam_to_inner_v3, cam_to_inner_v3)); // 원과의 길이(= 내적과의 길이)
// 		obj_to_inner_v3 = ft_vec3_sub(inner_point, obj->coord); // 원과 내적의 방향
// 		obj_to_inner_dist = sqrt(ft_vec3_dot(obj_to_inner_v3, obj_to_inner_v3)); // 원과 내적의 길이
// 		q = sqrt(pow(radius, 2.0) - pow(obj_to_inner_dist, 2.0));

// 		intersection->dist = fabs(cam_to_inner_dist + q - obj->diameter);
// 		intersection->obj = (t_rt *)obj;
// 		intersection->color = obj->color;
// 		intersection->hit_coord = ft_vec3_add(coord, ft_vec3_mult(*ray_point, cam_to_inner_dist + q));
// 		intersection->hit_point = ft_vec3_normalize(ft_vec3_sub(obj->coord, intersection->hit_coord));
// 		intersection->inside = 1;
// 		return (true);
// 	}

// 	if (ft_vec3_dot(cam_to_obj_v3, *ray_point) < 0.0) // 방행 백터가 반대일때
// 		return (false);

// 	inner_point = ft_vec3_add(coord, ft_vec3_mult(*ray_point, ft_vec3_dot(cam_to_obj_v3, *ray_point))); // 내적 위치
// 	cam_to_inner_v3 = ft_vec3_sub(inner_point, coord); // 내적과의 백터
// 	obj_to_inner_v3 = ft_vec3_sub(inner_point, obj->coord); // 원과 내적의 방향
// 	obj_to_inner_dist = sqrt(ft_vec3_dot(obj_to_inner_v3, obj_to_inner_v3)); // 원과 내적의 길이

// 	if (obj_to_inner_dist > radius) // 내적이 원 밖임
// 		return (false);
	
// 	cam_to_inner_dist = sqrt(ft_vec3_dot(cam_to_inner_v3, cam_to_inner_v3)); // 내적과의 길이
// 	q = sqrt(pow(radius, 2.0) - pow(obj_to_inner_dist, 2.0));
// 	//원 밖에 서 2점을 만날때
// 	intersection->dist = cam_to_inner_dist - q;
// 	intersection->obj = (t_rt *)obj;
// 	intersection->color = obj->color;
// 	intersection->hit_coord = ft_vec3_add(coord, ft_vec3_mult(*ray_point, intersection->dist));
// 	intersection->hit_point = ft_vec3_normalize(ft_vec3_sub(intersection->hit_coord, obj->coord));
// 	intersection->inside = 0;
// 	return (true);
// }


// bool	ft_obj_cylinder_intersection(t_cy *obj, t_vec3 coord, const t_vec3 *ray_point, t_intersection *intersection)
// {
// 	// 최적화
// 	t_vec3	obj_to_cam_v3 = ft_vec3_sub(coord, obj->coord);
	
// 	t_vec3	obj_to_cam_inner_v3 = ft_vec3_mult(obj->gt.point, ft_vec3_dot(obj_to_cam_v3, obj->gt.point));
// 	t_vec3	obj_to_cam_inner_coord = ft_vec3_add(obj->coord, obj_to_cam_inner_v3);
// 	t_vec3	cam_to_obj_inner_v3 = ft_vec3_sub(obj_to_cam_inner_coord, coord);
// 	t_vec3	cam_to_obj_inner_v3_norm = ft_vec3_normalize(cam_to_obj_inner_v3);
	
// 	t_vec3	hit_v3;
// 	t_vec3	hit_point;
// 	t_vec3	hit_coord;
// 	if (sqrt(ft_vec3_dot(cam_to_obj_inner_v3, cam_to_obj_inner_v3)) < obj->diameter / 2.0)
// 	{
// 		hit_v3 = ft_vec3_mult(*ray_point, ft_vec3_dot(cam_to_obj_inner_v3, *ray_point));
// 		hit_coord = ft_vec3_add(coord, hit_v3);
			
// 		if (ft_vec3_dot(*ray_point, cam_to_obj_inner_v3) > 0.0) // 방향같을때
// 		{
// 			hit_point = ft_vec3_mult(obj->gt.point, -1.0);
// 			intersection->inside = 1;
// 		}
// 		else
// 		{
// 			hit_point = obj->gt.point;
// 			intersection->inside = 0;
// 		}

// 		intersection->dist = sqrt(ft_vec3_dot(hit_v3, hit_v3));
// 		intersection->color = obj->color;
// 		intersection->hit_coord = hit_coord;
// 		intersection->hit_point = hit_point;
// 		return (true);
// 	}

// 	if (ft_vec3_dot(*ray_point, cam_to_obj_inner_v3_norm) < 0.0)
// 		return (false);

// 	double	cam_to_obj_inner_dist = ft_vec3_dot(cam_to_obj_inner_v3, cam_to_obj_inner_v3_norm);

// 	t_vec3	cam_to_some_v3 = ft_vec3_mult(*ray_point, cam_to_obj_inner_dist / ft_vec3_dot(cam_to_obj_inner_v3_norm, *ray_point));
// 	t_vec3	cam_to_some_coord = ft_vec3_add(coord, cam_to_some_v3);

// 	t_vec3	obj_to_some_v3 = ft_vec3_sub(cam_to_some_coord, obj->coord);
// 	t_vec3	obj_to_some_inner_v3 = ft_vec3_mult(obj->gt.point, ft_vec3_dot(obj_to_some_v3, obj->gt.point));
// 	t_vec3	obj_to_some_inner_coord = ft_vec3_add(obj->coord, obj_to_some_inner_v3);

// 	t_vec3	some_v3 = ft_vec3_sub(cam_to_some_coord, obj_to_some_inner_coord);
// 	double	some_dist = ft_vec3_dot(some_v3, some_v3);
// 	if (sqrt(some_dist) > obj->diameter / 2.0)
// 		return (false);
	
// 	double q = sqrt(pow(obj->diameter / 2.0, 2.0) - some_dist);
	
// 	double len = sqrt(ft_vec3_dot(cam_to_some_v3, cam_to_some_v3)) - q;
// 	hit_v3 = ft_vec3_mult(*ray_point, len);
// 	hit_coord = ft_vec3_add(coord, hit_v3);
	
// 	t_vec3	obj_to_hit_v3 = ft_vec3_sub(hit_coord, obj->coord);
// 	t_vec3	obj_to_hit_inner_v3 = ft_vec3_mult(obj->gt.point, ft_vec3_dot(obj_to_hit_v3, obj->gt.point));
// 	t_vec3	obj_to_hit_inner_coord = ft_vec3_add(obj->coord, obj_to_hit_inner_v3);
	
// 	//t_vec3	hit_to_obj_inner_v3 = ft_vec3_sub(obj_to_hit_inner_coord, hit_coord);
// 	// if ( sqrt(ft_vec3_dot(obj_to_hit_inner_v3, obj_to_hit_inner_v3)) > obj->height / 2.0)
// 	// 	return (false);
// 	intersection->dist = sqrt(ft_vec3_dot(hit_v3,hit_v3));
// 	intersection->color = obj->color;
// 	intersection->hit_coord = hit_coord;
// 	intersection->hit_point = ft_vec3_normalize(ft_vec3_sub(hit_coord, obj_to_hit_inner_coord));
// 	intersection->inside = 0;
// 	return (true);
// }


























bool	ft_scn_obj_intersection(t_rt *obj, t_vec3 *coord, t_vec3 *ray_point, t_intersection *intersection)
{
	intersection->inside = 0;
	if (!ft_strcmp(obj->type, "sp"))
		return (ft_obj_sphere_intersection((t_sp *)obj->data, *coord, ray_point, intersection));
	else if (!ft_strcmp(obj->type, "pl"))
		return (ft_obj_plane_intersection((t_pl *)obj->data, *coord, ray_point, intersection));
	else if (!ft_strcmp(obj->type, "cy"))
		return (ft_obj_cylinder_intersection((t_cy *)obj->data, *coord, ray_point, intersection));
	
	return (false);
}

bool	ft_obj_intersection(t_scene *scene, t_vec3 *coord, t_vec3 *ray_point, t_intersection *intersection_result)
{
	t_intersection	intersection;
	bool	intersection_found;
	int i;
	double	min_dist;

	intersection_found = false;
	min_dist = 100000000.0;
	i = 0;
	while (i < scene->obj_list->max_index)
	{
		if (ft_scn_obj_intersection(scene->obj_list->rt[i], coord, ray_point, &intersection))
		{
			intersection.obj = scene->obj_list->rt[i];
			if (intersection.dist < min_dist)
			{
				intersection_found = true;
				min_dist = intersection.dist;
				*intersection_result = intersection;
			}
		}
		i++;
	}
	return (intersection_found);
}