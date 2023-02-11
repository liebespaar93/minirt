/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rt_plane.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 11:51:47 by kyoulee           #+#    #+#             */
/*   Updated: 2023/02/10 09:08:39 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <math.h>
#include <errno.h>

#include "ft_rt.h"
#include "ft_minirt_tool.h"

void	ft_rt_plane(t_rt *rt, char *str)
{
	t_pl	*rt_pl;
	//int		index;
	char	**temp;

	rt_pl = malloc(sizeof(t_pl));
	if (!rt_pl)
		ft_exit_print_error(ENOMEM, "ft_rt_plane()");
	temp = ft_split(str, ' ');
	if (ft_ptrlen((void **)&temp, "char **") != 4)
		ft_exit_print_error(EBADF, "ft_rt_plane()");
	rt_pl->type = ft_strdup(temp[0]);
	rt_pl->coord = ft_rt_vec3(temp[1]);
	rt_pl->axis = ft_rt_vec3(temp[2]);

	
	if (!ft_vec3_norm(rt_pl->axis))
		rt_pl->axis = ft_vector_3(0.0, 1.0, 0.0);
	rt_pl->color = ft_rt_color(temp[3]);
	ft_split_free(temp);

	rt_pl->q_axis = ft_quaternion_from_euler_angles(ft_vec3_mult(rt_pl->axis, M_PI));
	rt_pl->point = ft_quaternion_rotate_vec3(rt_pl->q_axis, ft_vector_3(0.0, 0.0, 1.0));
	// 백터 만들기
	
	ft_rt_addback(rt, rt_pl->type, (void *)rt_pl);
}

void	ft_rt_plane_free(t_pl **rt_pl_ptr)
{
	t_pl	*rt_pl;

	if (!rt_pl_ptr)
		return ;
	rt_pl = *rt_pl_ptr;
	if (rt_pl->type)
		free(rt_pl->type);
	free(*rt_pl_ptr);
	*rt_pl_ptr = NULL;
}
