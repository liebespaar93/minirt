/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mac_key_hold.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 22:22:20 by kyoulee           #+#    #+#             */
/*   Updated: 2023/01/29 14:49:05 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mac_keyboard.h"

void	ft_key_hold(t_keyboard *keyboard)
{
	keyboard->x += keyboard->x / 10;
	keyboard->y += keyboard->y / 10;
	keyboard->zoom += keyboard->zoom / 10;
	keyboard->contour_line += keyboard->contour_line / 10;
}
