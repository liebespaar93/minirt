/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 11:49:03 by kyoulee           #+#    #+#             */
/*   Updated: 2022/12/26 14:17:05 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/_types/_null.h>

int	ft_strcmp(const char *s1, const char *s2)
{
	if (s1 == NULL && s2 == NULL)
		return (0);
	while (*s1 != '\0' && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)(*s1) - (unsigned char)(*s2));
}
