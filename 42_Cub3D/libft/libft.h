/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarthaud <jarthaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 10:44:50 by jarthaud          #+#    #+#             */
/*   Updated: 2023/10/23 15:26:40 by jarthaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <ctype.h>
# include <string.h>
# include <fcntl.h>
# include <stdarg.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 500
# endif

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

// LIBFT Functions
int				ft_atoi(char *nptr);
void			ft_bzero(void *s, size_t n);
void			*ft_calloc(size_t nmemb, size_t size);
int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_isprint(int c);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t n);
void			*ft_memset(void *s, int c, size_t n);
char			*ft_strchr(char *s, int c);
char			*ft_strdup(const char *s);
char			*ft_strdup2(const char *s);
char			*ft_strdup_trim(const char *s);
char			*ft_strcat(char *dst, const char *src);
char			*ft_strcpy(char *dst, const char *src);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
size_t			ft_strlcpy(char *dst, const char *src, size_t size);
size_t			ft_strlen(const char *s);
int				ft_strncmp(char *s1, char *s2, size_t n);
int				ft_strcmp(const char *s1, const char *s2);
char			*ft_strnstr(const char *s1, const char *s2, size_t len);
char			*ft_strrchr(char *s, int c);
int				ft_tolower(int c);
int				ft_toupper(int c);
char			*ft_itoa(int n);
void			ft_putchar_fd(char c, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
void			ft_putstr_fd(char *s, int fd);
char			**ft_split(char const *s, char c);
char			*ft_strjoin(char *s1, char *s2);
char			*ft_strtrim(char const *s1, char const *set);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void			ft_striteri(char *s, void (*f)(unsigned int, char*));
t_list			*ft_lstnew(void *content);
void			ft_lstadd_front(t_list **lst, t_list *new);
int				ft_lstsize(t_list *lst);
t_list			*ft_lstlast(t_list *lst);
t_list			*ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstdelone(t_list *lst, void (*del)(void *));
void			ft_lstclear(t_list **lst, void (*del)(void *));
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *),
					void (*del)(void *));

// GNL Functions
char			*get_next_line(int fd);
char			*get_new_start(char *stash, int read_nb);
char			*get_line(char *stash);

// PRINTF Functions
int				ft_convert(va_list args, const char c);
int				ft_printf(const char *str, ...);
int				ft_putchar(char c);
int				ft_putpercent(void);
int				ft_putnbr(int n);
int				ft_putstr(char *s);
unsigned int	ft_puthexa(unsigned long long n, char c);
unsigned int	ft_putptr(unsigned long long n, char c);
unsigned int	ft_putunbr(unsigned int n);

#endif
