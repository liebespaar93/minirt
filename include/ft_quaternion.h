/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quaternion.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 16:37:28 by kyoulee           #+#    #+#             */
/*   Updated: 2023/01/04 19:32:19 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_QUATERNION_H
# define FT_QUATERNION_H

// https://cs.stanford.edu/~acoates/

#include "ft_vector.h"
#include "ft_matrix.h"

typedef struct s_quaternion
{
	double	x;
	double	y;
	double	z;
	double	w;
}	t_quaternion;

typedef struct s_angles
{
	double	x;
	double	y;
	double	z;
}	t_angles;


t_quaternion	ft_quaternion_set(double x, double y, double z, double w);
t_quaternion	ft_quaternion_identity();
t_quaternion	ft_quaternion_conjugate(t_quaternion q);
double			ft_quaternion_norm(t_quaternion q);
t_quaternion	ft_quaternion_normalize(t_quaternion q);
t_quaternion	ft_quaternion_euler_from_angles(t_angles angles);
t_angles		ft_quaternion_euler_to_angles(t_quaternion q);
t_quaternion	ft_quaternion_axis_from_angle(t_angles axis, double angle);
t_angles		ft_quaternion_axis_to_angles(t_quaternion q);
t_quaternion	ft_quaternion_rotation_x(double angle);
t_quaternion	ft_quaternion_rotation_y(double angle);
t_quaternion	ft_quaternion_rotation_z(double angle);
t_quaternion	ft_quaternion_multiply(t_quaternion q1, t_quaternion q2);
t_mtx3			ft_quaternion_rotate_matrix(t_quaternion q);
t_vec3			ft_quaternion_rotate_vec3(t_quaternion q, t_vec3 v3);


#endif
