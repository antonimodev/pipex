/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonimo <antonimo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 11:24:43 by antonimo          #+#    #+#             */
/*   Updated: 2024/10/09 15:28:04 by antonimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex.h"

void	child_process(char **av, t_pipe pipe, char *cmd, pid_t child)
{
	int	fd;

	if (child == -1)
	{
		perror("fork: error at child process");
		exit(EXIT_FAILURE);
	}
	else if (child == 0)
	{
		fd = open_file(av[0], READ);
		fd_redirection(STDIN_FILENO, fd);
		close(fd);
		fd_redirection(STDOUT_FILENO, pipe.write_pipe);
		close(pipe.read_pipe);
		close(pipe.write_pipe);
		exec_cmd(cmd);
	}
}

void	parent_process(char **av, t_pipe pipe, char *cmd)
{
	int	fd;

	fd = open_file(av[3], WRITE);
	fd_redirection(STDOUT_FILENO, fd);
	close(fd);
	fd_redirection(STDIN_FILENO, pipe.read_pipe);
	close(pipe.write_pipe);
	close(pipe.read_pipe);
	exec_cmd(cmd);
}
