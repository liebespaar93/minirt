/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rt_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 11:50:15 by kyoulee           #+#    #+#             */
/*   Updated: 2022/12/26 11:50:16 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <errno.h>

#include "ft_rt.h"
#include "ft_minirt_tool.h"

void	ft_rt_light(t_rt *rt, char *str)
{
	t_L		*rt_L;
	int		index;
	char	**temp;

	rt_L = malloc(sizeof(t_L));
	if (!rt_L)
		ft_exit_error(ENOMEM);
	temp = ft_split(str, ' ');
	if (ft_ptrlen((void **)&temp, "char **") != 4)
		ft_exit_error(EBADF);
	rt_L->type = ft_strdup(temp[0]);
	rt_L->coord = ft_rt_vec3(temp[1]);
	rt_L->ratio = ft_atof(temp[2]);
	rt_L->color.integer = ft_rt_color(temp[3]);
	ft_split_free(temp);
	ft_rt_addback(rt, rt_L->type, (void *)rt_L);
}