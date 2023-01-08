/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix_4_mult.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 07:16:40 by kyoulee           #+#    #+#             */
/*   Updated: 2023/01/04 17:09:25 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_matrix.h"

t_mtx4	ft_mtx4_mult_scalar(t_mtx4 m4, double scalar)
{
	m4.m11 *= scalar;
	m4.m12 *= scalar;
	m4.m13 *= scalar;
	m4.m14 *= scalar;
	m4.m21 *= scalar;
	m4.m22 *= scalar;
	m4.m23 *= scalar;
	m4.m24 *= scalar;
	m4.m31 *= scalar;
	m4.m32 *= scalar;
	m4.m33 *= scalar;
	m4.m34 *= scalar;
	return (m4);
}

t_vec3	ft_vec3_mult_mtx4(t_vec3 v3, t_mtx4 m4)
{
	t_vec3	temp;
	double	w;

	temp.x = v3.x * m4.m11 + v3.y * m4.m21 + v3.z * m4.m31 + m4.m41;
	temp.y = v3.x * m4.m12 + v3.y * m4.m22 + v3.z * m4.m32 + m4.m42;
	temp.z = v3.x * m4.m13 + v3.y * m4.m23 + v3.z * m4.m33 + m4.m43;
	w = v3.x * m4.m14 + v3.y * m4.m24 + v3.z * m4.m34 + m4.m44;
	temp.x /= w;
	temp.y /= w;
	temp.z /= w;
	return (temp);
}

t_vec3	ft_mtx4_mult_vec3(t_mtx4 m4, t_vec3 v3)
{
	t_vec3	temp;
	double	w;

	temp.x = v3.x * m4.m11 + v3.y * m4.m12 + v3.z * m4.m13 + m4.m14;
	temp.y = v3.x * m4.m21 + v3.y * m4.m22 + v3.z * m4.m23 + m4.m24;
	temp.z = v3.x * m4.m31 + v3.y * m4.m32 + v3.z * m4.m33 + m4.m34;
	w = v3.x * m4.m41 + v3.y * m4.m42 + v3.z * m4.m43 + m4.m44;
	temp.x /= w;
	temp.y /= w;
	temp.z /= w;
	return (temp);
}

double	ft_mtx4_row_mult_mtx4_col(t_mtx4 m4_1, t_mtx4 m4_2, int row, int col)
{
	double	sum;

	sum = *(&m4_1.m11 + row * 4) * *(&m4_2.m11 + col) + \
		*(&m4_1.m11 + row * 4 + 1) * *(&m4_2.m11 + col + 4 * 1) + \
		*(&m4_1.m11 + row * 4 + 2) * *(&m4_2.m11 + col + 4 * 2) + \
		*(&m4_1.m11 + row * 4 + 3) * *(&m4_2.m11 + col + 4 * 3);
	return (sum);
}

t_mtx4	ft_mtx4_mult_mtx4(t_mtx4 m4_1, t_mtx4 m4_2)
{
	t_mtx4	new;

	new.m11 = ft_mtx4_row_mult_mtx4_col(m4_1, m4_2, 0, 0);
	new.m12 = ft_mtx4_row_mult_mtx4_col(m4_1, m4_2, 0, 1);
	new.m13 = ft_mtx4_row_mult_mtx4_col(m4_1, m4_2, 0, 2);
	new.m14 = ft_mtx4_row_mult_mtx4_col(m4_1, m4_2, 0, 3);
	new.m21 = ft_mtx4_row_mult_mtx4_col(m4_1, m4_2, 1, 0);
	new.m22 = ft_mtx4_row_mult_mtx4_col(m4_1, m4_2, 1, 1);
	new.m23 = ft_mtx4_row_mult_mtx4_col(m4_1, m4_2, 1, 2);
	new.m24 = ft_mtx4_row_mult_mtx4_col(m4_1, m4_2, 1, 3);
	new.m31 = ft_mtx4_row_mult_mtx4_col(m4_1, m4_2, 2, 0);
	new.m32 = ft_mtx4_row_mult_mtx4_col(m4_1, m4_2, 2, 1);
	new.m33 = ft_mtx4_row_mult_mtx4_col(m4_1, m4_2, 2, 2);
	new.m34 = ft_mtx4_row_mult_mtx4_col(m4_1, m4_2, 2, 3);
	new.m41 = ft_mtx4_row_mult_mtx4_col(m4_1, m4_2, 3, 0);
	new.m42 = ft_mtx4_row_mult_mtx4_col(m4_1, m4_2, 3, 1);
	new.m43 = ft_mtx4_row_mult_mtx4_col(m4_1, m4_2, 3, 2);
	new.m44 = ft_mtx4_row_mult_mtx4_col(m4_1, m4_2, 3, 3);
	return (new);
}
