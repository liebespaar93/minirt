/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 11:40:57 by kyoulee           #+#    #+#             */
/*   Updated: 2022/12/23 11:40:59 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

#include "ft_get_next_line.h"
#include "ft_minirt_tool.h"

t_read_line	*ft_new_read_line(char const *data)
{
	t_read_line	*new;

	if (!data || !ft_zeromalloc((void **)&new, sizeof(t_read_line)))
		return (NULL);
	new->data_size = ft_strlen(data);
	new->data = (char *)data;
	return (new);
}

t_read_line	*ft_read_line_add(t_read_line **read_line_ptr, char const *data)
{
	t_read_line	*new;
	t_read_line	*read_line;

	if (!data)
		return (NULL);
	read_line = *read_line_ptr;
	new = ft_new_read_line(data);
	if (!read_line)
	{
		*read_line_ptr = new;
		return (new);
	}
	while (read_line->next)
		read_line = read_line->next;
	read_line->next = new;
	new->prev = read_line;
	return (new);
}

t_read_file	*ft_read_file_free(t_read_file **read_file_ptr)
{
	t_read_file	*read_file;
	t_read_line	*read_line;
	t_read_line	*temp_free;

	read_file = *read_file_ptr;
	if (!read_file)
		return (NULL);
	if (read_file->line_head)
	{
		read_line = read_file->line_head;
		while (read_line)
		{
			temp_free = read_line;
			read_line = read_line->next;
			if (temp_free->data)
				free(temp_free->data);
			free(temp_free);
		}
	}
	free(read_file);
	*read_file_ptr = NULL;
	return (*read_file_ptr);
}

t_read_file	*ft_read_file(int fd)
{
	t_read_file	*read_file;
	t_read_line	*read_line;

	if (!ft_zeromalloc((void **)&read_file, sizeof(t_read_file)))
		return (NULL);
	read_line = ft_new_read_line(ft_get_next_line(fd));
	read_file->line_head = read_line;
	while (read_line && ++read_file->num_lines)
		read_line = ft_read_line_add(&read_line, ft_get_next_line(fd));
	close(fd);
	return (read_file);
}
