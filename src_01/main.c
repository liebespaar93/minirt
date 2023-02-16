/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 09:35:58 by kyoulee           #+#    #+#             */
/*   Updated: 2023/02/17 04:24:53 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <fcntl.h>

#include "mlx.h"

#include "ft_fd.h"
#include "ft_get_next_line.h"
#include "ft_param.h"
#include "ft_render.h"
#include "ft_minirt_tool.h"
#include "ft_quaternion.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	ft_key_update(t_scene *scene, t_keyboard *keyboard)
{
	t_C				*camera;
	t_vec3			v3_target;
	t_vec3			v3_move;

	v3_target = ft_vector_3(0.0, 0.0, 1.0);
	camera = scene->camera_list->camera;
	if (!keyboard->x && !keyboard->y && \
		!keyboard->contour_line && !keyboard->zoom && !keyboard->z)
		return (0);
	v3_move = ft_quaternion_rotate_vec3(camera->q_axis, v3_target);
	v3_move = ft_vec3_mult(v3_move, keyboard->y * -0.1);
	camera->coord = ft_vec3_sub(camera->coord, v3_move);
	keyboard->y = 0;
	v3_move = ft_quaternion_rotate_vec3(\
		camera->q_axis, ft_vector_3(1.0, 0.0, 0.0));
	v3_move = ft_vec3_mult(v3_move, keyboard->x * -0.1);
	camera->coord = ft_vec3_sub(camera->coord, v3_move);
	keyboard->x = 0;
	if (keyboard->z)
		camera->q_axis = ft_quaternion_normalize(\
			ft_quaternion_multiply(camera->q_axis, \
				ft_quaternion_rotation_z(keyboard->z * -0.1)));
	keyboard->z = 0;
	return (1);
}

int	ft_mouse_update(t_scene *scene, t_mouse *mouse)
{
	t_C				*camera;
	t_quaternion	r_x;
	t_quaternion	r_y;

	camera = scene->camera_list->camera;
	if (!mouse->x_angle && !mouse->y_angle)
		return (0);
	r_x = ft_quaternion_normalize(\
		ft_quaternion_rotation_y(mouse->x_angle * 0.01));
	r_y = ft_quaternion_normalize(\
		ft_quaternion_rotation_x(mouse->y_angle * 0.01));
	camera->q_axis = ft_quaternion_normalize(\
		ft_quaternion_multiply(camera->q_axis, r_x));
	camera->q_axis = ft_quaternion_normalize(\
		ft_quaternion_multiply(camera->q_axis, r_y));
	mouse->x_angle = 0;
	mouse->y_angle = 0;
	return (1);
}

void	ft_mlx_key_mouse_win_set(t_param *param)
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
	if (ft_key_update(param->scene, param->keyboard) || \
		ft_mouse_update(param->scene, param->mouse) \
		|| !param->frame)
	{
		ft_render(param);
		ft_memcpy(param->renderer->buffer, param->scene->image->back_buffer, \
			param->renderer->size_line * SCENE_H);
		mlx_put_image_to_window(param->mlx->mlx_ptr, param->mlx->win_ptr, \
			param->mlx->img_ptr, SCENE_X, SCENE_Y);
		param->frame = 1;
	}
	return (0);
}

int	main(int argc, char const *argv[])
{
	t_param		*param;
	t_read_file	*read_file;

	if (argc != 2)
		ft_exit_print_error(EINVAL, "main() 'argc != 2'");
	param = ft_param_init();
	read_file = ft_read_file(ft_open_type(argv[1], O_RDONLY, ".rt"));
	if (!read_file)
		ft_exit_error(ENOMEM);
	param->rt = ft_rt_init(read_file);
	ft_read_file_free(&read_file);
	param->scene = ft_scene_init(param->rt, SCENE_W, SCENE_H);
	ft_loop_event(param);
	ft_mlx_key_mouse_win_set(param);
	mlx_loop_hook(param->mlx->mlx_ptr, ft_loop_event, param);
	mlx_loop(param->mlx->mlx_ptr);
	system("leaks minirt");
	return (0);
}

/*
#include <sys/time.h>
#include <math.h>

int	ft_loop_event(t_param *param)
{
	t_C				*camera;
	t_vec3			axis;
	struct timeval	stop;
	struct timeval	start;
	t_vec3			v3_move;

	gettimeofday(&start, NULL);
	camera = param->scene->camera_list->camera;
	axis = ft_quaternion_to_euler_angles(camera->q_axis);
	if (ft_key_update(param->scene, param->keyboard) || \
		ft_mouse_update(param->scene, param->mouse))
	{
		ft_render(param);
		ft_memcpy(param->renderer->buffer, param->scene->image->back_buffer, \
			param->renderer->size_line * SCENE_H);
		mlx_put_image_to_window(param->mlx->mlx_ptr, param->mlx->win_ptr, \
			param->mlx->img_ptr, SCENE_X, SCENE_Y);
		gettimeofday(&stop, NULL);
		v3_move = ft_quaternion_rotate_vec3(camera->q_axis, \
			ft_vector_3(0.0, 0.0, -1.0));
		printf("╔════════════════════════════════╗\n");
		printf("║ 화면   : %-20d  ║\n", param->fram++);
		printf("║ 총시간 : %16ld m/s  ║\n", (stop.tv_sec - start.tv_sec) *\
		 1000000 + stop.tv_usec - start.tv_usec);
		printf("║ 위치   : %+6.2f,%+6.2f,%+6.2f  ║\n", camera->coord.x, \
		camera->coord.y, camera->coord.z);
		printf("║ 방향   : %+6.2f,%+6.2f,%+6.2f  ║\n", v3_move.x, \
		v3_move.y, v3_move.z);
		printf("║ 축회전 : %+6.2f,%+6.2f,%+6.2f  ║\n", axis.x / M_PI, \
		axis.y / M_PI, axis.z / M_PI);
		printf("╚════════════════════════════════╝\n");
	}
	return (0);
}
*/
