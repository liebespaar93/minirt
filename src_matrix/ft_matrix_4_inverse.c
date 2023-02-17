/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix_4_inverse.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 16:05:53 by kyoulee           #+#    #+#             */
/*   Updated: 2023/02/18 02:40:57 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_matrix.h"

void	ft_mtx4_inverse_m1(t_mtx4 m, t_mtx4 *new, double det)
{
	new->m11 = det * (m.m22 * (m.m33 * m.m44 - m.m34 * m.m43) - m.m23 * \
	(m.m32 * m.m44 - m.m34 * m.m42) + m.m24 * (m.m32 * m.m43 - m.m33 * m.m42));
	new->m13 = det * (m.m12 * (m.m23 * m.m44 - m.m24 * m.m43) - m.m13 * \
	(m.m22 * m.m44 - m.m24 * m.m42) + m.m14 * (m.m22 * m.m43 - m.m23 * m.m42));
	new->m12 = det * - (m.m12 * (m.m33 * m.m44 - m.m34 * m.m43) - m.m13 * \
	(m.m32 * m.m44 - m.m34 * m.m42) + m.m14 * (m.m32 * m.m43 - m.m33 * m.m42));
	new->m14 = det * - (m.m12 * (m.m23 * m.m34 - m.m24 * m.m33) - m.m13 * \
	(m.m22 * m.m34 - m.m24 * m.m32) + m.m14 * (m.m22 * m.m33 - m.m23 * m.m32));
}

void	ft_mtx4_inverse_m2(t_mtx4 m, t_mtx4 *new, double det)
{
	new->m21 = det * - (m.m21 * (m.m33 * m.m44 - m.m34 * m.m43) - m.m23 * \
	(m.m31 * m.m44 - m.m34 * m.m41) + m.m24 * (m.m31 * m.m43 - m.m33 * m.m41));
	new->m22 = det * (m.m11 * (m.m33 * m.m44 - m.m34 * m.m43) - m.m13 * \
	(m.m31 * m.m44 - m.m34 * m.m41) + m.m14 * (m.m31 * m.m43 - m.m33 * m.m41));
	new->m23 = det * - (m.m11 * (m.m23 * m.m44 - m.m24 * m.m43) - m.m13 * \
	(m.m21 * m.m44 - m.m24 * m.m41) + m.m14 * (m.m21 * m.m43 - m.m23 * m.m41));
	new->m24 = det * (m.m11 * (m.m23 * m.m34 - m.m24 * m.m33) - m.m13 * \
	(m.m21 * m.m34 - m.m24 * m.m31) + m.m14 * (m.m21 * m.m33 - m.m23 * m.m31));
}

void	ft_mtx4_inverse_m3(t_mtx4 m, t_mtx4 *new, double det)
{
	new->m31 = det * (m.m21 * (m.m32 * m.m44 - m.m34 * m.m42) - m.m22 * \
	(m.m31 * m.m44 - m.m34 * m.m41) + m.m24 * (m.m31 * m.m42 - m.m32 * m.m41));
	new->m32 = det * - (m.m11 * (m.m32 * m.m44 - m.m34 * m.m42) - m.m12 * \
	(m.m31 * m.m44 - m.m34 * m.m41) + m.m14 * (m.m31 * m.m42 - m.m32 * m.m41));
	new->m33 = det * (m.m11 * (m.m22 * m.m44 - m.m24 * m.m42) - m.m12 * \
	(m.m21 * m.m44 - m.m24 * m.m41) + m.m14 * (m.m21 * m.m42 - m.m22 * m.m41));
	new->m34 = det * - (m.m11 * (m.m22 * m.m34 - m.m24 * m.m32) - m.m12 * \
	(m.m21 * m.m34 - m.m24 * m.m31) + m.m14 * (m.m21 * m.m32 - m.m22 * m.m31));
}

void	ft_mtx4_inverse_m4(t_mtx4 m, t_mtx4 *new, double det)
{
	new->m41 = det * - (m.m21 * (m.m32 * m.m43 - m.m33 * m.m42) - m.m22 * \
	(m.m31 * m.m43 - m.m33 * m.m41) + m.m23 * (m.m31 * m.m42 - m.m32 * m.m41));
	new->m42 = det * (m.m11 * (m.m32 * m.m43 - m.m33 * m.m42) - m.m12 * \
	(m.m31 * m.m43 - m.m33 * m.m41) + m.m13 * (m.m31 * m.m42 - m.m32 * m.m41));
	new->m43 = det * - (m.m11 * (m.m22 * m.m43 - m.m23 * m.m42) - m.m12 * \
	(m.m21 * m.m43 - m.m23 * m.m41) + m.m13 * (m.m21 * m.m42 - m.m22 * m.m41));
	new->m44 = det * (m.m11 * (m.m22 * m.m33 - m.m23 * m.m32) - m.m12 * \
	(m.m21 * m.m33 - m.m23 * m.m31) + m.m13 * (m.m21 * m.m32 - m.m22 * m.m31));
}

t_mtx4	ft_mtx4_inverse(t_mtx4 m4)
{
	t_mtx4	new;
	double	det;
	t_mtx4	m;

	m = m4;
	det = m.m11 * (m.m22 * (m.m33 * m.m44 - m.m34 * m.m43) - m.m23 * \
	(m.m32 * m.m44 - m.m34 * m.m42) + m.m24 * (m.m32 * m.m43 - m.m33 * m.m42)) \
	- m.m12 * (m.m21 * (m.m33 * m.m44 - m.m34 * m.m43) - m.m23 * \
	(m.m31 * m.m44 - m.m34 * m.m41) + m.m24 * (m.m31 * m.m43 - m.m33 * m.m41)) \
	+ m.m13 * (m.m21 * (m.m32 * m.m44 - m.m34 * m.m42) - m.m22 * \
	(m.m31 * m.m44 - m.m34 * m.m41) + m.m24 * (m.m31 * m.m42 - m.m32 * m.m41)) \
	- m.m14 * (m.m21 * (m.m32 * m.m43 - m.m33 * m.m42) - m.m22 * \
	(m.m31 * m.m43 - m.m33 * m.m41) + m.m23 * (m.m31 * m.m42 - m.m32 * m.m41));
	det = 1 / det;
	ft_mtx4_inverse_m1(m, &new, det);
	ft_mtx4_inverse_m2(m, &new, det);
	ft_mtx4_inverse_m3(m, &new, det);
	ft_mtx4_inverse_m4(m, &new, det);
	return (new);
}
