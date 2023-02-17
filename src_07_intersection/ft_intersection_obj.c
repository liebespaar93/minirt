/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intersection_obj.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 14:21:04 by kyoulee           #+#    #+#             */
/*   Updated: 2023/02/17 08:41:06 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "ft_intersection.h"

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
		return (ft_intersection_obj_cylinder(\
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
