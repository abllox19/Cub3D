/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idioumas <idioumas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 11:09:07 by asoumare          #+#    #+#             */
/*   Updated: 2025/02/25 13:14:35 by idioumas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H

# define LIBFT_H

# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdarg.h>
# include <stdint.h>
# include <limits.h>

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
	char			*str_buf;
}					t_list;

/*		libft		*/

int					ft_atoi(const char *str);
long				ft_atol(const char *str);
void				*ft_bzero(void *b, size_t len);
void				*ft_calloc(size_t count, size_t size);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
char				*ft_itoa(int n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memset(void *b, int c, size_t len);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_putstr_fd(char *s, int fd);
char				**ft_split(char const *s, char c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strdup(const char *src);
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strjoin(char const *s1, char const *s2);
size_t				ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t				ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t				ft_strlen(const char *str);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strnstr(const char *str1, const char *str2, size_t len);
char				*ft_strchr(const char *s, int c);
char				*ft_strtrim(char const *s1, char const *set);
char				*ft_substr(char const *s, unsigned int start, size_t len);
int					ft_tolower(int c);
int					ft_toupper(int c);

t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **alst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **alst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));

/*		GNL		*/

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10 
# endif

int					found_newline(t_list *list);
t_list				*find_last_node(t_list *list);
char				*get_line(t_list *list);
void				copy_str(t_list *list, char *str);
int					len_to_newline(t_list *list);
void				polish_list(t_list **list);
char				*get_next_line(int fd);
void				dealloc(t_list **list, t_list *clean_node, char *buf);
void				create_list(t_list **list, int fd);

/*		print	*/

int					ft_printf(const char *format, ...);
int					ft_formats(va_list args, const char format);

int					ft_print_c(int c);
int					ft_print_str(char *str);
int					ft_print_ptr(unsigned long long ptr);
int					ft_print_nbr(int n);
int					ft_print_unsigned(unsigned int n);
int					ft_print_hex(unsigned int num, const char format);
int					ft_print_pour(void);

void				ft_put_str(char *str);
void				ft_put_ptr(uintptr_t num);
int					ft_ptr_len(uintptr_t num);
int					ft_num_len(unsigned	int num);
void				ft_put_hex(unsigned int num, const char format);
int					ft_hex_len(unsigned	int num);
char				*ft_uitoa(unsigned int n);

#endif
