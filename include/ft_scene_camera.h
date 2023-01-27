/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scene_camera.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 15:00:11 by kyoulee           #+#    #+#             */
/*   Updated: 2023/01/27 18:36:11 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SCENE_CAMERA_H
# define FT_SCENE_CAMERA_H

# include "ft_rt.h"

typedef	struct s_scn_camera
{
	/* data */
	int		index;
	int		max_index;
	
	t_rt	**rt;
	
}	t_scn_camera;

t_scn_camera	*ft_scn_camera_set(t_rt	*rt);
void	ft_scn_camera_free(t_scn_camera	**camera_ptr);

#endif
