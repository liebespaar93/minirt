/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intersection.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 23:12:12 by kyoulee           #+#    #+#             */
/*   Updated: 2023/02/17 08:53:31 by kyoulee          ###   ########.fr       */
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
	t_vec3	hit_coord;
	t_vec3	hit_point;
	t_vec3	color;
	double	dist;
	bool	inside;
}	t_intersection;


void	ft_intersection(t_scene *scene);

bool	ft_intersection_obj(t_scene *scene, t_vec3 *coord, t_vec3 *ray_point, t_intersection *ip_result);
bool	ft_intersection_scn_obj(t_rt *obj, t_vec3 *coord, t_vec3 *ray_point, t_intersection *ip);



t_vec3	ft_intersection_light_math_incidence(const t_vec3 ray_point, const t_vec3 hit_point);
double	ft_intersection_light_math_diffuse_reflection(
	const t_vec3 *light_point, const t_vec3 *hit_point);
double	ft_intersection_light_math_specular_reflection(
	const t_vec3 *ray_point, const t_vec3 *light_point, const t_vec3 *hit_point);

bool	ft_intersection_light_ambient(
	t_scene *scene, t_A *light, t_vec3 *light_color, t_intersection *ip);

bool	ft_intersection_light_light(
	t_scene *scene, t_L *light, t_vec3 *light_color, t_intersection *ip);

bool	ft_intersection_light(t_scene *scene, t_vec3 *ray_poin, t_intersection *ip);




bool	ft_intersection_obj_math_circle(t_vec3 coord, t_vec3 ray_point, double radius, double (*t)[2]);

bool	ft_intersection_obj_sphere(t_sp *obj, t_vec3 coord, \
	t_vec3 *ray_point, t_intersection *ip);

bool	ft_intersection_obj_plane(t_pl *obj, t_vec3 coord, \
	t_vec3 *ray_point, t_intersection *ip);

bool	ft_intersection_obj_cylinder(t_cy *obj, t_vec3 coord, t_vec3 *ray_point, t_intersection *ip);
#endif

