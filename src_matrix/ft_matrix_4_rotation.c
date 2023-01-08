/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix_4_rotation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 07:16:36 by kyoulee           #+#    #+#             */
/*   Updated: 2023/01/04 17:14:19 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "ft_matrix.h"

t_mtx4	ft_mtx4_rot_x(double angle)
{
	t_mtx4	new;
	double	s;
	double	c;

	s = sin(angle);
	c = cos(angle);
	new = ft_matrix_4(\
		(double [4]){1, 0, 0, 0}, \
		(double [4]){0, c, -s, 0}, \
		(double [4]){0, s, c, 0}, \
		(double [4]){0, 0, 0, 1});
	return (new);
}

t_mtx4	ft_mtx4_rot_y(double angle)
{
	t_mtx4	new;
	double	s;
	double	c;

	s = sin(angle);
	c = cos(angle);
	new = ft_matrix_4(\
		(double [4]){c, 0, s, 0}, \
		(double [4]){0, 1, 0, 0}, \
		(double [4]){-s, 0, c, 0}, \
		(double [4]){0, 0, 0, 1});
	return (new);
}

t_mtx4	ft_mtx4_rot_z(double angle)
{
	t_mtx4	new;
	double	s;
	double	c;

	s = sin(angle);
	c = cos(angle);
	new = ft_matrix_4(\
		(double [4]){c, -s, 0, 0}, \
		(double [4]){s, c, 0, 0}, \
		(double [4]){0, 0, 1, 0}, \
		(double [4]){0, 0, 0, 1});
	return (new);
}
