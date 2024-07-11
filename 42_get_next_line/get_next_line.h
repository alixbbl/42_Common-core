/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 18:45:31 by alibourb          #+#    #+#             */
/*   Updated: 2023/01/10 16:39:23 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

char	*get_next_line(int fd);
char	*read_and_stash(int fd, char *stash);
char	*stash_to_line(char *stash);
char	*renew_stash(char *stash);
char	*ft_strjoin(char *str1, char *str2);
int		ft_strchr(char *str, char c);
int		ft_strlen(char *str);

#endif
