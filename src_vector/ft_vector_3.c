/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 00:18:18 by kyoulee           #+#    #+#             */
/*   Updated: 2023/01/13 16:42:01 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "ft_vector.h"

t_vec3	ft_vector_3(double x, double y, double z)
{
	t_vec3	new;

	new.x = x;
	new.y = y;
	new.z = z;
	return (new);
}

double	ft_vec3_norm(t_vec3 v3)
{
	double	temp;

	temp = sqrt(v3.x * v3.x + v3.y * v3.y + v3.z * v3.z);
	return (temp);
}

t_vec3	ft_vec3_normalize(t_vec3 v3)
{
	double	length;

	length = ft_vec3_norm(v3);
	v3.x = v3.x / length;
	v3.y = v3.y / length;
	v3.z = v3.z / length;
	return (v3);
}
