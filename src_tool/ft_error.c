/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 10:00:10 by kyoulee           #+#    #+#             */
/*   Updated: 2022/12/23 11:27:37 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "ft_minirt_tool.h"

void	ft_exit_error(int error)
{
	char	*str_error;
	str_error = strerror(error);
	write(STDERR_FILENO, str_error, ft_strlen(str_error));
	exit(error);
}
