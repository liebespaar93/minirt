/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scene_camera.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 15:01:47 by kyoulee           #+#    #+#             */
/*   Updated: 2023/01/27 18:54:46 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stdlib.h>

#include "ft_scene_camera.h"
#include "ft_minirt_tool.h"

t_scn_camera	*ft_scn_camera_set(t_rt	*rt)
{
	t_scn_camera	*camera;
	int i;
	
	
	if (!ft_zeromalloc((void **)&camera, sizeof(t_scn_camera)))
		ft_exit_print_error(ENOMEM, "ft_camera_set()");

	i = 0;
	while (rt[i].data)
	{
		if (!ft_strcmp(rt[i].type, "C"))
			camera->max_index++;
		i++;
	}
	if (!ft_zeromalloc((void **)&camera->rt, sizeof(t_rt *) * (camera->max_index + 1)))
		ft_exit_print_error(ENOMEM, "ft_camera_set()");
	i = 0;
	while (rt[i].data)
	{
		if (!ft_strcmp(rt[i].type, "C"))
			camera->rt[camera->index++] = rt[i].data;	
		i++;
	}
	camera->index = 0;
	return (camera);
}

void	ft_scn_camera_free(t_scn_camera	**camera_ptr)
{
	t_scn_camera	*camera;

	if (!camera_ptr)
		return ;
	camera = *camera_ptr;
	if (camera->rt)
		free(camera->rt);
	free(*camera_ptr);
	*camera_ptr = NULL;
}

