/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fd.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 10:19:30 by kyoulee           #+#    #+#             */
/*   Updated: 2022/12/23 10:27:27 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FD_H
# define FT_FD_H

int	ft_open(const char *filename, int option);
int	ft_open_type(const char *filename, int option, char *type);

#endif
