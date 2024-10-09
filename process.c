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

#include "pipex.h"

void	child_process(char **av, t_pipe pipe, char *cmd)
{
	int	fd;

	fd = open_file(av[0], 0);
	if (dup2(fd, STDIN_FILENO) == -1)
	{
		perror("dup2: error duplicating fd to STDIN");
		exit(EXIT_FAILURE);
	}
	if (dup2(pipe.write_pipe, STDOUT_FILENO) == -1)
	{
		perror("dup2: error duplicating pipe to STDOUT");
		exit(EXIT_FAILURE);
	}
	close(pipe.read_pipe);
	exec_cmd(cmd);
}

void	parent_process(char **av, t_pipe pipe, char *cmd)
{
	int	fd;

	fd = open_file(av[3], 1);
	if (dup2(fd, STDOUT_FILENO) == -1)
	{
		perror("dup2: error duplicating fd to STDOUT");
		exit(EXIT_FAILURE);
	}
	if (dup2(pipe.read_pipe, STDIN_FILENO) == -1)
	{
		perror("dup2: error duplicating pipe to STDIN");
		exit(EXIT_FAILURE);
	}
	close(pipe.write_pipe);
	exec_cmd(cmd);
}
