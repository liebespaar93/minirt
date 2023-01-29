/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mac_keyboard.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 22:23:44 by kyoulee           #+#    #+#             */
/*   Updated: 2023/01/29 14:48:38 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>

#include "ft_mac_keyboard.h"
#include "ft_minirt_tool.h"

t_keyboard	*ft_keyboard_set()
{
	t_keyboard	*keyboard;

	if (!ft_zeromalloc((void **)&keyboard, sizeof(t_keyboard)))
		ft_exit_print_error(ENOMEM, "ft_keyboard_set()");

	return (keyboard);
}

int	ft_key_up(int keycode, t_keyboard *keyboard)
{
	if (ft_keyup_plus_min(keycode, keyboard))
		return (1);
	if (ft_keyup_move(keycode, keyboard))
		return (1);
	if (ft_keyup_option(keycode, keyboard))
		return (1);
	if (ft_keyup_exit(keycode, keyboard))
		return (1);
	return (0);
}

int	ft_key_down(int keycode, t_keyboard *keyboard)
{
	if (ft_keydown_plus_min(keycode, keyboard))
		return (1);
	if (ft_keydown_move(keycode, keyboard))
		return (1);
	if (ft_keydown_option(keycode, keyboard))
		return (1);
	return (0);
}
