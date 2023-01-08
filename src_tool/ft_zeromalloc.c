/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zeromalloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 11:14:51 by kyoulee           #+#    #+#             */
/*   Updated: 2022/12/23 15:35:24 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "ft_minirt_tool.h"

void	*ft_zeromalloc(void **ptr, size_t size)
{
	void	*new_ptr;

	new_ptr = malloc(size);
	if (new_ptr)
		ft_bzero(new_ptr, size);
	if (ptr)
		*ptr = new_ptr;
	return (new_ptr);
}
