/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intersection_light.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 14:22:35 by kyoulee           #+#    #+#             */
/*   Updated: 2023/02/17 09:03:20 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "ft_intersection.h"
#include "ft_shadow.h"

bool	ft_scn_light_intersection(
	t_scene *scene, t_rt *light, t_vec3 *light_color, \
	t_intersection *ip)
{
	if (!ft_strcmp(light->type, "A"))
		return (ft_intersection_light_ambient(\
			scene, (t_A *)light->data, light_color, ip));
	else if (!ft_strcmp(light->type, "L"))
		return (ft_intersection_light_light(\
			scene, (t_L *)light->data, light_color, ip));
	return (false);
}

t_vec3	ft_color_set(t_vec3 all_color)
{
	t_vec3	new_color;

	new_color = all_color;
	if (all_color.x > 1.0)
		new_color.x = 1.0;
	if (all_color.y > 1.0)
		new_color.y = 1.0;
	if (all_color.z > 1.0)
		new_color.z = 1.0;
	return (new_color);
}

bool	ft_intersection_light(
	t_scene *scene, t_vec3 *ray_point, t_intersection *ip)
{
	t_vec3	light_color;
	t_vec3	all_color;
	int		light_count;
	int		i;

	(void)ray_point;
	light_count = 0;
	i = 0;
	all_color = ft_vector_3(0.0, 0.0, 0.0);
	while (i < scene->light_list->max_index)
	{
		light_color = ft_vector_3(0.0, 0.0, 0.0);
		if (ft_scn_light_intersection(\
			scene, scene->light_list->rt[i], &light_color, ip))
		{
			all_color = ft_vec3_add(all_color, light_color);
			light_count = light_count + 1;
		}
		i++;
	}
	ip->color = ft_color_set(all_color);
	return (true);
}
