/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intersection_light.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 14:22:35 by kyoulee           #+#    #+#             */
/*   Updated: 2023/02/02 17:01:09 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <math.h>

#include "ft_intersection.h"

#include <stdio.h>

// bool	ft_light_light_intersection(t_L *light, t_C *camera, const t_vec3 *ray_point, t_intersection *intersection)
// {
// 	t_vec3 light_axis = ft_vec3_normalize(ft_vec3_sub(camera->coord, light->coord));
	
// 	double angle = acos(ft_vec3_dot(*ray_point, light_axis));

// 	if (angle < M_PI / 2)
// 	{
// 		intersection->color = ft_vec3_mult(ft_vector_3(light->color.bit.r / 255, light->color.bit.g / 255, light->color.bit.b / 255), light->ratio);

// 	}
// }

// bool	ft_scn_light_intersection(t_rt *light, t_C *camera, const t_vec3 *ray_point, t_intersection *intersection)
// {
// 	bool	result;

// 	result = false;
// 	// if (!ft_strcmp(obj->type, "pl"))
// 	// 	result = ft_obj_plane_intersection((t_pl *)obj, camera, ray_point, intersection);
// 	if (!ft_strcmp(light->type, "L"))
// 		result = ft_light_light_intersection((t_L *)light, camera, ray_point, intersection);
// 	return (result);
// }

// bool	ft_light_intersection(t_scene *scene, const t_vec3 *ray_point, t_intersection *result_intersection)
// {
// 	t_intersection	intersection;
// 	bool			intersection_found;
// 	int i;

// 	intersection_found = false;
// 	i = 0;
// 	while (i < scene->light_list->max_index)
// 	{
// 		ft_memset(&intersection, 0, sizeof(t_intersection));
// 		if (ft_scn_light_intersection(scene->light_list->rt[i], scene->camera_list->camera, ray_point, &intersection))
// 		{

// 		}
// 		i++;
// 	}
// 	return (intersection_found);
// }