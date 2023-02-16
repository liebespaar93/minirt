/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scene_camera.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 15:01:47 by kyoulee           #+#    #+#             */
/*   Updated: 2023/02/17 05:11:44 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stdlib.h>

#include "ft_scene_camera.h"
#include "ft_minirt_tool.h"

t_scn_camera	*ft_scn_camera_set(t_rt	*rt)
{
	t_scn_camera	*camera_list;
	int				i;

	if (!ft_zeromalloc((void **)&camera_list, sizeof(t_scn_camera)))
		ft_exit_print_error(ENOMEM, "ft_camera_set()");
	i = -1;
	while (rt[++i].data)
		if (!ft_strcmp(rt[i].type, "C"))
			camera_list->max_index++;
	if (!ft_zeromalloc((void **)&camera_list->rt, \
		sizeof(t_rt *) * (camera_list->max_index + 1)))
		ft_exit_print_error(ENOMEM, "ft_camera_set()");
	i = -1;
	while (rt[++i].data)
		if (!ft_strcmp(rt[i].type, "C"))
			camera_list->rt[camera_list->index++] = &rt[i];
	camera_list->index = 0;
	if (!ft_strcmp(camera_list->rt[camera_list->index]->type, "C"))
		camera_list->camera = \
			(t_C *)(camera_list->rt[camera_list->index]->data);
	else
		ft_exit_print_error(EBADF, "ft_scn_camera_set()");
	return (camera_list);
}

void	ft_scn_camera_free(t_scn_camera	**camera_list_ptr)
{
	t_scn_camera	*camera_list;

	if (!camera_list_ptr)
		return ;
	camera_list = *camera_list_ptr;
	if (camera_list->rt)
		free(camera_list->rt);
	free(*camera_list_ptr);
	*camera_list_ptr = NULL;
}
