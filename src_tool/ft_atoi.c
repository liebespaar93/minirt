/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 13:25:11 by kyoulee           #+#    #+#             */
/*   Updated: 2022/12/25 13:25:12 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minirt_tool.h"

int	ft_atoi_overflow(long sign);

int	ft_atoi(const char *str)
{
	int		num;
	long	sign;

	num = 0;
	sign = 1;
	while ((0x09 <= *str && *str <= 0x0d) || *str == 0x20)
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (ft_isdigit(*str))
	{
		if (num > num * 10)
			return (ft_atoi_overflow(sign));
		num = num * 10 + (*str - 0x30);
		str++;
	}
	return ((int)(num * sign));
}

int	ft_atoi_overflow(long sign)
{
	if (sign == 1)
		return (-1);
	return (0);
}

int	ft_atoi_len(const char *str)
{
	const char	*temp;
	int			num;
	long		sign;

	num = 0;
	sign = 1;
	temp = str;
	while ((0x09 <= *str && *str <= 0x0d) || *str == 0x20)
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (ft_isdigit(*str))
	{
		if (num > num * 10)
			return (ft_atoi_overflow(sign));
		num = num * 10 + (*str - 0x30);
		str++;
	}
	return (str - temp);
}
