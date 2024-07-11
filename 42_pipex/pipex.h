/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <alibourb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 10:53:10 by alibourb          #+#    #+#             */
/*   Updated: 2023/05/15 12:26:35 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/wait.h>
# include <fcntl.h>

# define EXIT_FAILURE 1

/* PIPEX */
void		execute_cmd(char *cmd, char **envp);
char		*get_real_path(char *cmd, char **envp);
void		child1_process(char **ag, int *pipe_fd, char **envp);
void		child2_process(char **ag, int *pipe_fd, char **envp);
void		pipex(char **ag, char **envp);

/* UTILS */
void		free_tabs(char **tab);
void		*free_split(char **tab);
int			ft_strlen(char *str);
int			count_lines(char *str, char c);
char		*put_line(const char *str, char c);
char		**ft_split(const char *str, char c);
char		*ft_strjoin(char *str1, char *str2);
char		*ft_strnstr(char *str, char *to_find, int size);

#endif
