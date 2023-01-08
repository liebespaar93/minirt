/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mac_mouse.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 22:28:32 by kyoulee           #+#    #+#             */
/*   Updated: 2022/08/05 22:30:10 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MAC_MOUSE_H
# define FT_MAC_MOUSE_H

# include <mac_mousecode.h>

typedef struct s_mouse
{
	int		x_hold;
	int		y_hold;

	int		left;
	int		right;
	int		scroll;

	int		x_move;
	int		y_move;
	int		x_angle;
	int		y_angle;
	int		zoom;
}	t_mouse;

/* ft_mac_mouse_up */
int	ft_mouse_up_left(int keycode, int x, int y, t_mouse *mouse);
int	ft_mouse_up_right(int keycode, int x, int y, t_mouse *mouse);
int	ft_mouse_up_scroll(int keycode, int x, int y, t_mouse *mouse);

/* ft_mac_mouse_down */
int	ft_mouse_down_left(int keycode, int x, int y, t_mouse *mouse);
int	ft_mouse_down_right(int keycode, int x, int y, t_mouse *mouse);
int	ft_mouse_down_scroll(int keycode, int x, int y, t_mouse *mouse);
int	ft_mouse_down_wheel(int keycode, int x, int y, t_mouse *mouse);

/* ft_mac_mouse_draw */
int	ft_mouse_drag_move(int x, int y, t_mouse *mouse);
int	ft_mouse_drag_angle(int x, int y, t_mouse *mouse);

/* ft_mac_mouse */
int	ft_mouse_up(int keycode, int x, int y, t_mouse *mouse);
int	ft_mouse_down(int keycode, int x, int y, t_mouse *mouse);
int	ft_mouse_drag(int x, int y, t_mouse *mouse);

#endif