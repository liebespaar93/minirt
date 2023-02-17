/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intersection_light_ambient.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 08:35:50 by kyoulee           #+#    #+#             */
/*   Updated: 2023/02/17 08:43:50 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "ft_intersection.h"

bool	ft_intersection_light_ambient(
	t_scene *scene, t_A *light, t_vec3 *light_color, t_intersection *ip)
{
	(void)scene;
	*light_color = ft_vec3_mult(\
		ft_vector_3(\
			ip->color.x * light->color.x, \
			ip->color.y * light->color.y, \
			ip->color.z * light->color.z), \
			light->ratio);
	return (true);
}
