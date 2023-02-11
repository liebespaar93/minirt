/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intersection_light.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 14:22:35 by kyoulee           #+#    #+#             */
/*   Updated: 2023/02/10 19:10:43 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <math.h>

#include "ft_intersection.h"
#include "ft_shadow.h"


#include <stdio.h>

//빈시긱 R = P +  2n(-P·n)
t_vec3	ft_angle_of_incidence(const t_vec3 ray_point, const t_vec3 hit_point)
{
	return (ft_vec3_add(ray_point, 
			ft_vec3_mult(hit_point, 2.0 * ft_vec3_dot(ft_vec3_mult(ray_point, -1.0) , hit_point))));
}

// 난반사
//https://darkpgmr.tistory.com/121
double	ft_light_diffuse_reflection(const t_vec3 *light_point, const t_vec3 *hit_point)
{
	t_vec3	reflection;

	reflection = ft_angle_of_incidence(ft_vec3_mult(*light_point, -1.0), *hit_point);
	return (acos(ft_vec3_dot(*light_point, reflection)));
}

// 정반사
double	ft_light_specular_reflection(const t_vec3 *ray_point, const t_vec3 *light_point, const t_vec3 *hit_point)
{
	t_vec3	reflection;

	reflection = ft_angle_of_incidence(*ray_point, *hit_point);
	return (acos(ft_vec3_dot(*light_point, reflection)));
}


bool	ft_light_light_intersection(t_scene *scene, t_L *light, const t_vec3 *ray_point, t_vec3 *light_color, t_intersection *intersection)
{
	(void)scene;
	double	angle;
	t_vec3	light_point;


	light_point = ft_vec3_normalize(ft_vec3_sub(light->coord, intersection->hit_coord));
	if (1)
		angle = ft_light_diffuse_reflection(&light_point, &intersection->hit_point);
	if (0)
		angle = ft_light_specular_reflection(ray_point, &light_point, &intersection->hit_point);

	if (angle < M_PI / 1.0)
	{
		// if (ft_shadow(scene, &light->coord, intersection))
		// 	return (false);
		*light_color = ft_vec3_mult(
			ft_vector_3(
				intersection->color.x * light->color.x,
				intersection->color.y * light->color.y, 
				intersection->color.z * light->color.z), 
				light->ratio * (1.0 - angle / (M_PI)));
		return (true);
	}

	return (false);
}

bool	ft_light_ambient_intersection(t_scene *scene, t_A *light, const t_vec3 *ray_point, t_vec3 *light_color, t_intersection *intersection)
{
	(void)scene;
	(void)ray_point;
	*light_color = ft_vec3_mult(
		ft_vector_3(
			intersection->color.x * light->color.x,
			intersection->color.y * light->color.y, 
			intersection->color.z * light->color.z), 
			light->ratio);
	return (true);
}


bool	ft_scn_light_intersection(t_scene *scene, t_rt *light, const t_vec3 *ray_point, t_vec3 *light_color, t_intersection *intersection)
{
	if (!ft_strcmp(light->type, "A"))
		return (ft_light_ambient_intersection(scene, (t_A *)light, ray_point, light_color, intersection));
	else if (!ft_strcmp(light->type, "L"))
		return (ft_light_light_intersection(scene, (t_L *)light, ray_point, light_color, intersection));
	return (false);
}

bool	ft_light_intersection(t_scene *scene, const t_vec3 *ray_point, t_intersection *intersection)
{
	bool			intersection_found;
	t_vec3			light_color;
	t_vec3			all_color;
	int				light_count;
	int i;

	intersection_found = false;
	light_count = 0;
	i = 0;
	all_color = ft_vector_3(0.0, 0.0, 0.0);
	while (i < scene->light_list->max_index)
	{
		light_color = ft_vector_3(0.0, 0.0, 0.0);
		if (ft_scn_light_intersection(scene, scene->light_list->rt[i], ray_point, &light_color, intersection))
		{
			
			all_color = ft_vec3_add(all_color, light_color);
			light_count++;
		}
		i++;
	}
	if (all_color.x > 1.0)
		all_color.x = 1.0;
	if (all_color.y > 1.0)
		all_color.y = 1.0;
	if (all_color.z > 1.0)
		all_color.z = 1.0;
	intersection->color = all_color;
	return (intersection_found);
}