/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intersection.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 23:06:55 by kyoulee           #+#    #+#             */
/*   Updated: 2023/01/30 23:13:06 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_intersection.h"

bool	ft_scn_obj_intersection(t_scene *scene, int obj_index, t_vec3 *ray_point, t_intersection *intersection)
{
	(void)obj_index;
	(void)intersection;
	t_vec3	a;
	double	b;
	double	c;
	//t_vec3 obj = ft_vector_3(0,0,0);
	
	t_vec3 camera_coord = scene->camera_list->camera->coord;

	a = *ray_point;

	b = 2.0 * ft_vec3_dot(camera_coord, a);
	c = ft_vec3_dot(camera_coord, camera_coord) - 1.0;

	double int_test = (b * b) - (4.0 * c);

	if (int_test > 0.0)
	{
		return (true);
	}
	return (0);
}

bool	ft_obj_intersection(t_scene *scene, t_vec3 *ray_point, t_intersection *result_intersection)
{
	(void)result_intersection;
	t_intersection	intersection;
	bool	validint;

	int i;
	i = 0;
	validint = false;
	ft_memset(&intersection, 0, sizeof(t_intersection));
	result_intersection->color.x = 1;
	// while (i < scene->obj_list->max_index)
	// {
		validint = ft_scn_obj_intersection(scene, i, ray_point , &intersection);
	// }
	return (validint);

}
