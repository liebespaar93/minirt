/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_end_space.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 13:25:11 by kyoulee           #+#    #+#             */
/*   Updated: 2023/04/13 10:50:19 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_end_space(char str)
{
	if (!str || (0x09 <= str && str <= 0x0d) || str == 0x20)
		return (1);
	return (0);
}