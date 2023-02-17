/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 12:44:47 by kyoulee           #+#    #+#             */
/*   Updated: 2023/02/18 02:23:23 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "ft_minirt_tool.h"

int	ft_atof_overflow(long sign)
{
	if (sign == -1)
		return (-HUGE_VAL);
	return (HUGE_VAL);
}

int	ft_atof_integer(const char *str, double *f, int sign)
{
	int	len;

	len = 0;
	while (ft_isdigit(*str))
	{
		if (*f > *f * 10)
			return (ft_atof_overflow(sign));
		*f *= 10;
		*f += (*str - 0x30);
		str++;
		len++;
	}
	return (len);
}

int	ft_atof_decimal(const char *str, double *f, int sign)
{
	double	pv;
	int		len;

	len = 0;
	pv = 0.1;
	while (ft_isdigit(*str))
	{
		if (*f > *f * 10)
			return (ft_atof_overflow(sign));
		*f += (*str - 0x30) * (pv);
		pv *= 0.1;
		str++;
		len++;
	}
	return (len);
}

void	ft_atof_e(const char *str, double *f, int sign)
{
	double	pv;
	int		num;

	if (*str == '-' && str++)
		pv = 0.1;
	else
		pv = 10;
	if (!ft_isdigit(*str))
		return ;
	num = ft_atoi(str);
	while (num--)
	{
		if (*f > *f * pv)
		{
			*f = ft_atof_overflow(sign);
			return ;
		}
		*f *= pv;
	}
}

double	ft_atof(const char *str)
{
	double	f;
	int		sign;

	f = 0;
	sign = 1;
	while ((0x09 <= *str && *str <= 0x0d) || *str == 0x20)
		str++;
	if (*str == '+' || *str == '-')
		if (*str++ == '-')
			sign = -1;
	str += ft_atof_integer(str, &f, sign);
	if (*str++ != '.')
		return (f * sign);
	str += ft_atof_decimal(str, &f, sign);
	if (!ft_strchr("Ee", *str++))
		return (f * sign);
	ft_atof_e(str, &f, sign);
	return (f * sign);
}
