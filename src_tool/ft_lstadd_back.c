/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 11:40:33 by kyoulee           #+#    #+#             */
/*   Updated: 2022/12/23 11:47:29 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/_types/_null.h>

#include "ft_minirt_tool.h"

void	ft_lstadd_back(t_list **lst, t_list *new_lst)
{
	t_list	*lst_move;

	if (*lst == NULL || new_lst == NULL)
	{
		if (*lst == NULL)
			*lst = new_lst;
		return ;
	}
	lst_move = *lst;
	while (lst_move->next)
		lst_move = lst_move->next;
	lst_move->next = new_lst;
}
