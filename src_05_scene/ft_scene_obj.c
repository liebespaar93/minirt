/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scene_obj.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 15:01:55 by kyoulee           #+#    #+#             */
/*   Updated: 2023/02/12 04:32:14 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stdlib.h>

#include "ft_scene_obj.h"
#include "ft_minirt_tool.h"

t_scn_obj	*ft_scn_obj_set(t_rt *rt)
{
	t_scn_obj	*obj;
	int i;
	
	
	if (!ft_zeromalloc((void **)&obj, sizeof(t_scn_obj)))
		ft_exit_print_error(ENOMEM, "ft_camera_set()");

	i = 0;
	while (rt[i].data)
	{
		if (!ft_strcmp(rt[i].type, "pl") || \
			!ft_strcmp(rt[i].type, "sp") || \
			!ft_strcmp(rt[i].type, "cy"))
			obj->max_index++;
		i++;
	}
	if (!ft_zeromalloc((void **)&obj->rt, sizeof(t_rt *) * (obj->max_index + 1)))
		ft_exit_print_error(ENOMEM, "ft_camera_set()");
	i = 0;
	while (rt[i].data)
	{
		if (!ft_strcmp(rt[i].type, "pl") || \
			!ft_strcmp(rt[i].type, "sp") || \
			!ft_strcmp(rt[i].type, "cy"))
			obj->rt[obj->index++] = &rt[i];
		i++;
	}
	obj->index = 0;
	return (obj);	
}

void	ft_scn_obj_free(t_scn_obj **obj_ptr)
{
	t_scn_obj	*obj;

	if (!obj_ptr)
		return ;
	obj = *obj_ptr;
	if (obj->rt)
		free(obj->rt);
	free(*obj_ptr);
	*obj_ptr = NULL;
}
