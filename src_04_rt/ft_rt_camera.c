/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rt_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 14:52:16 by kyoulee           #+#    #+#             */
/*   Updated: 2023/02/17 04:35:23 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <errno.h>
#include <math.h>

#include "ft_rt.h"
#include "ft_minirt_tool.h"

void	ft_rt_camera(t_rt *rt, char *str)
{
	t_C		*rt_c;
	char	**temp;

	rt_c = malloc(sizeof(t_C));
	if (!rt_c)
		ft_exit_print_error(ENOMEM, "ft_rt_camera()");
	temp = ft_split(str, ' ');
	if (ft_ptrlen((void **)&temp, "char **") != 4)
		ft_exit_print_error(EBADF, "ft_rt_camera()");
	rt_c->type = ft_strdup(temp[0]);
	rt_c->coord = ft_rt_vec3(temp[1]);
	rt_c->axis = ft_rt_vec3(temp[2]);
	rt_c->fov = ft_atof(temp[3]);
	rt_c->q_axis = ft_quaternion_rotation_xyz(ft_vec3_mult(rt_c->axis, M_PI));
	ft_split_free(temp);
	ft_rt_addback(rt, rt_c->type, (void *)rt_c);
}

void	ft_rt_camera_free(t_C **rt_c_ptr)
{
	t_C		*rt_c;

	if (!rt_c_ptr)
		return ;
	rt_c = *rt_c_ptr;
	if (rt_c->type)
		free(rt_c->type);
	free(*rt_c_ptr);
	*rt_c_ptr = NULL;
}
