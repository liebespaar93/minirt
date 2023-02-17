/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intersection_obj_plane.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 07:01:50 by kyoulee           #+#    #+#             */
/*   Updated: 2023/02/17 08:40:48 by kyoulee          ###   ########.fr       */
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
 * @ref http://matrix.skku.ac.kr/M-calculus/W2/
 * @return true 
 * @return false
 */
bool	ft_intersection_obj_plane(t_pl *obj, t_vec3 coord, \
	t_vec3 *ray_point, t_intersection *ip)
{	
	t_vec3	back_coord;
	double	t;
	double	l;

	back_coord = ft_vec3_sub(coord, obj->coord);
	l = ft_vec3_dot(*ray_point, obj->gt.point);
	if (l == 0.0)
		return (false);
	else if (l > 0.0)
		ip->inside = 1;
	else
		ip->inside = 0;
	t = ft_vec3_dot(back_coord, obj->gt.point) / -l;
	if (t <= 0.0)
		return (false);
	ip->hit_coord = ft_vec3_add(coord, ft_vec3_mult(*ray_point, t));
	ip->hit_point = ft_vec3_mult(obj->gt.point, 1.0 - ip->inside * 2.0);
	ip->dist = ft_vec3_to_vec3_dist(ip->hit_coord, coord);
	ip->color = obj->color;
	return (true);
}
