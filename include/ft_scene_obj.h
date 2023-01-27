/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scene_obj.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 14:59:19 by kyoulee           #+#    #+#             */
/*   Updated: 2023/01/27 15:39:26 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FT_SCENE_OBJ_H
# define FT_SCENE_OBJ_H

# include "ft_rt.h"

typedef	struct s_scn_obj
{
	/* data */
	int		index;
	int		max_index;

	t_rt	**rt;
	
}	t_scn_obj;


t_scn_obj	*ft_scn_obj_set(t_rt *rt);
void	ft_scn_obj_free(t_scn_obj **obj_ptr);
#endif
