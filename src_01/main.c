/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 09:35:58 by kyoulee           #+#    #+#             */
/*   Updated: 2023/01/29 16:41:47 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <fcntl.h>

#include "mlx.h"

#include "ft_fd.h"
#include "ft_get_next_line.h"

#include "ft_param.h"

#include "ft_draw.h"

#include "ft_minirt_tool.h"

#include "ft_quaternion.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int	ft_key_update(t_scene *scene, t_keyboard *keyboard)
{
	t_C		*camera;

	t_vec3	v3_target;
	t_quaternion	q;

	t_vec3	v3_move;
	
	v3_target = ft_vector_3(0.0,0.0,1.0);

	camera = scene->camera_list->camera;
	if (!keyboard->x && !keyboard->y && \
		!keyboard->contour_line && !keyboard->zoom)
		return (0);
	
	q = ft_quaternion_from_euler_angles(camera->axis);
	
	v3_move = ft_quaternion_rotate_vec3(q, v3_target);
	v3_move = ft_vec3_mult(v3_move, keyboard->y);
	camera->coord = ft_vec3_sub(camera->coord, v3_move);
	keyboard->y = 0;
	return (1);
}

int	ft_mouse_update(t_scene *scene, t_mouse *mouse)
{
	t_vec3	v3;
	t_C		*camera;

	t_quaternion	q;
	t_quaternion	r_x;
	t_quaternion	r_y;
	t_quaternion	out_1;
	t_quaternion	out_2;

	camera = scene->camera_list->camera;
	if (!mouse->x_angle && !mouse->y_angle)
		return (0);
	v3 = ft_vector_3(mouse->x_move, mouse->y_move, 0.0);


	q = ft_quaternion_from_euler_angles(camera->axis);

	r_x = ft_quaternion_rotation_y(mouse->x_angle * 0.01);
	r_y = ft_quaternion_rotation_x(mouse->y_angle * 0.01);

	out_1 = ft_quaternion_multiply(q, r_x);
	out_2 = ft_quaternion_multiply(out_1, r_y);
	camera->axis = ft_quaternion_to_euler_angles(out_2);
	mouse->x_angle = 0;
	mouse->y_angle = 0;
	return (1);
}


int	ft_window(t_mouse *mouse)
{
	(void) mouse;
	exit(1);
	return (0);
}

void	ft_mlx_key_mouse_set(t_param *param)
{
	mlx_hook(param->mlx->win_ptr, 2, 0, ft_key_down, param->keyboard);
	mlx_key_hook(param->mlx->win_ptr, ft_key_up, param->keyboard);
	mlx_mouse_hook(param->mlx->win_ptr, ft_mouse_down, param->mouse);
	mlx_hook(param->mlx->win_ptr, 5, 0, ft_mouse_up, param->mouse);
	mlx_hook(param->mlx->win_ptr, 6, 0, ft_mouse_drag, param->mouse);
	mlx_hook(param->mlx->win_ptr, 17, 0, ft_window, param->mouse);
}

int	ft_loop_event(t_param *param)
{
	t_C	*camera;
	camera = param->scene->camera_list->camera;
	//param->keyboard->y++;
	if (ft_key_update(param->scene, param->keyboard) || \
		ft_mouse_update(param->scene, param->mouse))
	{
		printf("%.2f %.2f %.2f , %.2f %.2f %.2f \n", camera->axis.x, camera->axis.y, camera->axis.z, camera->coord.x, camera->coord.y, camera->coord.z);
		ft_memset(param->scene->image->back_buffer, 0, param->renderer->size_line * SCENE_HEIGHT);
		ft_draw_ply(param);
		ft_memcpy(param->renderer->buffer, param->scene->image->back_buffer, param->renderer->size_line * SCENE_HEIGHT);
		mlx_put_image_to_window(param->mlx->mlx_ptr, param->mlx->win_ptr, param->mlx->img_ptr, SCENE_X, SCENE_Y);
	}
	return (0);
}

int main(int argc, char const *argv[])
{
	t_param		*param;
	t_read_file	*read_file;
	
	param = ft_param_init();

	if (argc != 2)
		ft_exit_error(EINVAL);
		
	read_file = ft_read_file(ft_open_type(argv[1], O_RDONLY, ".rt"));
	if (!read_file)
		ft_exit_error(ENOMEM);
	param->rt = ft_rt_init(read_file);
	ft_read_file_free(&read_file);

	int i = 0;
	while (param->rt[i].type)
	{
		printf("%d : ", i);
		ft_rt_printf(param->rt[i++]);
	}

	param->scene = ft_scene_init(param->rt, SCENE_WIDTH, SCENE_HEIGHT);
	ft_loop_event(param);
	ft_mlx_key_mouse_set(param);

	mlx_loop_hook(param->mlx->mlx_ptr, ft_loop_event, param);
	mlx_loop(param->mlx->mlx_ptr);
	// ft_param_free(&param);
	system("leaks minirt");
	return (0);
}
