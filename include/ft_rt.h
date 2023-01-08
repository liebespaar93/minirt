/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rt.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 14:31:13 by kyoulee           #+#    #+#             */
/*   Updated: 2022/12/28 13:28:11 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RT_H
# define FT_RT_H

# include "ft_get_next_line.h"
# include "ft_vector.h"

typedef struct s_rt
{
	char	*type;
	void	*data;
}	t_rt;

typedef struct s_A
{
	char	*type;
	double	ratio;
	t_color	color;
}	t_A;

typedef struct s_C
{
	char	*type;
	t_vec3	coord;
	t_vec3	axis;
	double	fov;
}	t_C;

typedef struct s_L
{
	char	*type;
	t_vec3	coord;
	double	ratio;
	t_color	color;
}	t_L;

typedef struct s_sp
{
	char	*type;
	t_vec3	coord;
	double	diameter;
	t_color	color;
}	t_sp;

typedef struct s_pl
{
	char	*type;
	t_vec3	coord;
	t_vec3	axis;
	t_color	color;
}	t_pl;

typedef struct s_cy
{
	char	*type;
	t_vec3	coord;
	t_vec3	axis;
	double	diameter;
	double	height;
	t_color	color;
}	t_cy;


t_rt	*ft_rt_init(t_read_file *read_file);

void ft_rt_addback(t_rt *rt, char *type, void *data);

int	ft_rt_color(char *str);
t_vec3	ft_rt_vec3(char *str);



void	ft_rt_ambient_lightning(t_rt *rt, char *str);
void	ft_rt_camera(t_rt *rt, char *str);
void	ft_rt_light(t_rt *rt, char *str);
void	ft_rt_sphere(t_rt *rt, char *str);
void	ft_rt_plane(t_rt *rt, char *str);
void	ft_rt_cylinder(t_rt *rt, char *str);


void	ft_rt_printf(t_rt rt);

#endif
