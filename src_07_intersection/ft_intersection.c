/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intersection.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 23:06:55 by kyoulee           #+#    #+#             */
/*   Updated: 2023/01/31 10:52:08 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <math.h>

#include "ft_intersection.h"

#include <stdio.h>


//https://www.phpschool.com/gnuboard4/bbs/board.php?bo_table=tipntech&wr_id=75345&sca=&sfl=wr_subject%7C%7Cwr_content&stx=%C0%CC%B9%CC%C1%F6+%C1%C2%C7%A5&sop=and
bool	ft_obj_plane_intersection(t_pl *obj, t_C *camera, const t_vec3 *ray_point, t_intersection *intersection)
{
	double	u;

	u = ft_vec3_dot(obj->axis, *ray_point);
	
	if (u > 0.0)
	{
		intersection->type = obj->type;
		intersection->obj = (t_rt *)obj;
		intersection->color = ft_vector_3(obj->color.bit.r / 255, obj->color.bit.g / 255, obj->color.bit.b/ 255);
		intersection->hit_point = ft_vec3_add(camera->coord, ft_vec3_mult(*ray_point, u));
		intersection->out_point = 
			ft_vec3_add(*ray_point,
				ft_vec3_mult( ft_vec3_mult(obj->axis ,2), 
					ft_vec3_dot(ft_vec3_mult(*ray_point, -1), obj->axis)));
		intersection->dist = u;
		return (true);
	}
	return (false);
}

bool	ft_obj_sphere_intersection(t_sp *obj, t_C *camera, const t_vec3 *ray_point, t_intersection *intersection)
{
	t_vec3	l = ft_vec3_sub(obj->coord, camera->coord); // 원과의 방향
	double	s = ft_vec3_dot(l, *ray_point); // 내적 각도
	double l2 =	ft_vec3_dot(l, l); // 원과의 거리 수치
	double r2=	pow(obj->diameter/2, 2);


	return (false);
}

// bool	ft_obj_cylinder_intersection(t_pl *obj, t_C *camera, const t_vec3 *ray_point, t_intersection *intersection)
// {
// 	return (false);
// }

bool	ft_scn_obj_intersection(t_rt *obj, t_C *camera, const t_vec3 *ray_point, t_intersection *intersection)
{
	bool	result;

	result = false;
	if (!ft_strcmp(obj->type, "pl"))
		result = ft_obj_plane_intersection((t_pl *)obj, camera, ray_point, intersection);
	else if (!ft_strcmp(obj->type, "sp"))
		result = ft_obj_sphere_intersection((t_sp *)obj, camera, ray_point, intersection);
	// else if (!ft_strcmp(obj->type, "cy"))
	// 	result = ft_obj_cylinder_intersection((t_cy *)obj, camera, ray_point, intersection);
	
	return (result);
}

bool	ft_obj_intersection(t_scene *scene, const t_vec3 *ray_point, t_intersection *result_intersection)
{
	t_intersection	intersection;
	bool	intersection_found;
	int i;
	double	min_dist;


	intersection_found = false;
	min_dist = 10000;
	i = 0;
	while (i < scene->obj_list->max_index)
	{
		ft_memset(&intersection, 0, sizeof(t_intersection));
		if (ft_scn_obj_intersection(scene->obj_list->rt[i], scene->camera_list->camera, ray_point, &intersection))
		{
			if (intersection.dist < min_dist)
			{
				intersection_found = true;
				min_dist = intersection.dist;
				*result_intersection = intersection;
			}
		}
		i++;
	}
	return (intersection_found);

}


void	ft_intersection(t_scene *scene)
{
	int l;
	t_vec3	ray_point;
	t_vec3	v3_target;
	t_intersection	intersection;

	l = 0;
	v3_target = ft_vector_3(0.0,0.0,1.0);
	while (l < scene->pixel_size)
	{
		ft_memset(&intersection, 0, sizeof(t_intersection));
		ray_point = ft_quaternion_rotate_vec3(scene->pixel_q[l], v3_target);
		if (ft_obj_intersection(scene, &ray_point, &intersection))
		{
			// 물체 표면에 따라 다음에 만들기
			//if (obj_option)
			// {
			//		ft_material_base_compute_color;
			// }
			//else
			// {
			ft_image_set_pixel(scene->image, l, &intersection.color);


			// }

		}
		else
			ft_image_unset_pixel(scene->image, l);
		l++;
	}
}