/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rt_cylinder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 11:53:48 by kyoulee           #+#    #+#             */
/*   Updated: 2022/12/26 12:07:10 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <errno.h>

#include "ft_rt.h"
#include "ft_minirt_tool.h"

void	ft_rt_cylinder(t_rt *rt, char *str)
{
	t_cy	*rt_cy;
	int		index;
	char	**temp;

	rt_cy = malloc(sizeof(t_cy));
	if (!rt_cy)
		ft_exit_error(ENOMEM);
	temp = ft_split(str, ' ');
	if (ft_ptrlen((void **)&temp, "char **") != 6)
		ft_exit_error(EBADF);
	rt_cy->type = ft_strdup(temp[0]);
	rt_cy->coord = ft_rt_vec3(temp[1]);
	rt_cy->axis = ft_rt_vec3(temp[2]);
	rt_cy->diameter = ft_atof(temp[3]);
	rt_cy->height = ft_atof(temp[4]);
	rt_cy->color.integer = ft_rt_color(temp[5]);
	ft_split_free(temp);
	ft_rt_addback(rt, rt_cy->type, (void *)rt_cy);
}
