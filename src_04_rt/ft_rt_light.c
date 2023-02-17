/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rt_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 11:50:15 by kyoulee           #+#    #+#             */
/*   Updated: 2023/02/17 04:35:43 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <errno.h>

#include "ft_rt.h"
#include "ft_minirt_tool.h"

void	ft_rt_light(t_rt *rt, char *str)
{
	t_L		*rt_l;
	char	**temp;

	rt_l = malloc(sizeof(t_L));
	if (!rt_l)
		ft_exit_print_error(ENOMEM, "ft_rt_light()");
	temp = ft_split(str, ' ');
	if (ft_ptrlen((void **)&temp, "char **") != 4)
		ft_exit_print_error(EBADF, "ft_rt_light()");
	rt_l->type = ft_strdup(temp[0]);
	rt_l->coord = ft_rt_vec3(temp[1]);
	rt_l->ratio = ft_atof(temp[2]);
	rt_l->color = ft_rt_color(temp[3]);
	ft_split_free(temp);
	ft_rt_addback(rt, rt_l->type, (void *)rt_l);
}

void	ft_rt_light_free(t_L **rt_l_ptr)
{
	t_L	*rt_l;

	if (!rt_l_ptr)
		return ;
	rt_l = *rt_l_ptr;
	if (rt_l->type)
		free(rt_l->type);
	free(*rt_l_ptr);
	*rt_l_ptr = NULL;
}
