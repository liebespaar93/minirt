/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 10:00:10 by kyoulee           #+#    #+#             */
/*   Updated: 2023/01/27 14:15:53 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>

#include "ft_minirt_tool.h"

void	ft_exit_error(int error)
{
	char	*str_error;
	str_error = strerror(error);
	write(STDERR_FILENO, str_error, ft_strlen(str_error));
	exit(error);
}

void	ft_exit_print_error(int error, char *str)
{
	printf("ERROR: %s\n", str);
	ft_exit_error(error);
}
