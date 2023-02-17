/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rt_ambient_lightning.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 11:06:20 by kyoulee           #+#    #+#             */
/*   Updated: 2023/02/17 04:35:57 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <errno.h>

#include "ft_rt.h"
#include "ft_minirt_tool.h"

void	ft_rt_ambient_lightning(t_rt *rt, char *str)
{
	t_A		*rt_a;
	char	**temp;

	rt_a = malloc(sizeof(t_A));
	if (!rt_a)
		ft_exit_print_error(ENOMEM, "ft_rt_ambient_lightning()");
	temp = ft_split(str, ' ');
	if (ft_ptrlen((void **)&temp, "char **") != 3)
		ft_exit_print_error(EBADF, "ft_rt_ambient_lightning()");
	rt_a->type = ft_strdup(temp[0]);
	rt_a->ratio = ft_atof(temp[1]);
	rt_a->color = ft_rt_color(temp[2]);
	ft_split_free(temp);
	ft_rt_addback(rt, rt_a->type, (void *)rt_a);
}

void	ft_rt_ambient_lightning_free(t_A **rt_a_ptr)
{
	t_A		*rt_a;

	if (!rt_a_ptr)
		return ;
	rt_a = *rt_a_ptr;
	if (rt_a->type)
		free(rt_a->type);
	free(*rt_a_ptr);
	*rt_a_ptr = NULL;
}
