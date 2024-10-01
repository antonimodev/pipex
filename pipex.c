/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonimo <antonimo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 11:49:18 by antonimo          #+#    #+#             */
/*   Updated: 2024/10/01 14:21:30 by antonimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av)
{
	ac--;
	if (ac == 4)
	{
		av++;
	}
	else
	{
		perror("No valid arguments.");
		exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);
}

bool	fd_validation(const char *fd1, const char *fd2)
{
	if (access(fd1, F_OK) == 0)
	{
		if (access(fd2, F_OK) == 0)
			return (true);
	}
	return (false);
}

bool	cmd_validation(const char *cmd1, const char *cmd2)
{
	if (access(cmd1, F_OK) == 0)
	{
		if (access(cmd2, F_OK) == 0)
			return (true);
	}
	return (false);
}
