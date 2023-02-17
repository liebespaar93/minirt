/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 11:41:12 by kyoulee           #+#    #+#             */
/*   Updated: 2023/02/17 04:09:14 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#include "ft_minirt_tool.h"

int	ft_open(char *filename, int option)
{
	int		fd;

	fd = open(filename, option);
	if (fd < 0)
		ft_exit_print_error(EBADF, "ft_open()");
	return (fd);
}

int	ft_open_type(const char *filename, int option, char *type)
{
	int		fd;
	int		len[2];

	len[0] = ft_strlen(filename);
	len[1] = ft_strlen(type);
	if (len[0] <= len[1])
		ft_exit_print_error(EBADF, "ft_open_type()");
	if (ft_memcmp(filename + len[0] - len[1], type, len[1]))
		ft_exit_print_error(EBADF, "ft_open_type()");
	fd = open(filename, option);
	if (fd < 0)
		ft_exit_print_error(EBADF, "ft_open_type()");
	return (fd);
}
