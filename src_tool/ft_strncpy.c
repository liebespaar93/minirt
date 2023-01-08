/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 11:30:29 by kyoulee           #+#    #+#             */
/*   Updated: 2022/12/23 11:30:46 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/_types/_size_t.h>

char	*ft_strncpy(char *str, size_t len)
{
	char	*tmp;
	char	*result;

	if (len == 0)
		return (NULL);
	tmp = (char *)malloc(sizeof(char) *(len + 1));
	if (!tmp)
		return (NULL);
	result = tmp;
	tmp[len] = '\0';
	while (len--)
		*tmp++ = *str++;
	return (result);
}
