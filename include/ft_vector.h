/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 17:41:54 by kyoulee           #+#    #+#             */
/*   Updated: 2023/01/03 18:01:16 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VECTOR_H
# define FT_VECTOR_H

typedef struct s_vector_2	t_vec2;
typedef struct s_vector_3	t_vec3;

typedef struct s_vector_2
{
	double	x;
	double	y;
}	t_vec2;

typedef struct s_vector_3
{
	double	x;
	double	y;
	double	z;
}	t_vec3;

/* ft_vector_2 */
t_vec2	ft_vector_2(double x, double y);
t_vec2	ft_vec2_sum(t_vec2 v2_1, t_vec2 v2_2);
t_vec2	ft_vec2_mult(t_vec2 v2, double scalar);
double	ft_vec2_length(t_vec2 v2);

/* ft_vector_3 */
t_vec3	ft_vector_3(double x, double y, double z);
t_vec3	ft_vec3_sum(t_vec3 v3_1, t_vec3 v3_2);
t_vec3	ft_vec3_mult(t_vec3 v3, double scalar);
double	ft_vec3_length(t_vec3 v3);
t_vec3	ft_vec3_normalize(t_vec3 v3);

/* ft_vector_to */
t_vec2	ft_vec_3to2(t_vec3 v3);

#endif