/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mac_key_up.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 22:24:08 by kyoulee           #+#    #+#             */
/*   Updated: 2022/08/08 02:13:22 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_mac_keyboard.h>

int	ft_keyup_plus_min(int keycode, t_keyboard *keyboard)
{
	int	f;

	f = 0;
	if ((keycode == KEY_PLUS || keycode == KEY_P_PLUS) && ++f)
	{
		keyboard->zoom = 0;
	}
	else if ((keycode == KEY_MINUS || keycode == KEY_P_MINUS) && ++f)
	{
		keyboard->zoom = 0;
	}
	return (f);
}

int	ft_keyup_move(int keycode, t_keyboard *keyboard)
{
	int	f;

	f = 0;
	if ((keycode == KEY_ARROW_U || keycode == KEY_W) && ++f)
		keyboard->y = 0;
	else if ((keycode == KEY_ARROW_D || keycode == KEY_S) && ++f)
		keyboard->y = 0;
	else if ((keycode == KEY_ARROW_R || keycode == KEY_D) && ++f)
		keyboard->x = 0;
	else if ((keycode == KEY_ARROW_L || keycode == KEY_A) && ++f)
		keyboard->x = 0;
	return (f);
}

int	ft_keyup_option(int keycode, t_keyboard *keyboard)
{
	int	f;

	f = 0;
	if ((keycode == KEY_R_SHIFT || keycode == KEY_L_SHIFT || \
		keycode == KEY_NEW_R_SHIFT || keycode == KEY_NEW_L_SHIFT) && ++f)
		keyboard->shift = 0;
	return (f);
}

int	ft_keyup_exit(int keycode, t_keyboard *keyboard)
{
	int	f;

	f = 0;
	if (keycode == KEY_ESC && ++f)
		keyboard->exit++;
	return (f);
}
