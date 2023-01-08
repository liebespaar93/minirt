/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 13:45:30 by kyoulee           #+#    #+#             */
/*   Updated: 2022/12/23 11:51:42 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GET_NEXT_LINE_H
# define FT_GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 512
# endif

# include <sys/_types/_size_t.h>

# include "ft_minirt_tool.h"

typedef struct s_fd			t_fd;
typedef struct s_read_line	t_read_line;
typedef struct s_read_file	t_read_file;

typedef struct s_fd
{
	int		fd;
	void	*data;
	t_fd	*next;
}	t_fd;

typedef struct s_read_line
{
	char		*data;
	size_t		data_size;
	t_read_line	*next;
	t_read_line	*prev;
}	t_read_line;

typedef struct s_read_file
{
	int			num_lines;
	t_read_line	*line_head;
}	t_read_file;

/* ft_get_next_line */
char		*ft_get_next_line(int fd);
char		*ft_buff_split(char **buff_all, int *flag, int rlen);
void		ft_buff_read(char **buff_static, t_list **buff_head, int *flag, \
	int fd);
t_fd		*ft_lst_fd_addfront(t_fd **fd_static, int fd, char **buff_static);
char		*ft_lst_fd_find(t_fd **fd_static, int fd);

/* ft_fd */
int			ft_open(const char *filename, int option);
int			ft_open_type(const char *filename, int option, char *type);

/* ft_read */
t_read_line	*ft_new_read_line(char const *data);
t_read_line	*ft_read_line_add(t_read_line **read_line_ptr, char const *data);
t_read_file	*ft_read_file_free(t_read_file **read_file_ptr);
t_read_file	*ft_read_file(int fd);

#endif