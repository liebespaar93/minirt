/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intersection_light.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 14:22:35 by kyoulee           #+#    #+#             */
/*   Updated: 2023/02/04 19:30:17 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <math.h>

#include "ft_intersection.h"

#include <stdio.h>

bool	ft_light_light_intersection(t_L *light, t_C *camera, const t_vec3 *ray_point, t_vec3 *light_color, t_intersection *intersection)
{
	(void)camera;
	t_vec3	r = ft_vec3_add(*ray_point, 
		ft_vec3_mult(intersection->hit_axis, 
				2 * ft_vec3_dot(ft_vec3_mult(*ray_point, -1) ,intersection->hit_axis)
			)
		);  //빈시긱 R = P +  2n(-P·n)
	t_vec3 light_axis = ft_vec3_normalize(ft_vec3_sub(intersection->hit_point, light->coord));
	
	double angle = acos(ft_vec3_dot(ft_vec3_mult(light_axis, -1), r));
	
	if (angle < M_PI / 2)
	{
		*light_color = ft_vec3_mult(
			ft_vector_3(
				intersection->color.x * (light->color.bit.r / 255),
				intersection->color.y * (light->color.bit.g / 255), 
				intersection->color.z * (light->color.bit.b / 255)), 
				light->ratio *(1.0 - (angle / (M_PI/ 2))));
		return (true);
	}
	return (false);
}

bool	ft_scn_light_intersection(t_rt *light, t_C *camera, const t_vec3 *ray_point, t_vec3 *light_color, t_intersection *intersection)
{
	bool	result;

	result = false;
	// if (!ft_strcmp(obj->type, "A"))
	// 	result = ft_obj_plane_intersection((t_pl *)obj, camera, ray_point, intersection);
	if (!ft_strcmp(light->type, "L"))
		result = ft_light_light_intersection((t_L *)light, camera, ray_point, light_color, intersection);
	return (result);
}

bool	ft_light_intersection(t_scene *scene, const t_vec3 *ray_point, t_intersection *intersection)
{
	bool			intersection_found;
	t_vec3			light_color;
	t_vec3			all_color;
	int				light_count;
	int i;

	intersection_found = false;
	light_count = 0;
	i = 0;
	all_color = ft_vector_3(0.0, 0.0, 0.0);
	while (i < scene->light_list->max_index)
	{
		light_color = ft_vector_3(0.0, 0.0, 0.0);
		if (ft_scn_light_intersection(scene->light_list->rt[i], scene->camera_list->camera, ray_point, &light_color, intersection))
		{
			all_color = ft_vec3_add(all_color, light_color);
		if (all_color.x > 1.0)
			all_color.x = 1.0;
		if (all_color.y > 1.0)
			all_color.y = 1.0;
		if (all_color.z > 1.0)
			all_color.z = 1.0;
			light_count++;
		}
		i++;
	}
	intersection->color = all_color;
	return (intersection_found);
}