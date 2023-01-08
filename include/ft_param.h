/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_param.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 12:02:21 by kyoulee           #+#    #+#             */
/*   Updated: 2023/01/07 23:44:49 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PARAM_H
# define FT_PARAM_H

# ifndef WIN_WIDTH
# define WIN_WIDTH   11
# endif

# ifndef WIN_HEIGHT
# define WIN_HEIGHT  11
# endif

# define SCREEN_X		0
# define SCREEN_Y		0
# define SCREEN_WIDTH	WIN_WIDTH
# define SCREEN_HEIGHT	WIN_HEIGHT

# include "ft_rt.h"
# include "ft_screen.h"

typedef struct s_param	t_param;

typedef struct s_param
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	char		*buffer;
	char		*back_buffer;
	int			bits_per_pixel;
	int			size_line;
	int			endian;

	t_rt		*rt;
	t_screen	*screen;
	// t_basis2	*basis2;
	// t_mtx2		m2_angle;

	// t_ply		*ply;
	// t_ply		*ply_origin;

	// t_keyboard	*keyboard;
	// t_mouse		*mouse;

}	t_param;

t_param	ft_param_init(void);
void	ft_param_free(t_param *param_ptr);

#endif
