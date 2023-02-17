/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shadow.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 16:15:57 by kyoulee           #+#    #+#             */
/*   Updated: 2023/02/17 09:22:05 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "ft_shadow.h"

bool	ft_shadow(t_scene *scene, t_vec3 *coord, t_intersection *ip_obj)
{
	t_intersection	ip;
	t_vec3			ray_point;
	double			dist;
	t_vec3			axis;
	int				i;

	i = 0;
	axis = ft_vec3_sub(ip_obj->hit_coord, *coord);
	dist = sqrt(ft_vec3_dot(axis, axis)) - 0.000001;
	ray_point = ft_vec3_normalize(axis);
	while (i < scene->obj_list->max_index)
	{
		if (ft_intersection_scn_obj(\
			scene->obj_list->rt[i], coord, &ray_point, &ip))
		{
			ip.obj = scene->obj_list->rt[i];
			if (ip.dist <= dist)
				return (true);
			else if (ip_obj->obj == ip.obj && ip.inside != ip_obj->inside)
				return (true);
		}
		i++;
	}
	return (false);
}
