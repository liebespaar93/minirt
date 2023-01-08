/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mac_mouse_down.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 22:30:33 by kyoulee           #+#    #+#             */
/*   Updated: 2022/08/23 11:08:45 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_mac_mouse.h>

int	ft_mouse_down_left(int keycode, int x, int y, t_mouse *mouse)
{
	int	f;

	f = 0;
	if (keycode == MOUSE_LEFT_BUTTON && ++f)
	{
		mouse->x_hold = x;
		mouse->y_hold = y;
		mouse->left = 1;
		mouse->right = 0;
		mouse->scroll = 0;
	}
	return (f);
}

int	ft_mouse_down_right(int keycode, int x, int y, t_mouse *mouse)
{
	int	f;

	f = 0;
	if (keycode == MOUSE_RIGHT_BUTTON && ++f)
	{
		mouse->x_hold = x;
		mouse->y_hold = y;
		mouse->left = 0;
		mouse->right = 1;
		mouse->scroll = 0;
	}
	return (f);
}

int	ft_mouse_down_scroll(int keycode, int x, int y, t_mouse *mouse)
{
	int	f;

	f = 0;
	if (keycode == MOUSE_SCROLL_BUTTON && ++f)
	{
		mouse->x_hold = x;
		mouse->y_hold = y;
		mouse->left = 0;
		mouse->right = 0;
		mouse->scroll = 1;
	}
	return (f);
}

int	ft_mouse_down_wheel(int keycode, int x, int y, t_mouse *mouse)
{
	int	f;

	f = 0;
	(void)x;
	(void)y;
	if (keycode == MOUSE_SCROLL_UP && ++f)
		mouse->zoom++;
	else if (keycode == MOUSE_SCROLL_DOWN && ++f)
		mouse->zoom--;
	return (f);
}
