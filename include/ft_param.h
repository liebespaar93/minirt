/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_param.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 12:02:21 by kyoulee           #+#    #+#             */
/*   Updated: 2023/01/27 19:05:28 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PARAM_H
# define FT_PARAM_H

# ifndef WIN_WIDTH
# define WIN_WIDTH   100
# endif

# ifndef WIN_HEIGHT
# define WIN_HEIGHT  100
# endif

# define SCENE_X		0
# define SCENE_Y		0
# define SCENE_WIDTH	WIN_WIDTH
# define SCENE_HEIGHT	WIN_HEIGHT

# include <stdbool.h>

# include "mlx.h"
# include "ft_rt.h"
# include "ft_scene.h"

typedef struct s_mlx
{
	/* data */
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;

}	t_mlx;

typedef	struct s_renderer
{
	/* data */
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
}	t_param;

t_param	*ft_param_init(void);
void	ft_param_free(t_param **param_ptr);

#endif
