/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shadow.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 16:15:57 by kyoulee           #+#    #+#             */
/*   Updated: 2023/02/12 08:51:56 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "ft_shadow.h"

// 그림자
bool	ft_shadow(t_scene *scene, t_vec3 *coord, t_intersection *intersection_obj)
{
	t_intersection	intersection;
	t_vec3 			ray_point;
	double			dist;
	t_vec3			axis;
	int				i;

	i = 0;
	axis = ft_vec3_sub(intersection_obj->hit_coord, *coord);
	dist = sqrt(ft_vec3_dot(axis, axis)) - 0.000001;
	ray_point = ft_vec3_normalize(axis);
	while (i < scene->obj_list->max_index)
	{
		if (ft_scn_obj_intersection(scene->obj_list->rt[i], coord, &ray_point, &intersection))
		{
			intersection.obj = scene->obj_list->rt[i];
			if (intersection.dist <= dist)
			{
				return (true);
			}
			else if (intersection_obj->obj == intersection.obj)
			{
				if (intersection.inside != intersection_obj->inside)
					return (true);
			}
		}
		i++;
	}
	return (false);
}
