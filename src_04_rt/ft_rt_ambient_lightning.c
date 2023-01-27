/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rt_ambient_lightning.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 11:06:20 by kyoulee           #+#    #+#             */
/*   Updated: 2023/01/27 16:28:49 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <errno.h>

#include "ft_rt.h"
#include "ft_minirt_tool.h"

void	ft_rt_ambient_lightning(t_rt *rt, char *str)
{
	t_A		*rt_A;
	//int		index;
	char	**temp;

	rt_A = malloc(sizeof(t_A));
	if (!rt_A)
		ft_exit_print_error(ENOMEM, "ft_rt_ambient_lightning()");
	temp = ft_split(str, ' ');
	if (ft_ptrlen((void **)&temp, "char **") != 3)
		ft_exit_print_error(EBADF, "ft_rt_ambient_lightning()");
	rt_A->type = ft_strdup(temp[0]);
	rt_A->ratio = ft_atof(temp[1]);
	rt_A->color.integer = ft_rt_color(temp[2]);
	ft_split_free(temp);
	ft_rt_addback(rt, rt_A->type, (void *)rt_A);
}


void	ft_rt_ambient_lightning_free(t_A **rt_A_ptr)
{
	t_A		*rt_A;

	if (!rt_A_ptr)
		return ;
	rt_A = *rt_A_ptr;
	if (rt_A->type)
		free(rt_A->type);
	free(*rt_A_ptr);
	*rt_A_ptr = NULL;
}
