/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quaternion_euler.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 01:46:28 by kyoulee           #+#    #+#             */
/*   Updated: 2023/02/18 02:46:14 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "ft_quaternion.h"

/**
 * @brief 
 * 
 * @param v3
 * @ref https://en.wikipedia.org/wiki/
 * 	Conversion_between_quaternions_and_Euler_angles
 * @return t_quaternion
 */
t_quaternion	ft_quaternion_from_euler_angles(t_vec3 angles)
{
	t_quaternion	q;
	t_vec3			c;
	t_vec3			s;

	c.x = cos(angles.x * 0.5);
	s.x = sin(angles.x * 0.5);
	c.y = cos(angles.y * 0.5);
	s.y = sin(angles.y * 0.5);
	c.z = cos(angles.z * 0.5);
	s.z = sin(angles.z * 0.5);
	q.w = c.x * c.y * c.z + s.x * s.y * s.z;
	q.x = s.x * c.y * c.z - c.x * s.y * s.z;
	q.y = c.x * s.y * c.z + s.x * c.y * s.z;
	q.z = c.x * c.y * s.z - s.x * s.y * c.z;
	return (q);
}

/**
 * @brief 
 * 
 * @param q 
 * @ref https://en.wikipedia.org/
 * 	wiki/Conversion_between_quaternions_and_Euler_angles
 * @ref	https://stackoverflow.com/
 * 	questions/5782658/extracting-yaw-from-a-quaternion
 * @return t_vec3 
 */
t_vec3	ft_quaternion_to_euler_angles(t_quaternion q)
{
	t_vec3	angles;
	t_vec3	c;
	t_vec3	s;

	s.x = 2.0 * (q.w * q.x + q.y * q.z);
	c.x = 1.0 - 2.0 * (q.x * q.x + q.y * q.y);
	angles.x = atan2(s.x, c.x);
	s.y = sqrt(1.0 + 2.0 * (q.w * q.y - q.x * q.z));
	c.y = sqrt(1.0 - 2.0 * (q.w * q.y - q.x * q.z));
	angles.y = 2.0 * atan2(s.y, c.y) - M_PI / 2;
	s.z = 2.0 * (q.w * q.z + q.x * q.y);
	c.z = 1.0 - 2.0 * (q.y * q.y + q.z * q.z);
	angles.z = atan2(s.z, c.z);
	return (angles);
}
