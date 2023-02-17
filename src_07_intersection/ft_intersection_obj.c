/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intersection_obj.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 14:21:04 by kyoulee           #+#    #+#             */
/*   Updated: 2023/02/18 07:18:39 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "ft_intersection.h"

bool	ft_intersection_obj_back_cylinder(
	t_cy *obj, t_vec3 coord, t_vec3 *ray_point, t_intersection *ip)
{
	t_vec3			back_coord;
	t_vec3			back_ray_point;
	t_quaternion	q;

	q = ft_quaternion_rotation_xyz(ft_vec3_mult(obj->axis, M_PI));
	back_coord = ft_vec3_sub(coord, obj->coord);
	back_coord = ft_quaternion_rotate_vec3(q, back_coord);
	back_ray_point = ft_quaternion_rotate_vec3(q, *ray_point);
	if (!ft_intersection_obj_cylinder(obj, back_coord, &back_ray_point, ip))
		return (false);
	q = ft_quaternion_inverse(q);
	ip->hit_coord = ft_quaternion_rotate_vec3(q, ip->hit_coord);
	ip->hit_coord = ft_vec3_add(ip->hit_coord, obj->coord);
	ip->hit_point = ft_quaternion_rotate_vec3(q, ip->hit_point);
	return (true);
}

bool	ft_intersection_scn_obj(
	t_rt *obj, t_vec3 *coord, t_vec3 *ray_point, t_intersection *ip)
{
	ip->inside = 0;
	if (!ft_strcmp(obj->type, "sp"))
		return (ft_intersection_obj_sphere(\
			(t_sp *)obj->data, *coord, ray_point, ip));
	else if (!ft_strcmp(obj->type, "pl"))
		return (ft_intersection_obj_plane(\
			(t_pl *)obj->data, *coord, ray_point, ip));
	else if (!ft_strcmp(obj->type, "cy"))
		return (ft_intersection_obj_back_cylinder(\
			(t_cy *)obj->data, *coord, ray_point, ip));
	return (false);
}

bool	ft_intersection_obj(
	t_scene *scene, t_vec3 *coord, t_vec3 *ray_point,
	t_intersection *ip_result)
{
	t_intersection	ip;
	bool			ip_found;
	double			min_dist;
	int				i;

	ip_found = false;
	min_dist = 100000000.0;
	i = 0;
	while (i < scene->obj_list->max_index)
	{
		if (ft_intersection_scn_obj(\
			scene->obj_list->rt[i], coord, ray_point, &ip))
		{
			ip.obj = scene->obj_list->rt[i];
			if (ip.dist < min_dist)
			{
				ip_found = true;
				min_dist = ip.dist;
				*ip_result = ip;
			}
		}
		i++;
	}
	return (ip_found);
}
