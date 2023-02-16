/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rt_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 14:52:16 by kyoulee           #+#    #+#             */
/*   Updated: 2023/02/14 05:05:43 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <errno.h>
#include <math.h>

#include "ft_rt.h"
#include "ft_minirt_tool.h"

void	ft_rt_camera(t_rt *rt, char *str)
{
	t_C		*rt_C;
	//int		index;
	char	**temp;

	rt_C = malloc(sizeof(t_C));
	if (!rt_C)
		ft_exit_print_error(ENOMEM, "ft_rt_camera()");
	temp = ft_split(str, ' ');
	if (ft_ptrlen((void **)&temp, "char **") != 4)
		ft_exit_print_error(EBADF, "ft_rt_camera()");
	rt_C->type = ft_strdup(temp[0]);
	rt_C->coord = ft_rt_vec3(temp[1]);
	rt_C->axis = ft_rt_vec3(temp[2]);
	rt_C->fov = ft_atof(temp[3]);
	rt_C->q_axis = ft_quaternion_rotation_xyz(ft_vec3_mult(rt_C->axis, M_PI));
	ft_split_free(temp);
	ft_rt_addback(rt, rt_C->type, (void *)rt_C);
}

void	ft_rt_camera_free(t_C **rt_C_ptr)
{
	t_C		*rt_C;

	if (!rt_C_ptr)
		return ;
	rt_C = *rt_C_ptr;
	if (rt_C->type)
		free(rt_C->type);
	free(*rt_C_ptr);
	*rt_C_ptr = NULL;
}
