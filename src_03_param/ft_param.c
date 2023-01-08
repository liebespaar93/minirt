/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_param.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 13:58:32 by kyoulee           #+#    #+#             */
/*   Updated: 2022/12/29 13:18:31 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <errno.h>
#include <mlx.h>

#include "ft_minirt_tool.h"
#include "ft_param.h"

void	ft_param_free(t_param *param_ptr)
{
	if (param_ptr)
	{
		if (param_ptr->img_ptr)
			mlx_destroy_image(param_ptr->mlx_ptr, param_ptr->img_ptr);
		if (param_ptr->win_ptr)
			mlx_destroy_window(param_ptr->mlx_ptr, param_ptr->win_ptr);
	}
}

t_param	ft_param_init(void)
{
	t_param	param;

	param.mlx_ptr = mlx_init();
	param.win_ptr = mlx_new_window(param.mlx_ptr, WIN_WIDTH, WIN_HEIGHT, \
		"minirt 0.3v");
	param.img_ptr = mlx_new_image(param.mlx_ptr, SCREEN_WIDTH, SCREEN_HEIGHT);
	param.buffer = mlx_get_data_addr(param.img_ptr, &param.bits_per_pixel, \
		&param.size_line, &param.endian);
	if (!ft_zeromalloc((void **)&param.back_buffer, param.size_line * SCREEN_HEIGHT))
		ft_exit_error(ENOMEM);
	return (param);
}
