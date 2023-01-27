/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_2_operator.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 00:18:18 by kyoulee           #+#    #+#             */
/*   Updated: 2023/01/12 14:31:57 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "ft_vector.h"

t_vec2	ft_vec2_add(t_vec2 v2_1, t_vec2 v2_2)
{
	v2_1.x += v2_2.x;
	v2_1.y += v2_2.y;
	return (v2_1);
}

t_vec2	ft_vec2_sub(t_vec2 v2_1, t_vec2 v2_2)
{
	v2_1.x -= v2_2.x;
	v2_1.y -= v2_2.y;
	return (v2_1);
}

t_vec2	ft_vec2_mult(t_vec2 v2, double scalar)
{
	v2.x *= scalar;
	v2.y *= scalar;
	return (v2);
}
