/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intersection.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 23:12:12 by kyoulee           #+#    #+#             */
/*   Updated: 2023/01/30 23:15:53 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_INTERSECTION_H
# define FT_INTERSECTION_H

#include "ft_rt.h"
# include "ft_scene.h"

typedef struct s_intersection
{
	/* data */
	t_rt	*obj;
	t_vec3	int_point;
	t_vec3	local_normal;
	t_vec3	color;
}	t_intersection;

bool	ft_obj_intersection(t_scene *scene, t_vec3 *ray_point, t_intersection *result_intersection);

#endif

