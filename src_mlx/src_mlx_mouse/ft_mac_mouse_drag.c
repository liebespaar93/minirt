/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mac_mouse_drag.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 22:26:07 by kyoulee           #+#    #+#             */
/*   Updated: 2023/01/29 14:49:21 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mac_mouse.h"

int	ft_mouse_drag_move(int x, int y, t_mouse *mouse)
{
	int	f;

	f = 0;
	if (mouse->left && ++f)
	{
		mouse->x_move = x - mouse->x_hold;
		mouse->y_move = y - mouse->y_hold;
		mouse->x_hold = x;
		mouse->y_hold = y;
	}
	return (f);
}

int	ft_mouse_drag_angle(int x, int y, t_mouse *mouse)
{
	int	f;

	f = 0;
	if (mouse->right && ++f)
	{
		mouse->x_angle += x - mouse->x_hold;
		mouse->y_angle += y - mouse->y_hold;
		mouse->x_hold = x;
		mouse->y_hold = y;
	}
	return (f);
}
