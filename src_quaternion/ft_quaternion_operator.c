/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quaternion_operator.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 01:49:53 by kyoulee           #+#    #+#             */
/*   Updated: 2023/02/18 01:56:47 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_quaternion.h"

/**
 * @brief 4x4
 * 
 * @param q1 
 * @param q2 
 * @ref https://en.wikipedia.org/wiki/Quaternion
 * @ref https://jjycjnmath.tistory.com/245
 * @return t_quaternion 
 */
t_quaternion	ft_quaternion_multiply(t_quaternion q1, t_quaternion q2)
{
	t_quaternion	result;

	result.w = q1.w * q2.w - q1.x * q2.x - q1.y * q2.y - q1.z * q2.z;
	result.x = q1.w * q2.x + q1.x * q2.w + q1.y * q2.z - q1.z * q2.y;
	result.y = q1.w * q2.y - q1.x * q2.z + q1.y * q2.w + q1.z * q2.x;
	result.z = q1.w * q2.z + q1.x * q2.y - q1.y * q2.x + q1.z * q2.w;
	return (result);
}
