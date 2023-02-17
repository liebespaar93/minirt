/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mac_mouse_up.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 22:26:53 by kyoulee           #+#    #+#             */
/*   Updated: 2023/01/29 14:49:21 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mac_mouse.h"

int	ft_mouse_up_left(int keycode, int x, int y, t_mouse *mouse)
{
	int	f;

	f = 0;
	(void)x;
	(void)y;
	if (keycode == MOUSE_LEFT_BUTTON && ++f)
	{
		mouse->x_move = 0;
		mouse->y_move = 0;
		mouse->x_hold = 0;
		mouse->y_hold = 0;
		mouse->left = 0;
	}
	return (f);
}

int	ft_mouse_up_right(int keycode, int x, int y, t_mouse *mouse)
{
	int	f;

	f = 0;
	(void)x;
	(void)y;
	if (keycode == MOUSE_RIGHT_BUTTON && ++f)
	{
		mouse->x_hold = 0;
		mouse->y_hold = 0;
		mouse->right = 0;
	}
	return (f);
}

int	ft_mouse_up_scroll(int keycode, int x, int y, t_mouse *mouse)
{
	int	f;

	f = 0;
	(void)x;
	(void)y;
	if (keycode == MOUSE_SCROLL_BUTTON && ++f)
	{
		mouse->x_move = 0;
		mouse->y_move = 0;
		mouse->x_hold = 0;
		mouse->y_hold = 0;
		mouse->scroll = 0;
	}
	return (f);
}
