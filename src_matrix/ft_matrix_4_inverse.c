/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix_4_inverse.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 16:05:53 by kyoulee           #+#    #+#             */
/*   Updated: 2023/02/17 03:15:17 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_matrix.h"


t_mtx4	ft_mtx4_inverse(t_mtx4 m4)
{
	t_mtx4	new;
	double	det;
	t_mtx4 m;

	m = m4;
	det = m.m11 * ( m.m22 * (m.m33 * m.m44 - m.m34 * m.m43) - m.m23 * (m.m32 * m.m44 - m.m34 * m.m42) + m.m24 * (m.m32 * m.m43 - m.m33 * m.m42) ) \
		- m.m12 * ( m.m21 * (m.m33 * m.m44 - m.m34 * m.m43) - m.m23 * (m.m31 * m.m44 - m.m34 * m.m41) + m.m24 * (m.m31 * m.m43 - m.m33 * m.m41) ) \
		+ m.m13 * ( m.m21 * (m.m32 * m.m44 - m.m34 * m.m42) - m.m22 * (m.m31 * m.m44 - m.m34 * m.m41) + m.m24 * (m.m31 * m.m42 - m.m32 * m.m41) ) \
		- m.m14 * ( m.m21 * (m.m32 * m.m43 - m.m33 * m.m42) - m.m22 * (m.m31 * m.m43 - m.m33 * m.m41) + m.m23 * (m.m31 * m.m42 - m.m32 * m.m41) );
	det = 1 / det;

	new.m11 = det *   ( m.m22 * (m.m33 * m.m44 - m.m34 * m.m43) - m.m23 * (m.m32 * m.m44 - m.m34 * m.m42) + m.m24 * (m.m32 * m.m43 - m.m33 * m.m42) );
	new.m12 = det * - ( m.m12 * (m.m33 * m.m44 - m.m34 * m.m43) - m.m13 * (m.m32 * m.m44 - m.m34 * m.m42) + m.m14 * (m.m32 * m.m43 - m.m33 * m.m42) );
	new.m13 = det *   ( m.m12 * (m.m23 * m.m44 - m.m24 * m.m43) - m.m13 * (m.m22 * m.m44 - m.m24 * m.m42) + m.m14 * (m.m22 * m.m43 - m.m23 * m.m42) );
	new.m14 = det * - ( m.m12 * (m.m23 * m.m34 - m.m24 * m.m33) - m.m13 * (m.m22 * m.m34 - m.m24 * m.m32) + m.m14 * (m.m22 * m.m33 - m.m23 * m.m32) );

	new.m21 = det * - ( m.m21 * (m.m33 * m.m44 - m.m34 * m.m43) - m.m23 * (m.m31 * m.m44 - m.m34 * m.m41) + m.m24 * (m.m31 * m.m43 - m.m33 * m.m41) );
	new.m22 = det *   ( m.m11 * (m.m33 * m.m44 - m.m34 * m.m43) - m.m13 * (m.m31 * m.m44 - m.m34 * m.m41) + m.m14 * (m.m31 * m.m43 - m.m33 * m.m41) );
	new.m23 = det * - ( m.m11 * (m.m23 * m.m44 - m.m24 * m.m43) - m.m13 * (m.m21 * m.m44 - m.m24 * m.m41) + m.m14 * (m.m21 * m.m43 - m.m23 * m.m41) );
	new.m24 = det *   ( m.m11 * (m.m23 * m.m34 - m.m24 * m.m33) - m.m13 * (m.m21 * m.m34 - m.m24 * m.m31) + m.m14 * (m.m21 * m.m33 - m.m23 * m.m31) );

	new.m31 = det *   ( m.m21 * (m.m32 * m.m44 - m.m34 * m.m42) - m.m22 * (m.m31 * m.m44 - m.m34 * m.m41) + m.m24 * (m.m31 * m.m42 - m.m32 * m.m41) );
	new.m32 = det * - ( m.m11 * (m.m32 * m.m44 - m.m34 * m.m42) - m.m12 * (m.m31 * m.m44 - m.m34 * m.m41) + m.m14 * (m.m31 * m.m42 - m.m32 * m.m41) );
	new.m33 = det *   ( m.m11 * (m.m22 * m.m44 - m.m24 * m.m42) - m.m12 * (m.m21 * m.m44 - m.m24 * m.m41) + m.m14 * (m.m21 * m.m42 - m.m22 * m.m41) );
	new.m34 = det * - ( m.m11 * (m.m22 * m.m34 - m.m24 * m.m32) - m.m12 * (m.m21 * m.m34 - m.m24 * m.m31) + m.m14 * (m.m21 * m.m32 - m.m22 * m.m31) );

	new.m41 = det * - ( m.m21 * (m.m32 * m.m43 - m.m33 * m.m42) - m.m22 * (m.m31 * m.m43 - m.m33 * m.m41) + m.m23 * (m.m31 * m.m42 - m.m32 * m.m41) );
	new.m42 = det *   ( m.m11 * (m.m32 * m.m43 - m.m33 * m.m42) - m.m12 * (m.m31 * m.m43 - m.m33 * m.m41) + m.m13 * (m.m31 * m.m42 - m.m32 * m.m41) );
	new.m43 = det * - ( m.m11 * (m.m22 * m.m43 - m.m23 * m.m42) - m.m12 * (m.m21 * m.m43 - m.m23 * m.m41) + m.m13 * (m.m21 * m.m42 - m.m22 * m.m41) );
	new.m44 = det *   ( m.m11 * (m.m22 * m.m33 - m.m23 * m.m32) - m.m12 * (m.m21 * m.m33 - m.m23 * m.m31) + m.m13 * (m.m21 * m.m32 - m.m22 * m.m31) );

	return (new);
}


t_mtx3	ft_mtx3_inverse(t_mtx3 m3)
{
	t_mtx3	new;
	double	det;
	t_mtx3 m;

	m = m3;
	det = m.m11 * (m.m22 * m.m33 - m.m32 * m.m23)
		- m.m12 * (m.m21 * m.m33 - m.m23 * m.m31)
		+ m.m13 * (m.m21 * m.m32 - m.m22 * m.m31);
	det = 1 / det;

	new.m11 = det * (m.m22 * m.m33 - m.m32 * m.m23);
	new.m12 = det * (m.m13 * m.m32 - m.m12 * m.m33);
	new.m13 = det * (m.m12 * m.m23 - m.m13 * m.m22);

	new.m21 = det * (m.m23 * m.m31 - m.m21 * m.m33);
	new.m22 = det * (m.m11 * m.m33 - m.m13 * m.m31);
	new.m23 = det * (m.m21 * m.m13 - m.m11 * m.m23);

	new.m31 = det * (m.m21 * m.m32 - m.m31 * m.m22);
	new.m32 = det * (m.m31 * m.m12 - m.m11 * m.m32);
	new.m33 = det * (m.m11 * m.m22 - m.m21 * m.m12);

	return (new);
}
