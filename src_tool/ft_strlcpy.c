/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 12:30:52 by kyoulee           #+#    #+#             */
/*   Updated: 2022/12/25 12:30:57 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minirt_tool.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	unsigned char	*dptr;
	unsigned char	*sptr;
	size_t			count;

	dptr = (unsigned char *)dst;
	sptr = (unsigned char *)src;
	if (src == (void *)0)
		*sptr = '\0';
	count = ft_strlen((const char *)sptr);
	if (dstsize == 0)
		return (count);
	while (*sptr != '\0' && dstsize-- > 1)
		*dptr++ = *sptr++;
	if (*dptr != '\0')
		*dptr = '\0';
	return (count);
}
