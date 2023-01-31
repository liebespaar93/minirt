/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intersection.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 23:12:12 by kyoulee           #+#    #+#             */
/*   Updated: 2023/01/31 02:26:36 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_INTERSECTION_H
# define FT_INTERSECTION_H

#include "ft_rt.h"
# include "ft_scene.h"

typedef struct s_intersection
{
	/* data */
	char	*type;
	t_rt	*obj;
	t_vec3	hit_point;
	t_vec3	out_point;
	t_vec3	color;
	double	dist;
}	t_intersection;


void	ft_intersection(t_scene *scene);

#endif

