/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 22:57:33 by kyoulee           #+#    #+#             */
/*   Updated: 2023/01/04 17:11:15 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "ft_matrix.h"

t_mtx2	ft_matrix_2(double m11, double m12, double m21, double m22)
{
	t_mtx2	new;

	new.m11 = m11;
	new.m12 = m12;
	new.m21 = m21;
	new.m22 = m22;
	return (new);
}

t_mtx2	ft_mtx2_identity(void)
{
	t_mtx2		new;

	new = ft_matrix_2(1, 0, 0, 1);
	return (new);
}

t_mtx2	ft_mtx2_shear(double x, double y)
{
	t_mtx2	new;

	new.m11 = 1;
	new.m12 = y;
	new.m21 = x;
	new.m22 = 1;
	return (new);
}

t_mtx2	ft_mtx2_rotation(double angle)
{
	t_mtx2		new;
	double		s;
	double		c;

	s = sin(angle);
	c = cos(angle);
	new = ft_matrix_2(c, -s, s, c);
	return (new);
}
