/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mac_keyboard.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 22:23:44 by kyoulee           #+#    #+#             */
/*   Updated: 2022/09/13 08:28:06 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_mac_keyboard.h>

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
