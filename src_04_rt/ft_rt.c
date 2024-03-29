/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rt.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 15:06:43 by kyoulee           #+#    #+#             */
/*   Updated: 2023/02/18 07:40:33 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <errno.h>
#include <stdio.h>

#include "ft_rt.h"
#include "ft_get_next_line.h"
#include "ft_minirt_tool.h"

size_t	ft_rt_len(t_read_file *ft_read_file)
{
	t_read_line	*read_line;
	size_t		len;

	len = 0;
	read_line = ft_read_file->line_head;
	while (read_line)
	{
		if (!ft_memcmp(read_line->data, "A ", ft_strlen("A ")) \
			|| !ft_memcmp(read_line->data, "C ", ft_strlen("C ")) \
			|| !ft_memcmp(read_line->data, "L ", ft_strlen("L ")) \
			|| !ft_memcmp(read_line->data, "sp ", ft_strlen("sp ")) \
			|| !ft_memcmp(read_line->data, "pl ", ft_strlen("pl ")) \
			|| !ft_memcmp(read_line->data, "cy ", ft_strlen("cy ")))
			len++;
		else if (*read_line->data == '\n' \
			|| !ft_memcmp(read_line->data, "//", ft_strlen("//")) \
			|| !ft_memcmp(read_line->data, "#", ft_strlen("#")))
			;
		else if (printf("line[%zu] : %s \n", len + 1, read_line->data))
			ft_exit_print_error(EBADF, "ft_rt_len()");
		read_line = read_line->next;
	}
	return (len);
}

void	ft_rt_addback(t_rt *rt, char *type, void *data)
{
	int	index;

	index = 0;
	while (rt[index].data)
		index++;
	rt[index].type = type;
	rt[index].data = data;
}

void	ft_rt_check(t_rt *rt)
{
	int	index;
	int	checker[2];

	index = 0;
	ft_memset(checker, 0, sizeof(int [2]));
	while (rt[index].data)
	{
		if (!ft_strcmp(rt[index].type, "A"))
			checker[0]++;
		else if (!ft_strcmp(rt[index].type, "C"))
			checker[1]++;
		index++;
	}
	index = 0;
	while (index < 2)
	{
		if (checker[index] != 1)
			ft_exit_print_error(EBADF, "ft_rt_check()");
		index++;
	}
}

t_rt	*ft_rt_init(t_read_file *read_file)
{
	t_rt		*rt;
	t_read_line	*read_line;

	if (!ft_zeromalloc((void **)&rt, sizeof(t_rt) * (ft_rt_len(read_file) + 1)))
		ft_exit_error(ENOMEM);
	read_line = read_file->line_head;
	while (read_line)
	{
		if (!ft_memcmp(read_line->data, "A ", ft_strlen("A ")))
			ft_rt_ambient_lightning(rt, read_line->data);
		else if (!ft_memcmp(read_line->data, "C ", ft_strlen("C ")))
			ft_rt_camera(rt, read_line->data);
		else if (!ft_memcmp(read_line->data, "L ", ft_strlen("L ")))
			ft_rt_light(rt, read_line->data);
		else if (!ft_memcmp(read_line->data, "sp ", ft_strlen("sp ")))
			ft_rt_sphere(rt, read_line->data);
		else if (!ft_memcmp(read_line->data, "pl ", ft_strlen("pl ")))
			ft_rt_plane(rt, read_line->data);
		else if (!ft_memcmp(read_line->data, "cy ", ft_strlen("cy ")))
			ft_rt_cylinder(rt, read_line->data);
		read_line = read_line->next;
	}
	ft_rt_check(rt);
	return (rt);
}

void	ft_rt_free(t_rt **rt_ptr)
{
	t_rt	*rt;
	int		i;

	if (!rt_ptr)
		return ;
	rt = *rt_ptr;
	i = 0;
	while (rt[i].type)
	{
		if (!ft_strcmp(rt[i].type, "A"))
			ft_rt_ambient_lightning_free((t_A **)&rt[i].data);
		else if (!ft_strcmp(rt[i].type, "C"))
			ft_rt_camera_free((t_C **)&rt[i].data);
		else if (!ft_strcmp(rt[i].type, "L"))
			ft_rt_light_free((t_L **)&rt[i].data);
		else if (!ft_strcmp(rt[i].type, "sp"))
			ft_rt_sphere_free((t_sp **)&rt[i].data);
		else if (!ft_strcmp(rt[i].type, "pl"))
			ft_rt_plane_free((t_pl **)&rt[i].data);
		else if (!ft_strcmp(rt[i].type, "cy"))
			ft_rt_cylinder_free((t_cy **)&rt[i].data);
		i++;
	}
	free(*rt_ptr);
	*rt_ptr = NULL;
}
