/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 12:23:40 by kyoulee           #+#    #+#             */
/*   Updated: 2022/12/25 12:24:01 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "ft_minirt_tool.h"

char	*ft_strdup(const char *s1)
{
	char	*strdup_ptr;
	size_t	s1_len;

	strdup_ptr = (char *)s1;
	if (s1 == (void *)0)
		*strdup_ptr = '\0';
	s1_len = ft_strlen(s1);
	strdup_ptr = (char *)malloc(1 * (s1_len + 1));
	if (strdup_ptr == NULL)
		return (NULL);
	while (*s1 != '\0')
		*strdup_ptr++ = *s1++;
	*strdup_ptr = '\0';
	return (strdup_ptr - s1_len);
}
