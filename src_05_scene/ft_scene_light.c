/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scene_light.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 15:01:53 by kyoulee           #+#    #+#             */
/*   Updated: 2023/02/17 05:06:53 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stdlib.h>

#include "ft_scene_light.h"
#include "ft_minirt_tool.h"

t_scn_light	*ft_scn_light_set(t_rt *rt)
{
	t_scn_light	*light;
	int			i;

	if (!ft_zeromalloc((void **)&light, sizeof(t_scn_light)))
		ft_exit_print_error(ENOMEM, "ft_camera_set()");
	i = 0;
	while (rt[i].data)
	{
		if (!ft_strcmp(rt[i].type, "A") || !ft_strcmp(rt[i].type, "L"))
			light->max_index++;
		i++;
	}
	if (!ft_zeromalloc((void **)&light->rt, \
		sizeof(t_rt *) * (light->max_index + 1)))
		ft_exit_print_error(ENOMEM, "ft_camera_set()");
	i = 0;
	while (rt[i].data)
	{
		if (!ft_strcmp(rt[i].type, "A") || !ft_strcmp(rt[i].type, "L"))
			light->rt[light->index++] = &rt[i];
		i++;
	}
	light->index = 0;
	return (light);
}

void	ft_scn_light_free(t_scn_light **light_ptr)
{
	t_scn_light	*light;

	if (!light_ptr)
		return ;
	light = *light_ptr;
	if (light->rt)
		free(light->rt);
	free(*light_ptr);
	*light_ptr = NULL;
}
