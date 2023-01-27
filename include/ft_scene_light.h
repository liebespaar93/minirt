/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scene_light.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 14:50:28 by kyoulee           #+#    #+#             */
/*   Updated: 2023/01/27 15:38:30 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SCENE_LIGHT_H
# define FT_SCENE_LIGHT_H

# include "ft_rt.h"

typedef	struct s_scn_light
{
	/* data */
	int		index;
	int		max_index;

	t_rt	**rt;
	
}	t_scn_light;


t_scn_light	*ft_scn_light_set(t_rt *rt);
void	ft_scn_light_free(t_scn_light **light_ptr);

#endif
