/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intersection_light_math.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 08:46:25 by kyoulee           #+#    #+#             */
/*   Updated: 2023/02/18 02:18:04 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "ft_intersection.h"

/**
 * @brief 
 * 
 * @param ray_point 
 * @param hit_point 
 * @note R = P +  2n(-P·n)
 * @return t_vec3 
 */
t_vec3	ft_intersection_light_math_incidence(\
	const t_vec3 ray_point, const t_vec3 hit_point)
{
	return (ft_vec3_add(ray_point, \
			ft_vec3_mult(hit_point, 2.0 * ft_vec3_dot(\
				ft_vec3_mult(ray_point, -1.0), hit_point))));
}

/**
 * @brief 
 * 
 * @param light_point 
 * @param hit_point 
 * @return double 
 * @ref https://darkpgmr.tistory.com/121
 */
double	ft_intersection_light_math_diffuse_reflection(
	const t_vec3 *light_point, const t_vec3 *hit_point)
{
	t_vec3	reflection;

	reflection = ft_intersection_light_math_incidence(\
		ft_vec3_mult(*light_point, -1.0), *hit_point);
	return (acos(ft_vec3_dot(*light_point, reflection)));
}

double	ft_intersection_light_math_specular_reflection(
	const t_vec3 *ray_point, const t_vec3 *light_point, \
	const t_vec3 *hit_point)
{
	t_vec3	reflection;

	reflection = ft_intersection_light_math_incidence(\
		*ray_point, *hit_point);
	return (acos(ft_vec3_dot(*light_point, reflection)));
}
