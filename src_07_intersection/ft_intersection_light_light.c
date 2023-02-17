/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intersection_light_light.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 08:42:07 by kyoulee           #+#    #+#             */
/*   Updated: 2023/02/17 08:54:22 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "ft_intersection.h"
#include "ft_shadow.h"

bool	ft_intersection_light_light(
	t_scene *scene, t_L *light, t_vec3 *light_color, t_intersection *ip)
{
	double	angle;
	t_vec3	light_point;

	light_point = ft_vec3_normalize(ft_vec3_sub(light->coord, ip->hit_coord));
	if (1)
		angle = ft_intersection_light_math_diffuse_reflection(\
			&light_point, &ip->hit_point);
	if (angle < M_PI)
	{
		if (ft_shadow(scene, &light->coord, ip))
			return (false);
		*light_color = ft_vec3_mult(\
			ft_vector_3(\
				ip->color.x * light->color.x, \
				ip->color.y * light->color.y, \
				ip->color.z * light->color.z), \
				light->ratio * (1.0 - angle / (M_PI)));
		return (true);
	}
	return (false);
}
