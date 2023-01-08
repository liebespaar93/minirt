/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_screen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 12:23:49 by kyoulee           #+#    #+#             */
/*   Updated: 2023/01/08 00:01:58 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <errno.h>

#include "ft_screen.h"
#include "ft_minirt_tool.h"
#include "ft_param.h"

t_C	**ft_screen_camera(t_rt *rt)
{
	t_C			**camera;
	t_rt		*temp;
	int			index;
	int			len;

	index = 0;
	len = 0;
	temp = rt;
	while (temp[index].data)
	{
		if (!ft_strcmp(temp[index].type, "C"))
			len++;
		index++;
	}
	if (!ft_zeromalloc((void **)&camera, (sizeof(t_C *) * len + 1)))
		ft_exit_error(ENOMEM);
	len = 0;
	index = 0;
	while (temp[index].data)
	{
		if (!ft_strcmp(temp[index].type, "C"))
			camera[len] = (t_C *)temp[index].data;
		index++;
	}
	return (camera);
}

t_screen	*ft_screen_init(t_rt *rt)
{
	t_screen	*screen;

	if (!ft_zeromalloc((void **)&screen, sizeof(t_screen)))
		ft_exit_error(ENOMEM);
	screen->index = 0;
	screen->w = SCREEN_WIDTH - SCREEN_WIDTH % 2 + 1;
	screen->h = SCREEN_WIDTH - SCREEN_HEIGHT % 2 + 1;
	screen->camera = ft_screen_camera(rt);
	if (!ft_zeromalloc((void **)&screen->pixel_axis, \
		sizeof(t_angles) * screen->h * screen->w))
		ft_exit_error(ENOMEM);
	return (screen);
}