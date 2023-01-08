/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 09:35:58 by kyoulee           #+#    #+#             */
/*   Updated: 2023/01/07 23:35:53 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <fcntl.h>

#include "mlx.h"
#include "ft_fd.h"
#include "ft_minirt_tool.h"
#include "ft_get_next_line.h"
#include "ft_param.h"
#include "ft_rt.h"
#include "ft_draw.h"


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>



int	ft_loop_event(t_param *param)
{
	// if (ft_key_update(param->screan, param->keyboard) || \
	// 	ft_mouse_update(param->screan, param->mouse))
	// {
		ft_memset(param->back_buffer, 0, param->size_line * SCREEN_HEIGHT);
		ft_draw_ply(param);
		ft_memcpy(param->buffer, param->back_buffer, param->size_line * SCREEN_HEIGHT);
		mlx_put_image_to_window(param->mlx_ptr, param->win_ptr, param->img_ptr, SCREEN_X, SCREEN_Y);
	// }
	return (0);
}

int main(int argc, char const *argv[])
{
	t_param		param;
	t_read_file	*read_file;
	
	if (argc != 2)
		ft_exit_error(EINVAL);
	read_file = ft_read_file(ft_open_type(argv[1], O_RDONLY, ".rt"));
	if (!read_file)
		ft_exit_error(ENOMEM);
	param = ft_param_init();
	param.rt = ft_rt_init(read_file);
	ft_read_file_free(&read_file);
	
	param.screen = ft_screen_init(param.rt);


	int i = 0;
	while (param.rt[i].data)
		ft_rt_printf(param.rt[i++]);

	ft_draw_ply(&param);
	//ft_mlx_key_mouse_set(param);

	// mlx_loop_hook(param.mlx_ptr, ft_loop_event, &param);
	// mlx_loop(param.mlx_ptr);
	//ft_param_free(&param);
	system("leaks a.out");
	return (0);
}
