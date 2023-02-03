/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mac_key_down.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 22:24:24 by kyoulee           #+#    #+#             */
/*   Updated: 2023/02/03 18:21:57 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mac_keyboard.h"
#include <stdlib.h>

int	ft_keydown_plus_min(int keycode, t_keyboard *keyboard)
{
	int	f;

	f = 0;
	if ((keycode == KEY_PLUS || keycode == KEY_P_PLUS) && ++f)
	{
		if (keyboard->shift)
			keyboard->contour_line++;
		else
			keyboard->zoom++;
	}
	else if ((keycode == KEY_MINUS || keycode == KEY_P_MINUS) && ++f)
	{
		if (keyboard->shift)
			keyboard->contour_line--;
		else
			keyboard->zoom--;
	}
	return (f);
}

int	ft_keydown_move(int keycode, t_keyboard *keyboard)
{
	int	f;

	f = 0;
	if ((keycode == KEY_ARROW_U || keycode == KEY_W) && ++f)
		keyboard->y--;
	else if ((keycode == KEY_ARROW_D || keycode == KEY_S) && ++f)
		keyboard->y++;
	else if ((keycode == KEY_ARROW_R || keycode == KEY_D) && ++f)
		keyboard->x++;
	else if ((keycode == KEY_ARROW_L || keycode == KEY_A) && ++f)
		keyboard->x--;
	return (f);
}

int	ft_keydown_option(int keycode, t_keyboard *keyboard)
{
	int	f;

	f = 0;
	if (keycode == KEY_R_SHIFT || keycode == KEY_L_SHIFT || \
		keycode == KEY_NEW_R_SHIFT || keycode == KEY_NEW_L_SHIFT)
	{
		keyboard->shift = 1;
		f++;
	}
	else if (keycode == KEY_ESC && ++f)
		exit(1);
	return (f);
}

int	ft_keydown_z_rotation(int keycode, t_keyboard *keyboard)
{
	int	f;

	f = 0;
	if (keycode == KEY_Q)
	{
		keyboard->z = -1;
		f++;
	}
	else if (keycode == KEY_E)
	{
		keyboard->z = 1;
		f++;
	}
	return (f);
}
