/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mac_key_hold.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 22:22:20 by kyoulee           #+#    #+#             */
/*   Updated: 2022/08/05 22:22:49 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_mac_keyboard.h>

void	ft_key_hold(t_keyboard *keyboard)
{
	keyboard->x += keyboard->x / 10;
	keyboard->y += keyboard->y / 10;
	keyboard->zoom += keyboard->zoom / 10;
	keyboard->contour_line += keyboard->contour_line / 10;
}
