/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intersection_obj_cylinder.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 07:02:31 by kyoulee           #+#    #+#             */
/*   Updated: 2023/02/18 07:13:37 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "ft_intersection.h"

/**
 * @brief 
 * `
 * @param back_coord 
 * @param ray_point 
 * @param info [3] = {top, bottom, radius}
 * @param t 
 * @return true 
 * @return false 
 */
bool	ft_obj_cylinder_intersection_base_assistant(
	t_vec3 back_coord, t_vec3 *ray_point, double info[3], double *t)
{
	t_vec3	top;
	t_vec3	bottom;

	top = ft_vec3_add(back_coord, ft_vec3_mult(*ray_point, info[0]));
	bottom = ft_vec3_add(back_coord, ft_vec3_mult(*ray_point, info[1]));
	if (top.x * top.x + top.y * top.y < info[2] * info[2] \
		&& *t == info[0])
		*t = info[0];
	else if (
		bottom.x * bottom.x + bottom.y * bottom.y < info[2] * info[2] \
		&& *t == info[1])
		*t = info[1];
	else
		return (false);
	return (true);
}

/**
 * @brief 
 * 
 * @param obj 
 * @param back_coord 
 * @param ray_point 
 * @param ip 
 * @return true 
 * @return false 
 */
bool	ft_obj_cylinder_intersection_base(
	t_cy *obj, t_vec3 back_coord, t_vec3 *ray_point, t_intersection *ip)
{
	double	t;
	double	top;
	double	bottom;

	top = (back_coord.z - obj->height * 0.5) / -ray_point->z;
	bottom = (back_coord.z + obj->height * 0.5) / -ray_point->z;
	if (top < 0.0 && bottom < 0.0)
		return (false);
	ip->inside = 0;
	t = top;
	if (top > 0.0 && bottom > 0.0 && top > bottom)
		t = bottom;
	else if (top < 0.0 && ++ip->inside)
		t = bottom;
	if (!ft_obj_cylinder_intersection_base_assistant(\
		back_coord, ray_point, (double [3]){top, bottom, obj->radius}, &t))
		return (false);
	ip->hit_coord = ft_vec3_add(back_coord, ft_vec3_mult(*ray_point, t));
	ip->hit_point = ft_vec3_mult(\
			ft_vector_3(0.0, 0.0, 1.0), 1.0 - 2.0 * ip->inside);
	ip->dist = ft_vec3_to_vec3_dist(ip->hit_coord, back_coord);
	ip->color = obj->color;
	return (true);
}

/**
 * @brief 
 * 
 * @param t_ip 
 * @param info = (double [4])
 * 		{back_coord.z, 
 * 		ray_point->z, 
 * 		obj->coord.z, 
 * 		obj->height}
 * @param t 
 * @param ip 
 * @return true 
 * @return false 
 */
bool	ft_obj_cylinder_intersection_side_assistant(
	double t_ip[2], double info[3], double *t, t_intersection *ip)
{
	ip->inside = 0;
	if (t_ip[0] > 0.0)
	{
		*t = t_ip[0];
		if (fabs(info[0] + t_ip[0] * info[1]) > info[2] * 0.5 && ++ip->inside)
		{
			if (fabs(info[0] + t_ip[1] * info[1]) > info[2] * 0.5)
				return (false);
			*t = t_ip[1];
		}
	}
	else if (++ip->inside)
	{
		*t = t_ip[1];
		if (fabs(info[0] + t_ip[1] * info[1]) > info[2] * 0.5)
			return (false);
	}
	return (true);
}

/**
 * @brief 
 * 
 * @param obj 
 * @param back_coord 
 * @param ray_point 
 * @param ip 
 * @return true 
 * @return false 
 */
bool	ft_obj_cylinder_intersection_side(
	t_cy *obj, t_vec3 back_coord, t_vec3 *ray_point, t_intersection *ip)
{
	double	t;
	double	t_ip[2];

	if (!ft_intersection_obj_math_circle(\
		ft_vector_3(back_coord.x, back_coord.y, 0.0), \
		ft_vector_3(ray_point->x, ray_point->y, 0.0), obj->radius, &t_ip))
		return (false);
	if (t_ip[0] < 0.0 && t_ip[1] < 0.0)
		return (false);
	if (!ft_obj_cylinder_intersection_side_assistant(t_ip, \
		(double [4]){back_coord.z, ray_point->z, obj->height}, \
		&t, ip))
		return (false);
	ip->hit_coord = ft_vec3_add(back_coord, ft_vec3_mult(*ray_point, t));
	ip->hit_point = ft_vec3_sub(ip->hit_coord, obj->coord);
	ip->hit_point.z = 0;
	ip->hit_point = ft_vec3_normalize(ip->hit_point);
	ip->hit_point = ft_vec3_mult(ip->hit_point, 1.0 - ip->inside * 2.0);
	ip->dist = ft_vec3_to_vec3_dist(ip->hit_coord, back_coord);
	ip->color = obj->color;
	return (true);
}

/**
 * @brief 
 * 
 * @param obj 
 * @param coord 
 * @param ray_point 
 * @param ip 
 * @ref https://mrl.cs.nyu.edu/~dzorin/rend05/lecture2.pdf 
 * @return true 
 * @return false 
 */
bool	ft_intersection_obj_cylinder(
	t_cy *obj, t_vec3 back_coord, t_vec3 *back_ray_point, t_intersection *ip)
{
	t_intersection	ip_base;
	t_intersection	ip_side;
	bool			result_base;
	bool			result_side;

	result_side = ft_obj_cylinder_intersection_side(\
		obj, back_coord, back_ray_point, &ip_side);
	result_base = ft_obj_cylinder_intersection_base(\
		obj, back_coord, back_ray_point, &ip_base);
	if (!result_side && !result_base)
		return (false);
	if (result_side && result_base)
	{
		if (ip_side.dist < ip_base.dist)
			*ip = ip_side;
		else
			*ip = ip_base;
	}
	else if (result_side)
		*ip = ip_side;
	else if (result_base)
		*ip = ip_base;
	return (true);
}
