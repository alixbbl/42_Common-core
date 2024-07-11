/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths_and_commands.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <alibourb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 12:57:40 by alibourb          #+#    #+#             */
/*   Updated: 2023/05/11 14:33:34 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	execute_cmd(char *cmd_ag, char **envp)
{
	char	**tab_cmd;
	char	*path;

	tab_cmd = ft_split(cmd_ag, ' ');
	if (!tab_cmd)
	{
		perror("");
		exit(EXIT_FAILURE);
	}
	path = get_real_path(tab_cmd[0], envp);
	if (path == NULL)
	{
		free_tabs(tab_cmd);
		perror("");
		exit(EXIT_FAILURE);
	}
	if (execve(path, tab_cmd, envp) == -1)
	{
		free_tabs(tab_cmd);
		perror("");
		exit(EXIT_FAILURE);
	}
}

char	*get_real_path(char *cmd, char **envp)
{
	char	**tab_paths;
	char	*real_path;
	char	*path_cmd;
	int		i;

	i = 0;
	if (access(cmd, F_OK) == 0)
		return (cmd);
	while (ft_strnstr(envp[i], "PATH", 4) == 0)
		i++;
	tab_paths = ft_split(envp[i] + 5, ':');
	i = 0;
	while (tab_paths[i])
	{
		path_cmd = ft_strjoin(tab_paths[i], "/");
		real_path = ft_strjoin(path_cmd, cmd);
		free(path_cmd);
		if (access(real_path, F_OK) == 0)
			return (real_path);
		free(real_path);
		i++;
	}
	free_tabs(tab_paths);
	return (NULL);
}
