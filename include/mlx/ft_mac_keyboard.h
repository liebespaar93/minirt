/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mac_keyboard.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 22:24:52 by kyoulee           #+#    #+#             */
/*   Updated: 2023/02/18 02:15:49 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MAC_KEYBOARD_H
# define FT_MAC_KEYBOARD_H

# include <mac_keycode.h>

typedef struct s_keyboard	t_keyboard;

typedef struct s_keyboard
{	
	int	x;
	int	y;
	int	z;

	int	zoom;
	int	shift;
	int	contour_line;
	int	exit;
}	t_keyboard;

t_keyboard	*ft_keyboard_set(void);

/* ft_mac_keyboard */
int			ft_key_up(int keycode, t_keyboard *keyboard);
int			ft_key_down(int keycode, t_keyboard *keyboard);

/* ft_mac_key_down.c */
int			ft_keydown_plus_min(int keycode, t_keyboard *keyboard);
int			ft_keydown_move(int keycode, t_keyboard *keyboard);
int			ft_keydown_option(int keycode, t_keyboard *keyboard);
int			ft_keydown_z_rotation(int keycode, t_keyboard *keyboard);

/* ft_mac_key_up.c */
int			ft_keyup_plus_min(int keycode, t_keyboard *keyboard);
int			ft_keyup_move(int keycode, t_keyboard *keyboard);
int			ft_keyup_option(int keycode, t_keyboard *keyboard);
int			ft_keyup_exit(int keycode, t_keyboard *keyboard);

/* ft_mac_key_hold */
void		ft_key_hold(t_keyboard *keyboard);
#endif
