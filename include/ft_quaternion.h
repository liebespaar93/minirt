/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quaternion.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 16:37:28 by kyoulee           #+#    #+#             */
/*   Updated: 2023/02/18 02:21:48 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_QUATERNION_H
# define FT_QUATERNION_H

# include "ft_vector.h"
# include "ft_matrix.h"

typedef struct s_quaternion
{
	double	x;
	double	y;
	double	z;
	double	w;
}	t_quaternion;

t_quaternion	ft_quaternion_set(double x, double y, double z, double w);
t_quaternion	ft_quaternion_identity(void);
t_quaternion	ft_quaternion_conjugate(t_quaternion q);
double			ft_quaternion_norm(t_quaternion q);
t_quaternion	ft_quaternion_normalize(t_quaternion q);
t_quaternion	ft_quaternion_from_euler_angles(t_vec3 angles);
t_vec3			ft_quaternion_to_euler_angles(t_quaternion q);
t_quaternion	ft_quaternion_axis_from_angle(t_vec3 axis, double angle);
t_vec3			ft_quaternion_axis_to_angles(t_quaternion q, double *angle);
t_quaternion	ft_quaternion_rotation_x(double angle);
t_quaternion	ft_quaternion_rotation_y(double angle);
t_quaternion	ft_quaternion_rotation_z(double angle);
t_quaternion	ft_quaternion_rotation_xyz(t_vec3 angle);
t_quaternion	ft_quaternion_multiply(t_quaternion q1, t_quaternion q2);
t_mtx3			ft_quaternion_rotate_matrix(t_quaternion q);
t_vec3			ft_quaternion_rotate_vec3(t_quaternion q, t_vec3 v3);

#endif
