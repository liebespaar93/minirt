#ifndef FT_SCREEN_H
# define FT_SCREEN_H

# include "ft_rt.h"
# include "ft_quaternion.h"

typedef struct s_screen
{
	int			index;
	int			w;
	int			h;
	t_C			**camera;
	t_angles	*pixel_axis;
} t_screen;

t_screen	*ft_screen_init(t_rt *rt);

#endif
