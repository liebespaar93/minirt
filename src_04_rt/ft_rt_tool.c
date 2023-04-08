/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rt_tool.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 13:42:58 by kyoulee           #+#    #+#             */
/*   Updated: 2023/02/17 04:36:35 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <errno.h>
#include <stdio.h>

#include "ft_minirt_tool.h"
#include "ft_rt.h"
#include "ft_vector.h"

int	ft_color_check(int color)
{
	if (!(0 <= color && color < 256))
		ft_exit_print_error(EBADF, "ft_color_check()");
	return (color);
}

t_vec3	ft_rt_color(char *str)
{
	char	**temp;
	t_vec3	color;

	temp = ft_split(str, ',');
	if (ft_ptrlen((void **)&temp, "char **") != 3)
		ft_exit_print_error(EBADF, "ft_rt_color()");
	if ((!ft_is_end_space(*(temp[0] + ft_atoi_len(temp[0]))) \
		|| !ft_is_end_space(*(temp[1] + ft_atoi_len(temp[1]))) \
		|| !ft_is_end_space(*(temp[2] + ft_atoi_len(temp[2])))) \
		&& printf("%s \n", str))
		ft_exit_print_error(EBADF, "ft_rt_color()");
	color.x = ft_color_check(ft_atoi(temp[0])) / 255.0;
	color.y = ft_color_check(ft_atoi(temp[1])) / 255.0;
	color.z = ft_color_check(ft_atoi(temp[2])) / 255.0;
	ft_split_free(temp);
	return (color);
}

t_vec3	ft_rt_vec3(char *str)
{
	char	**temp;
	t_vec3	vec;

	temp = ft_split(str, ',');
	if (ft_ptrlen((void **)&temp, "char **") != 3)
		ft_exit_print_error(EBADF, "ft_rt_vec3()");
	vec.x = ft_atof(temp[0]);
	vec.y = ft_atof(temp[1]);
	vec.z = ft_atof(temp[2]);
	ft_split_free(temp);
	return (vec);
}

/*
#include <stdio.h>
void	ft_rt_printf(t_rt rt)
{
	if (!ft_strcmp(rt.type, "A"))
		printf("%s \t%f %f %f %f\n", 
			((t_A *)rt.data)->type, 
			((t_A *)rt.data)->ratio, 
			((t_A *)rt.data)->color.x, 
			((t_A *)rt.data)->color.y, 
			((t_A *)rt.data)->color.z);
	else if (!ft_strcmp(rt.type, "C"))
		printf("%s \t%f %f %f %f %f %f %f\n", 
			((t_C *)rt.data)->type, 
			((t_C *)rt.data)->coord.x, 
			((t_C *)rt.data)->coord.y, 
			((t_C *)rt.data)->coord.z, 
			((t_C *)rt.data)->axis.x, 
			((t_C *)rt.data)->axis.y, 
			((t_C *)rt.data)->axis.z,
			((t_C *)rt.data)->fov);
	else if (!ft_strcmp(rt.type, "L"))
		printf("%s \t%f %f %f %f %f %f %f\n", 
			((t_L *)rt.data)->type, 
			((t_L *)rt.data)->coord.x, 
			((t_L *)rt.data)->coord.y, 
			((t_L *)rt.data)->coord.z, 
			((t_L *)rt.data)->ratio,
			((t_L *)rt.data)->color.x, 
			((t_L *)rt.data)->color.y, 
			((t_L *)rt.data)->color.z);
	else if (!ft_strcmp(rt.type, "sp"))
		printf("%s \t%f %f %f %f %f %f %f\n", 
			((t_sp *)rt.data)->type, 
			((t_sp *)rt.data)->coord.x, 
			((t_sp *)rt.data)->coord.y, 
			((t_sp *)rt.data)->coord.z, 
			((t_sp *)rt.data)->diameter,
			((t_sp *)rt.data)->color.x, 
			((t_sp *)rt.data)->color.y, 
			((t_sp *)rt.data)->color.z);
	else if (!ft_strcmp(rt.type, "pl"))
		printf("%s \t%f %f %f %f %f %f %f %f %f\n", 
			((t_pl *)rt.data)->type, 
			((t_pl *)rt.data)->coord.x, 
			((t_pl *)rt.data)->coord.y, 
			((t_pl *)rt.data)->coord.z, 
			((t_pl *)rt.data)->axis.x, 
			((t_pl *)rt.data)->axis.y, 
			((t_pl *)rt.data)->axis.z,
			((t_pl *)rt.data)->color.x, 
			((t_pl *)rt.data)->color.y, 
			((t_pl *)rt.data)->color.z);
	else if (!ft_strcmp(rt.type, "cy"))
		printf("%s \t%f %f %f %f %f %f %f %f %f %f %f\n", 
			((t_cy *)rt.data)->type, 
			((t_cy *)rt.data)->coord.x, 
			((t_cy *)rt.data)->coord.y, 
			((t_cy *)rt.data)->coord.z, 
			((t_cy *)rt.data)->axis.x, 
			((t_cy *)rt.data)->axis.y, 
			((t_cy *)rt.data)->axis.z,
			((t_cy *)rt.data)->diameter,
			((t_cy *)rt.data)->height,
			((t_cy *)rt.data)->color.x, 
			((t_cy *)rt.data)->color.y, 
			((t_cy *)rt.data)->color.z);
	else
		printf("error rt!!");
}
*/