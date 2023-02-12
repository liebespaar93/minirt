/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matirx_to.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 19:26:30 by kyoulee           #+#    #+#             */
/*   Updated: 2023/02/11 19:30:48 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_matrix.h"

t_mtx4	ft_mtx3_to_mtx4(t_mtx3 m3)
{
	t_mtx4	m4;
	
	m4 = ft_matrix_4(\
		(double [4]){m3.m11, m3.m12, m3.m13, 0}, \
		(double [4]){m3.m21, m3.m22, m3.m23, 0}, \
		(double [4]){m3.m31, m3.m32, m3.m33, 0}, \
		(double [4]){0, 0, 0, 1});
	return (m4);
}