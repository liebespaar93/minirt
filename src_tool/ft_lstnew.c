/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 11:40:37 by kyoulee           #+#    #+#             */
/*   Updated: 2022/12/23 11:43:42 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "ft_minirt_tool.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*lst_new;

	lst_new = (t_list *)malloc(sizeof(t_list));
	if (lst_new == NULL)
		return (NULL);
	lst_new->next = NULL;
	lst_new->content = content;
	return (lst_new);
}
