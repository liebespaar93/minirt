/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 22:57:33 by kyoulee           #+#    #+#             */
/*   Updated: 2023/01/26 03:26:00 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "ft_matrix.h"

t_mtx3	ft_matrix_3(double *m1, double *m2, double *m3)
{
	t_mtx3	new;

	new.m11 = m1[0];
	new.m12 = m1[1];
	new.m13 = m1[2];
	new.m21 = m2[0];
	new.m22 = m2[1];
	new.m23 = m2[2];
	new.m31 = m3[0];
	new.m32 = m3[1];
	new.m33 = m3[2];
	return (new);
}

t_mtx3	ft_mtx3_identity(void)
{
	t_mtx3		new;

	new = ft_matrix_3(\
		(double [3]){1, 0, 0}, \
		(double [3]){0, 1, 0}, \
		(double [3]){0, 0, 1});
	return (new);
}

t_mtx3	ft_mtx3_translation(double x, double y)
{
	t_mtx3	new;

	new = ft_matrix_3(\
		(double [3]){1, 0, x}, \
		(double [3]){0, 1, y}, \
		(double [3]){0, 0, 1});
	return (new);
}

t_mtx3	ft_mtx3_shear(double x, double y)
{
	t_mtx3	new;

	new = ft_matrix_3(\
		(double [3]){1, y, 0}, \
		(double [3]){x, 1, 0}, \
		(double [3]){0, 0, 1});
	return (new);
}
