/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <alibourb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 10:52:30 by alibourb          #+#    #+#             */
/*   Updated: 2023/05/17 14:16:25 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child1_process(char **ag, int *pipe_fd, char **envp)
{
	int	fd1;

	fd1 = open(ag[1], O_RDONLY);
	if (fd1 < 0)
	{
		perror("");
		exit(EXIT_FAILURE);
	}
	if (dup2(pipe_fd[1], STDOUT_FILENO) < 0)
		perror("");
	if (dup2(fd1, STDIN_FILENO) < 0)
		perror("");
	close(pipe_fd[0]);
	close(fd1);
	close(pipe_fd[1]);
	execute_cmd(ag[2], envp);
}

void	child2_process(char **ag, int *pipe_fd, char **envp)
{
	int		fd2;

	fd2 = open(ag[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fd2 < 0)
	{
		perror("");
		exit(EXIT_FAILURE);
	}
	if (dup2(pipe_fd[0], STDIN_FILENO) == -1)
		perror("");
	if (dup2(fd2, STDOUT_FILENO) == -1)
		perror("");
	close(pipe_fd[1]);
	close(fd2);
	close(pipe_fd[0]);
	execute_cmd(ag[3], envp);
}

void	pipex(char **ag, char **envp)
{
	int		pipe_fd[2];
	pid_t	id1;
	pid_t	id2;
	int		status;

	pipe(pipe_fd);
	id1 = fork();
	if (id1 == -1)
		return (perror("Fork failed: "));
	if (id1 == 0)
		child1_process(ag, pipe_fd, envp);
	id2 = fork();
	if (id2 == -1)
		return (perror("Fork failed: "));
	if (id2 == 0)
		child2_process(ag, pipe_fd, envp);
	close(pipe_fd[1]);
	close(pipe_fd[0]);
	waitpid(id1, NULL, 0);
	waitpid(id2, &status, 0);
}

int	main(int ac, char **ag, char **envp)
{
	if (ac == 5)
		pipex(ag, envp);
	else
		write(STDERR_FILENO, "Wrong arguments number.\n", 24);
	return (0);
}
