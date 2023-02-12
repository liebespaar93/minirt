/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_geometric_transform.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 15:27:27 by kyoulee           #+#    #+#             */
/*   Updated: 2023/02/12 06:28:24 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GEOMETRIC_TRANSFORM_H
# define FT_GEOMETRIC_TRANSFORM_H

# include <stdbool.h>
# include "ft_matrix.h"
# include "ft_quaternion.h"

typedef struct s_geometric_transform
{
	/* data */
	t_vec3			translation;
	t_quaternion	q_rotation;
	t_vec3			scaler;
	t_vec3			point;

	t_mtx4	forward_tf_mtx;
	t_mtx4	back_tf_mtx;
}	t_gt;

t_gt	ft_gt_default();
t_gt	ft_gt_set(t_vec3 translation, t_vec3 axis, t_vec3 scale);

void	ft_gt_transform(t_gt *gt);

t_vec3	ft_gt_apply_vec3(t_gt *gt, t_vec3 input_v3, bool dir_flag);

#endif
