/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rt_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 11:50:23 by kyoulee           #+#    #+#             */
/*   Updated: 2022/12/26 12:07:18 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <errno.h>

#include "ft_rt.h"
#include "ft_minirt_tool.h"

void	ft_rt_sphere(t_rt *rt, char *str)
{
	t_sp	*rt_sp;
	int		index;
	char	**temp;

	rt_sp = malloc(sizeof(t_sp));
	if (!rt_sp)
		ft_exit_error(ENOMEM);
	temp = ft_split(str, ' ');
	if (ft_ptrlen((void **)&temp, "char **") != 4)
		ft_exit_error(EBADF);
	rt_sp->type = ft_strdup(temp[0]);
	rt_sp->coord = ft_rt_vec3(temp[1]);
	rt_sp->diameter = ft_atof(temp[2]);
	rt_sp->color.integer = ft_rt_color(temp[3]);
	ft_split_free(temp);
	ft_rt_addback(rt, rt_sp->type, (void *)rt_sp);
}