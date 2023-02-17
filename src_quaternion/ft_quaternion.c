/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quaternion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 16:37:16 by kyoulee           #+#    #+#             */
/*   Updated: 2023/02/18 01:55:05 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "ft_quaternion.h"

// https://cs.stanford.edu/~acoates/
t_quaternion	ft_quaternion_set(double x, double y, double z, double w)
{
	t_quaternion	q;

	q.x = x;
	q.y = y;
	q.z = z;
	q.w = w;
	return (q);
}

t_quaternion	ft_quaternion_identity(void)
{
	return (ft_quaternion_set(0.0, 0.0, 0.0, 1.0));
}

t_quaternion	ft_quaternion_conjugate(t_quaternion q)
{
	q.x = -q.x;
	q.y = -q.y;
	q.z = -q.z;
	q.w = q.w;
	return (q);
}

double	ft_quaternion_norm(t_quaternion q)
{
	return (sqrt(q.x * q.x + q.y * q.y + q.z * q.z + q.w * q.w));
}

t_quaternion	ft_quaternion_normalize(t_quaternion q)
{
	double	len;

	len = ft_quaternion_norm(q);
	q.x = q.x / len;
	q.y = q.y / len;
	q.z = q.z / len;
	q.w = q.w / len;
	return (q);
}
