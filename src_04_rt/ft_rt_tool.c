/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rt_tool.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 13:42:58 by kyoulee           #+#    #+#             */
/*   Updated: 2022/12/26 14:27:09 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <errno.h>

#include "ft_minirt_tool.h"
#include "ft_rt.h"
#include "ft_vector.h"

int	ft_color_check(int color)
{
	if (!(0 <= color && color < 256))
		ft_exit_error(EBADF);
	return (color);	
}

int	ft_rt_color(char *str)
{
	char	**temp;
	t_color	color;

	temp = ft_split(str, ',');
	if (ft_ptrlen((void **)&temp, "char **") != 3)
		ft_exit_error(EBADF);
	color.integer = 0;
	color.bit.r = ft_color_check(ft_atoi(temp[0]));
	color.bit.g = ft_color_check(ft_atoi(temp[1]));
	color.bit.b = ft_color_check(ft_atoi(temp[2]));
	ft_split_free(temp);
	return (color.integer);
}

t_vec3	ft_rt_vec3(char *str)
{
	char	**temp;
	t_vec3	vec;

	temp = ft_split(str, ',');
	if (ft_ptrlen((void **)&temp, "char **") != 3)
		ft_exit_error(EBADF);
	vec.x = ft_atof(temp[0]);
	vec.y = ft_atof(temp[1]);
	vec.z = ft_atof(temp[2]);
	ft_split_free(temp);
	return (vec);
}


#include <stdio.h>
void	ft_rt_printf(t_rt rt)
{
	if (!ft_strcmp(rt.type, "A"))
		printf("%s \t%f %d %d %d\n", 
			((t_A *)rt.data)->type, 
			((t_A *)rt.data)->ratio, 
			((t_A *)rt.data)->color.bit.r, 
			((t_A *)rt.data)->color.bit.g, 
			((t_A *)rt.data)->color.bit.b);
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
		printf("%s \t%f %f %f %f %d %d %d\n", 
			((t_L *)rt.data)->type, 
			((t_L *)rt.data)->coord.x, 
			((t_L *)rt.data)->coord.y, 
			((t_L *)rt.data)->coord.z, 
			((t_L *)rt.data)->ratio,
			((t_L *)rt.data)->color.bit.r, 
			((t_L *)rt.data)->color.bit.g, 
			((t_L *)rt.data)->color.bit.b);
	else if (!ft_strcmp(rt.type, "sp"))
		printf("%s \t%f %f %f %f %d %d %d\n", 
			((t_sp *)rt.data)->type, 
			((t_sp *)rt.data)->coord.x, 
			((t_sp *)rt.data)->coord.y, 
			((t_sp *)rt.data)->coord.z, 
			((t_sp *)rt.data)->diameter,
			((t_sp *)rt.data)->color.bit.r, 
			((t_sp *)rt.data)->color.bit.g, 
			((t_sp *)rt.data)->color.bit.b);
	else if (!ft_strcmp(rt.type, "pl"))
		printf("%s \t%f %f %f %f %f %f %d %d %d\n", 
			((t_pl *)rt.data)->type, 
			((t_pl *)rt.data)->coord.x, 
			((t_pl *)rt.data)->coord.y, 
			((t_pl *)rt.data)->coord.z, 
			((t_pl *)rt.data)->axis.x, 
			((t_pl *)rt.data)->axis.y, 
			((t_pl *)rt.data)->axis.z,
			((t_pl *)rt.data)->color.bit.r, 
			((t_pl *)rt.data)->color.bit.g, 
			((t_pl *)rt.data)->color.bit.b);
	else if (!ft_strcmp(rt.type, "cy"))
		printf("%s \t%f %f %f %f %f %f %f %f %d %d %d\n", 
			((t_cy *)rt.data)->type, 
			((t_cy *)rt.data)->coord.x, 
			((t_cy *)rt.data)->coord.y, 
			((t_cy *)rt.data)->coord.z, 
			((t_cy *)rt.data)->axis.x, 
			((t_cy *)rt.data)->axis.y, 
			((t_cy *)rt.data)->axis.z,
			((t_cy *)rt.data)->diameter,
			((t_cy *)rt.data)->height,
			((t_cy *)rt.data)->color.bit.r, 
			((t_cy *)rt.data)->color.bit.g, 
			((t_cy *)rt.data)->color.bit.b);
	else
		printf("error rt!!");
	
}