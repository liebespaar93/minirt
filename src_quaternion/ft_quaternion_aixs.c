/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quaternion_aixs.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 01:47:15 by kyoulee           #+#    #+#             */
/*   Updated: 2023/02/18 01:54:55 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "ft_quaternion.h"

/**
 * @brief 
 * 
 * @param t_vec3 
 * @param angle 
 * @ref http://www.euclideanspace.com/
 * 	maths/geometry/rotations/conversions/angleToQuaternion/
 * @return t_quaternion 
 */
t_quaternion	ft_quaternion_axis_from_angle(t_vec3 axis, double angle)
{
	t_quaternion	q;
	double			s;

	s = sin(angle * 0.5);
	q.x = axis.x * s;
	q.y = axis.y * s;
	q.z = axis.z * s;
	q.w = cos(angle * 0.5);
	return (q);
}

/**
 * @brief 
 * 
 * @param q 
 * @ref http://www.euclideanspace.com/maths/
 * 	geometry/rotations/conversions/quaternionToAngle/
 * @return t_vec3 
 */
t_vec3	ft_quaternion_axis_to_angles(t_quaternion q, double *angle)
{
	t_vec3	axis;
	double	divider;

	if (q.w > 1.0)
		q = ft_quaternion_normalize(q);
	if (angle)
		*angle = 2.0 * acos(q.w);
	divider = sqrt(1.0 - q.w * q.w);
	if (divider < 0.001)
	{
		axis.x = q.x;
		axis.y = q.y;
		axis.z = q.z;
	}
	else
	{
		axis.x = q.x / divider;
		axis.y = q.y / divider;
		axis.z = q.z / divider;
	}
	return (axis);
}
