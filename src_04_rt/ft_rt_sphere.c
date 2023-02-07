/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rt_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 11:50:23 by kyoulee           #+#    #+#             */
/*   Updated: 2023/02/06 17:24:48 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <errno.h>

#include "ft_rt.h"
#include "ft_minirt_tool.h"

void	ft_rt_sphere(t_rt *rt, char *str)
{
	t_sp	*rt_sp;
	//int		index;
	char	**temp;

	rt_sp = malloc(sizeof(t_sp));
	if (!rt_sp)
		ft_exit_print_error(ENOMEM, "ft_rt_sphere()");
	temp = ft_split(str, ' ');
	if (ft_ptrlen((void **)&temp, "char **") != 4)
		ft_exit_print_error(EBADF, "ft_rt_sphere()");
	rt_sp->type = ft_strdup(temp[0]);
	rt_sp->coord = ft_rt_vec3(temp[1]);
	rt_sp->diameter = ft_atof(temp[2]);
	rt_sp->color = ft_rt_color(temp[3]);
	ft_split_free(temp);

	// 추가항목
	rt_sp->axis = ft_vector_3(0.0, 0.0, 1.0);
	rt_sp->radius = rt_sp->diameter / 2.0;

	ft_rt_addback(rt, rt_sp->type, (void *)rt_sp);
}

void	ft_rt_sphere_free(t_sp **rt_sp_ptr)
{
	t_sp	*rt_sp;

	if (!rt_sp_ptr)
		return ;
	rt_sp = *rt_sp_ptr;
	if (rt_sp->type)
		free(rt_sp->type);
	free(*rt_sp_ptr);
	*rt_sp_ptr = NULL;
}
