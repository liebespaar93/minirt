/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix_3_rotation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 22:57:33 by kyoulee           #+#    #+#             */
/*   Updated: 2023/01/23 14:36:04 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "ft_matrix.h"

t_mtx3	ft_mtx3_rotation(double angle)
{
	t_mtx3	new;
	double	s;
	double	c;

	s = sin(angle);
	c = cos(angle);
	new = ft_matrix_3(\
		(double [3]){c, -s, 0}, \
		(double [3]){s, c, 0}, \
		(double [3]){0, 0, 1});
	return (new);
}
