/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mac_mouse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 22:30:14 by kyoulee           #+#    #+#             */
/*   Updated: 2022/08/06 01:41:08 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_mac_mouse.h>

int	ft_mouse_up(int keycode, int x, int y, t_mouse *mouse)
{
	if (ft_mouse_up_left(keycode, x, y, mouse))
		return (1);
	if (ft_mouse_up_right(keycode, x, y, mouse))
		return (1);
	if (ft_mouse_up_scroll(keycode, x, y, mouse))
		return (1);
	return (0);
}

int	ft_mouse_down(int keycode, int x, int y, t_mouse *mouse)
{
	if (ft_mouse_down_left(keycode, x, y, mouse))
		return (1);
	if (ft_mouse_down_right(keycode, x, y, mouse))
		return (1);
	if (ft_mouse_down_scroll(keycode, x, y, mouse))
		return (1);
	if (ft_mouse_down_wheel(keycode, x, y, mouse))
		return (1);
	return (0);
}

int	ft_mouse_drag(int x, int y, t_mouse *mouse)
{
	if (ft_mouse_drag_move(x, y, mouse))
		return (1);
	else if (ft_mouse_drag_angle(x, y, mouse))
		return (1);
	return (0);
}
