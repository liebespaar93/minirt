/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_geometric_transform.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 15:36:39 by kyoulee           #+#    #+#             */
/*   Updated: 2023/02/18 02:01:27 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <errno.h>
#include <math.h>

#include "ft_geometric_transform.h"
#include "ft_minirt_tool.h"

t_gt	ft_gt_default(void)
{
	t_gt	gt;

	gt.translation = ft_vector_3(0.0, 0.0, 0.0);
	gt.q_rotation = ft_quaternion_from_euler_angles(ft_vector_3(0.0, 0.0, 1.0));
	gt.scaler = ft_vector_3(1.0, 1.0, 1.0);
	gt.forward_tf_mtx = ft_mtx4_identity();
	gt.back_tf_mtx = ft_mtx4_identity();
	return (gt);
}

t_gt	ft_gt_set(t_vec3 translation, t_vec3 axis, t_vec3 scale)
{
	t_gt	gt;

	gt = ft_gt_default();
	gt.translation = translation;
	gt.q_rotation = ft_quaternion_from_euler_angles(ft_vec3_mult(axis, M_PI));
	gt.scaler = scale;
	gt.point = ft_quaternion_rotate_vec3(\
		gt.q_rotation, ft_vector_3(0.0, 0.0, 1.0));
	ft_gt_transform(&gt);
	return (gt);
}

void	ft_gt_transform(t_gt *gt)
{
	t_mtx4	translation_mtx;
	t_mtx4	rotation_mtx;
	t_mtx4	scale_mtx;

	translation_mtx = ft_mtx4_translation(\
		gt->translation.x, gt->translation.y, gt->translation.z);
	rotation_mtx = ft_mtx3_to_mtx4(ft_quaternion_rotate_matrix(gt->q_rotation));
	scale_mtx = ft_mtx4_scale(gt->scaler.x, gt->scaler.y, gt->scaler.z);
	gt->forward_tf_mtx = ft_mtx4_mult_mtx4(gt->forward_tf_mtx, scale_mtx);
	gt->forward_tf_mtx = ft_mtx4_mult_mtx4(gt->forward_tf_mtx, rotation_mtx);
	gt->forward_tf_mtx = ft_mtx4_mult_mtx4(gt->forward_tf_mtx, translation_mtx);
	gt->back_tf_mtx = ft_mtx4_inverse(gt->forward_tf_mtx);
}

t_vec3	ft_gt_apply_vec3(t_gt *gt, t_vec3 input_v3, bool dir_flag)
{
	t_vec3	output_v3;

	if (dir_flag)
		output_v3 = ft_mtx4_mult_vec3(gt->forward_tf_mtx, input_v3);
	else
		output_v3 = ft_mtx4_mult_vec3(gt->back_tf_mtx, input_v3);
	return (output_v3);
}
