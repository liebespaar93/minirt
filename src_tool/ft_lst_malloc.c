/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_malloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 11:40:26 by kyoulee           #+#    #+#             */
/*   Updated: 2022/12/23 11:51:17 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "ft_minirt_tool.h"

char	*ft_lst_malloc(t_list **lst)
{
	t_list	*lst_move;
	t_list	*tmp_lst;
	char	*tmp;
	char	*result;
	int		len;

	if (*lst == NULL)
		return (NULL);
	lst_move = *lst;
	len = ft_lst_len(lst);
	result = (char *)malloc(len + 1);
	lst_move = *lst;
	len = 0;
	while (lst_move)
	{
		tmp_lst = lst_move->next;
		tmp = lst_move->content;
		while (*tmp)
			result[len++] = *tmp++;
		free(lst_move->content);
		free(lst_move);
		lst_move = tmp_lst;
	}
	result[len] = '\0';
	return (result);
}
