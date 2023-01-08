/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 00:18:18 by kyoulee           #+#    #+#             */
/*   Updated: 2023/01/04 17:13:56 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "ft_vector.h"

t_vec3	ft_vector_3(double x, double y, double z)
{
	t_vec3	new;

	new.x = x;
	new.y = y;
	new.z = z;
	return (new);
}

t_vec3	ft_vec3_sum(t_vec3 v3_1, t_vec3 v3_2)
{
	v3_1.x += v3_2.x;
	v3_1.y += v3_2.y;
	v3_1.z += v3_2.z;
	return (v3_1);
}

t_vec3	ft_vec3_mult(t_vec3 v3, double scalar)
{
	v3.x *= scalar;
	v3.y *= scalar;
	v3.z *= scalar;
	return (v3);
}

double	ft_vec3_length(t_vec3 v3)
{
	double	temp;

	temp = sqrt(v3.x * v3.x + v3.y * v3.y + v3.z * v3.z);
	return (temp);
}

t_vec3	ft_vec3_normalize(t_vec3 v3)
{
	double	length;

	length = ft_vec3_length(v3);
	v3.x = v3.x / length;
	v3.y = v3.y / length;
	v3.z = v3.z / length;
	return (v3);
}
