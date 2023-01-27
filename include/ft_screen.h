#ifndef FT_SCREEN_H
# define FT_SCREEN_H

# include "ft_rt.h"

typedef struct s_screen
{
	int			index;
	int			w;
	int			h;
	t_C			**camera;
	t_vec3	*pixel_axis;
} t_screen;

t_screen	*ft_screen_init(t_rt *rt);

#endif
