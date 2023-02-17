/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 10:06:30 by kyoulee           #+#    #+#             */
/*   Updated: 2022/12/23 10:07:14 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/_types/_size_t.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*sptr1;
	unsigned char	*sptr2;

	sptr1 = (unsigned char *)s1;
	sptr2 = (unsigned char *)s2;
	while (n-- > 0)
	{
		if (*sptr1 != *sptr2)
			return (*sptr1 - *sptr2);
		sptr1++;
		sptr2++;
	}
	return (0);
}
