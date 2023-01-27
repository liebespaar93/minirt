/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_3_operator.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 00:18:18 by kyoulee           #+#    #+#             */
/*   Updated: 2023/01/13 11:53:03 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "ft_vector.h"

t_vec3	ft_vec3_add(t_vec3 v3_1, t_vec3 v3_2)
{
	v3_1.x += v3_2.x;
	v3_1.y += v3_2.y;
	v3_1.z += v3_2.z;
	return (v3_1);
}

t_vec3	ft_vec3_sub(t_vec3 v3_1, t_vec3 v3_2)
{
	v3_1.x -= v3_2.x;
	v3_1.y -= v3_2.y;
	v3_1.z -= v3_2.z;
	return (v3_1);
}

t_vec3	ft_vec3_mult(t_vec3 v3, double scalar)
{
	v3.x *= scalar;
	v3.y *= scalar;
	v3.z *= scalar;
	return (v3);
}

t_vec3	ft_vec3_cross(t_vec3 v3_1, t_vec3 v3_2)
{
	t_vec3	v3;

	v3.x = (v3_1.y * v3_2.z) - (v3_1.z * v3_2.y);
	v3.y = -((v3_1.x * v3_2.z) - (v3_1.z * v3_2.x));
	v3.z = (v3_1.x * v3_2.y) - (v3_1.y * v3_2.x);
	return (v3);
}

double	ft_vec3_dot(t_vec3 v3_1, t_vec3 v3_2)
{
	double	result;
	
	result = v3_1.x * v3_2.x + v3_1.y * v3_2.y + v3_1.z * v3_2.z;
	return (result);
}