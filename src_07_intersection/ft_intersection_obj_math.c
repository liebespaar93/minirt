/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intersection_obj_math.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 06:26:55 by kyoulee           #+#    #+#             */
/*   Updated: 2023/02/17 08:50:28 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "ft_intersection.h"

bool	ft_intersection_obj_math_circle(
	t_vec3 coord, t_vec3 ray_point, double radius, double (*t)[2])
{
	double	a;
	double	b;
	double	c;
	double	q;

	a = ft_vec3_dot(ray_point, ray_point);
	b = 2.0 * ft_vec3_dot(coord, ray_point);
	c = ft_vec3_dot(coord, coord) - (radius * radius);
	q = (b * b) - (4.0 * a * c);
	if (q <= 0.0)
		return (false);
	q = sqrt(q);
	(*t)[0] = (-b - q) / (2.0 * a);
	(*t)[1] = (-b + q) / (2.0 * a);
	return (true);
}
