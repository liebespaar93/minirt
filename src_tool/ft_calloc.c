/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 12:32:17 by kyoulee           #+#    #+#             */
/*   Updated: 2022/12/25 12:32:38 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "ft_minirt_tool.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	if (0xffffffffffffffff == count || 0xffffffffffffffff == size)
		return (NULL);
	ptr = malloc(size * count);
	if (!ptr)
		return (NULL);
	ft_memset(ptr, 0, size * count);
	return (ptr);
}
