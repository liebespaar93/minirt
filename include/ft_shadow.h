/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shadow.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 16:18:48 by kyoulee           #+#    #+#             */
/*   Updated: 2023/02/08 16:20:38 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FT_SHADOW_H
# define FT_SHADOW_H

# include "ft_intersection.h"
bool	ft_shadow(t_scene *scene, t_vec3 *coord, t_intersection *intersection_obj);

#endif
