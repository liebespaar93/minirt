/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quaternion_roration.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 01:51:37 by kyoulee           #+#    #+#             */
/*   Updated: 2023/02/18 01:56:31 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_quaternion.h"

t_quaternion	ft_quaternion_rotation_x(double angle)
{
	t_vec3	axis;

	axis.x = 1.0;
	axis.y = 0.0;
	axis.z = 0.0;
	return (ft_quaternion_axis_from_angle(axis, angle));
}

t_quaternion	ft_quaternion_rotation_y(double angle)
{
	t_vec3	axis;

	axis.x = 0.0;
	axis.y = 1.0;
	axis.z = 0.0;
	return (ft_quaternion_axis_from_angle(axis, angle));
}

t_quaternion	ft_quaternion_rotation_z(double angle)
{
	t_vec3	axis;

	axis.x = 0.0;
	axis.y = 0.0;
	axis.z = 1.0;
	return (ft_quaternion_axis_from_angle(axis, angle));
}

t_quaternion	ft_quaternion_rotation_xyz(t_vec3 angle)
{
	t_quaternion	q;

	q = ft_quaternion_identity();
	q = ft_quaternion_multiply(q, ft_quaternion_rotation_z(angle.z));
	q = ft_quaternion_multiply(q, ft_quaternion_rotation_y(angle.y));
	q = ft_quaternion_multiply(q, ft_quaternion_rotation_x(angle.x));
	return (q);
}
