/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_len.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 11:40:20 by kyoulee           #+#    #+#             */
/*   Updated: 2022/12/23 11:43:54 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/_types/_null.h>

#include "ft_minirt_tool.h"

int	ft_lst_len(t_list **lst)
{
	t_list	*lst_move;
	char	*tmp;
	int		len;

	if (*lst == NULL)
		return (0);
	lst_move = *lst;
	len = 0;
	while (lst_move)
	{
		tmp = lst_move->content;
		while (*tmp++)
			len++;
		lst_move = lst_move->next;
	}
	return (len);
}
