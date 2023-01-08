/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 11:14:24 by kyoulee           #+#    #+#             */
/*   Updated: 2022/12/23 11:51:03 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minirt_tool.h"

int	ft_ptrlen(void **ptr, char *type)
{
	int	len;

	len = 0;
	if (!ft_strcmp(type, "int **"))
		while (*((int **)(*ptr) + len))
			len++;
	else if (!ft_strcmp(type, "float **"))
		while (*((float **)(*ptr) + len))
			len++;
	else if (!ft_strcmp(type, "char **"))
		while (*((char **)(*ptr) + len))
			len++;
	return (len);
}
