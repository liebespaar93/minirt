/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_param.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 13:58:32 by kyoulee           #+#    #+#             */
/*   Updated: 2023/02/17 05:03:54 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <errno.h>

#include "mlx.h"

#include "ft_param.h"
#include "ft_minirt_tool.h"

t_mlx	*ft_mlx_set(void)
{
	t_mlx	*mlx;

	if (!ft_zeromalloc((void **)&mlx, sizeof(t_mlx)))
		ft_exit_print_error(ENOMEM, "ft_mlx_set()");
	mlx->mlx_ptr = mlx_init();
	if (!mlx->mlx_ptr)
		ft_exit_print_error(EFAULT, "mlx_init()");
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, WIN_W, WIN_H, "minirt 0.8v");
	mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
	if (!mlx->win_ptr)
		ft_exit_print_error(EFAULT, "mlx_new_window()");
	mlx->img_ptr = mlx_new_image(mlx->mlx_ptr, SCENE_W, SCENE_H);
	if (!mlx->img_ptr)
		ft_exit_print_error(EFAULT, "mlx_new_image()");
	return (mlx);
}

t_renderer	*ft_renderer_set(void *img_ptr)
{
	t_renderer	*renderer;

	if (!ft_zeromalloc((void **)&renderer, sizeof(t_renderer)))
		ft_exit_print_error(ENOMEM, "ft_renderer_set()");
	renderer->buffer = mlx_get_data_addr(\
		img_ptr, \
		&renderer->bits_per_pixel, \
		&renderer->size_line, \
		&renderer->endian);
	if (!renderer->buffer)
		ft_exit_print_error(EFAULT, "ft_renderer_set() -> mlx_get_data_addr()");
	return (renderer);
}

t_param	*ft_param_init(void)
{
	t_param	*param;

	if (!ft_zeromalloc((void **)&param, sizeof(t_param)))
		ft_exit_print_error(ENOMEM, "ft_app_set()");
	param->isrunning = true;
	param->mlx = ft_mlx_set();
	param->renderer = ft_renderer_set(param->mlx->img_ptr);
	param->scene = NULL;
	param->keyboard = ft_keyboard_set();
	param->mouse = ft_mouse_set();
	return (param);
}

void	ft_mlx_free(t_mlx **mlx_ptr)
{
	t_mlx	*mlx;

	if (!mlx_ptr)
		return ;
	mlx = *mlx_ptr;
	if (mlx->img_ptr)
		mlx_destroy_image(mlx->mlx_ptr, mlx->img_ptr);
	if (mlx->win_ptr)
		mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	if (mlx->mlx_ptr)
		mlx_del(mlx->mlx_ptr);
	free(*mlx_ptr);
	mlx_ptr = NULL;
}

void	ft_param_free(t_param **param_ptr)
{
	t_param	*param;

	if (!param_ptr)
		return ;
	param = *param_ptr;
	if (param->mlx)
		ft_mlx_free(&param->mlx);
	if (param->renderer)
		free(param->renderer);
	if (param->rt)
		ft_rt_free(&param->rt);
	if (param->scene)
		ft_scene_free(&param->scene);
	free(*param_ptr);
	*param_ptr = NULL;
}
