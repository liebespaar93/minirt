/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix_2_mult.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 22:57:33 by kyoulee           #+#    #+#             */
/*   Updated: 2023/01/04 17:09:04 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_matrix.h"

t_mtx2	ft_mtx2_mult_scalar(t_mtx2 m2, double scalar)
{
	m2.m11 *= scalar;
	m2.m12 *= scalar;
	m2.m21 *= scalar;
	m2.m22 *= scalar;
	return (m2);
}

t_vec2	ft_vec2_mult_mtx2(t_vec2 v2, t_mtx2 m2)
{
	t_vec2	temp;

	temp.x = v2.x * m2.m11 + v2.y * m2.m21;
	temp.y = v2.x * m2.m12 + v2.y * m2.m22;
	return (temp);
}

t_vec2	ft_mtx2_mult_vec2(t_mtx2 m2, t_vec2 v2)
{
	t_vec2	temp;

	temp.x = v2.x * m2.m11 + v2.y * m2.m12;
	temp.y = v2.x * m2.m21 + v2.y * m2.m22;
	return (temp);
}

t_mtx2	ft_mtx2_mult_mtx2(t_mtx2 m2_1, t_mtx2 m2_2)
{
	t_mtx2	new;

	new.m11 = m2_1.m11 * m2_2.m11 + m2_1.m12 * m2_2.m21;
	new.m12 = m2_1.m11 * m2_2.m12 + m2_1.m12 * m2_2.m22;
	new.m21 = m2_1.m21 * m2_2.m11 + m2_1.m22 * m2_2.m21;
	new.m22 = m2_1.m21 * m2_2.m12 + m2_1.m22 * m2_2.m22;
	return (new);
}
