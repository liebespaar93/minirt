/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quaternion_matrix.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 01:49:25 by kyoulee           #+#    #+#             */
/*   Updated: 2023/02/18 02:26:53 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "ft_quaternion.h"

double	ft_epsilon(double d)
{
	if (fabs(d) < 0.00001)
		return (0.0);
	return (d);
}

/**
 * @brief 
 * 
 * @param q 
 * @ref https://en.wikipedia.org/wiki/
 * 	Quaternions_and_spatial_rotation
 * @ref https://en.wikipedia.org/wiki/
 * 	Rotation_matrix
 * @ref https://automaticaddison.com/
 * 	how-to-convert-a-quaternion-to-a-rotation-matrix/
 * @return t_mtx3
 */
t_mtx3	ft_quaternion_rotate_matrix(t_quaternion q)
{
	t_mtx3	m3;

	m3 = ft_matrix_3(\
		(double [3]){\
			ft_epsilon(1.0 - 2.0 * q.y * q.y - 2.0 * q.z * q.z), \
			2.0 * q.x * q.y - 2.0 * q.z * q.w, \
			2.0 * q.x * q.z + 2.0 * q.y * q.w}, \
		(double [3]){\
			2.0 * q.x * q.y + 2.0 * q.z * q.w, \
			ft_epsilon(1.0 - 2.0 * q.x * q.x - 2.0 * q.z * q.z), \
			2.0 * q.y * q.z - 2.0 * q.x * q.w}, \
		(double [3]){\
			2.0 * q.x * q.z - 2.0 * q.y * q.w, \
			2.0 * q.y * q.z + 2.0 * q.x * q.w, \
			ft_epsilon(1.0 - 2.0 * q.x * q.x - 2.0 * q.y * q.y) \
		} \
	);
	return (m3);
}

t_vec3	ft_quaternion_rotate_vec3(t_quaternion q, t_vec3 v3)
{
	t_vec3	result;
	t_mtx3	m3;

	m3 = ft_quaternion_rotate_matrix(q);
	result = ft_mtx3_mult_vec3(m3, v3);
	return (result);
}
