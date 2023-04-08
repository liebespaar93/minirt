/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minirt_tool.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 09:54:18 by kyoulee           #+#    #+#             */
/*   Updated: 2023/02/18 02:08:39 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MINIRT_TOOL_H
# define FT_MINIRT_TOOL_H

# include <sys/_types/_size_t.h>

typedef struct s_list		t_list;

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

typedef union s_color
{
	unsigned int	integer;
	struct s_bit
	{
		unsigned char	a;
		unsigned char	r;
		unsigned char	g;
		unsigned char	b;
	} bit;
}	t_color;

void	ft_bzero(void *s, size_t n);
void	*ft_memset(void *b, int c, size_t len);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);

int		ft_isdigit(int c);
int		ft_is_end_space(char str);

int		ft_lst_len(t_list **lst);
char	*ft_lst_malloc(t_list **lst);
void	ft_lstadd_back(t_list **lst, t_list *new_lst);
t_list	*ft_lstnew(void *content);

int		ft_ptrlen(void **ptr, char *type);
void	*ft_ptrcpy(void **ptr, void *cpy_ptr);

void	*ft_calloc(size_t count, size_t size);
void	*ft_zeromalloc(void **ptr, size_t size);

size_t	ft_strlen(const char *str);
char	*ft_strncpy(char *str, size_t len);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s1);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);

char	**ft_split(char const *s, char c);
void	**ft_split_free(char **split_all);

int		ft_atoi(const char *str);
int		ft_atoi_len(const char *str);
double	ft_atof(const char *str);

void	ft_exit_error(int error);
void	ft_exit_print_error(int error, char *str);

#endif
