/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 17:41:15 by kyoulee           #+#    #+#             */
/*   Updated: 2023/01/12 14:35:12 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "ft_vector.h"

t_vec2	ft_vector_2(double x, double y)
{
	t_vec2	new;

	new.x = x;
	new.y = y;
	return (new);
}

double	ft_vec2_length(t_vec2 v2)
{
	double	temp;

	temp = sqrt(v2.x * v2.x + v2.y * v2.y);
	return (temp);
}

t_vec2	ft_vec2_normalize(t_vec2 v2)
{
	double	length;

	length = ft_vec2_length(v2);
	v2.x = v2.x / length;
	v2.y = v2.y / length;
	return (v2);
}
