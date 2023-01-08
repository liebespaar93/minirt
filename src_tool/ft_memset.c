/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 12:32:54 by kyoulee           #+#    #+#             */
/*   Updated: 2022/12/25 12:33:22 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/_types/_size_t.h>

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)b;
	while (len-- > 0)
		*ptr++ = c;
	return (b);
}
