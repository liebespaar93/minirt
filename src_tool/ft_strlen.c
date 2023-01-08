/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 09:55:23 by kyoulee           #+#    #+#             */
/*   Updated: 2022/12/23 10:28:35 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/_types/_size_t.h>

size_t	ft_strlen(const char *str)
{
	const char	*temp;

	temp = str;
	while (*temp)
		temp++;
	return (temp - str);
}
