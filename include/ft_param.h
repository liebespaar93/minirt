/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_param.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 12:02:21 by kyoulee           #+#    #+#             */
/*   Updated: 2023/02/18 04:11:14 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PARAM_H
# define FT_PARAM_H

# ifndef WIN_W
#  define WIN_W   600
# endif

# ifndef WIN_H
#  define WIN_H  300
# endif

# define SCENE_X		0
# define SCENE_Y		0
# define SCENE_W	WIN_W
# define SCENE_H	WIN_H

# include <stdbool.h>

# include "mlx.h"
# include "ft_rt.h"
# include "ft_scene.h"
# include "ft_mac_keyboard.h"
# include "ft_mac_mouse.h"
# include "ft_mac_win.h"

typedef struct s_mlx
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;

}	t_mlx;

typedef struct s_renderer
{
	char		*buffer;
	int			bits_per_pixel;
	int			size_line;
	int			endian;

}	t_renderer;

typedef struct s_param
{
	bool		isrunning;
	t_mlx		*mlx;
	t_renderer	*renderer;

	t_rt		*rt;

	t_scene		*scene;

	t_keyboard	*keyboard;
	t_mouse		*mouse;
}	t_param;

t_param	*ft_param_init(void);
void	ft_param_free(t_param **param_ptr);

#endif
