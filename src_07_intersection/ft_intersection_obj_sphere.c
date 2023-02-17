/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intersection_obj_sphere.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 07:01:55 by kyoulee           #+#    #+#             */
/*   Updated: 2023/02/17 08:50:48 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "ft_intersection.h"

/**
 * @brief 
 * 
 * @param obj 
 * @param coord 
 * @param ray_point 
 * @param ip 
 * @ref https://m.blog.naver.com/hermet/68084286
 * @return true 
 * @return false 
 */
bool	ft_intersection_obj_sphere(t_sp *obj, t_vec3 coord, \
	t_vec3 *ray_point, t_intersection *ip)
{
	t_vec3	back_coord;
	double	t_ip[2];

	back_coord = ft_vec3_sub(coord, obj->coord);
	t_ip[0] = 0;
	t_ip[1] = 1;
	if (!ft_intersection_obj_math_circle(\
		back_coord, *ray_point, obj->radius, &t_ip))
		return (false);
	if (t_ip[0] < 0.0 && t_ip[1] < 0.0)
		return (false);
	if (t_ip[0] < 0.0 && ++ip->inside)
		t_ip[0] = t_ip[1];
	ip->hit_coord = ft_vec3_add(coord, ft_vec3_mult(*ray_point, t_ip[0]));
	ip->hit_point = ft_vec3_normalize(\
			ft_vec3_mult(ft_vec3_sub(ip->hit_coord, obj->coord), \
				1.0 - ip->inside * 2.0));
	ip->dist = ft_vec3_to_vec3_dist(ip->hit_coord, coord);
	ip->color = obj->color;
	return (true);
}
