/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 22:51:54 by kyoulee           #+#    #+#             */
/*   Updated: 2023/02/17 03:15:25 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MATRIX_H
# define FT_MATRIX_H

# include "ft_vector.h"

typedef struct s_matrix2	t_mtx2;
typedef struct s_matrix3	t_mtx3;
typedef struct s_matrix4	t_mtx4;

typedef struct s_matrix2
{
	double	m11;
	double	m12;
	double	m21;
	double	m22;
}	t_mtx2;

typedef struct s_matrix3
{
	double	m11;
	double	m12;
	double	m13;
	double	m21;
	double	m22;
	double	m23;
	double	m31;
	double	m32;
	double	m33;
}	t_mtx3;

typedef struct s_matrix4
{
	double	m11;
	double	m12;
	double	m13;
	double	m14;
	double	m21;
	double	m22;
	double	m23;
	double	m24;
	double	m31;
	double	m32;
	double	m33;
	double	m34;
	double	m41;
	double	m42;
	double	m43;
	double	m44;
}	t_mtx4;

/* ft_matrix_2 */
t_mtx2	ft_matrix_2(double m11, double m12, double m21, double m22);
t_mtx2	ft_mtx2_identity(void);
t_mtx2	ft_mtx2_shear(double x, double y);
t_mtx2	ft_mtx2_rotation(double angle);

t_mtx2	ft_mtx2_mult_scalar(t_mtx2 m2, double scalar);
t_vec2	ft_vec2_mult_mtx2(t_vec2 v2, t_mtx2 m2);
t_vec2	ft_mtx2_mult_vec2(t_mtx2 m2, t_vec2 v2);
t_mtx2	ft_mtx2_mult_mtx2(t_mtx2 m2_1, t_mtx2 m2_2);

/* ft_matrix_3 */
t_mtx3	ft_matrix_3(double *m1, double *m2, double *m3);
t_mtx3	ft_mtx3_identity(void);
t_mtx3	ft_mtx3_translation(double x, double y);
t_mtx3	ft_mtx3_shear(double x, double y);
t_mtx3	ft_mtx3_rotation(double angle);

t_mtx3	ft_mtx3_mult_scalar(t_mtx3 m3, double scalar);
t_vec2	ft_vec2_mult_mtx3(t_vec2 v2, t_mtx3 m3);
t_vec2	ft_mtx3_mult_vec2(t_mtx3 m3, t_vec2 v2);
t_mtx3	ft_mtx3_mult_mtx3(t_mtx3 m3_1, t_mtx3 m3_2);
t_vec3	ft_mtx3_mult_vec3(t_mtx3 m3, t_vec3 v3);

/* ft_matrix_4 */
t_mtx4	ft_matrix_4(double *m1, double *m2, double *m3, double *m4);
t_mtx4	ft_mtx4_identity(void);
t_mtx4	ft_mtx4_translation(double x, double y, double z);
t_mtx4	ft_mtx4_scale(double x, double y, double z);
t_mtx4	ft_mtx4_projection(double d);
t_mtx4	ft_mtx4_mult_scalar(t_mtx4 m4, double scalar);
t_vec3	ft_vec3_mult_mtx4(t_vec3 v3, t_mtx4 m4);
t_vec3	ft_mtx4_mult_vec3(t_mtx4 m4, t_vec3 v3);
double	ft_mtx4_row_mult_mtx4_col(t_mtx4 m4_1, t_mtx4 m4_2, int row, int col);
t_mtx4	ft_mtx4_mult_mtx4(t_mtx4 m4_1, t_mtx4 m4_2);
t_mtx4	ft_mtx4_rot_x(double angle);
t_mtx4	ft_mtx4_rot_y(double angle);
t_mtx4	ft_mtx4_rot_z(double angle);

t_mtx4	ft_mtx4_inverse(t_mtx4 m4);
t_mtx3	ft_mtx3_inverse(t_mtx3 m3);

/* ft_matrix_to */
t_mtx4	ft_mtx3_to_mtx4(t_mtx3 m3);

#endif