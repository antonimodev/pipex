/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonimo <antonimo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 11:49:18 by antonimo          #+#    #+#             */
/*   Updated: 2024/10/02 14:20:59 by antonimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av)
{
	t_pipe	pipe;
	pid_t	child;

	validate_arguments(ac, av);
	pipe = create_pipe();
	child = fork();
	if (child == 0)
	{
		dup2();
		exec_cmd_to_file(av[0], av[1]);
	}
	dup2();
	exec_cmd_to_file();
	exit(EXIT_SUCCESS);
}

void	open_file(char *file, enum e_mode mode)
{
	int	fd;

	if (mode == R_MODE)
		fd = open(file, O_RDONLY);
	else
		fd = open(file, O_WRONLY | O_TRUNC, 0644); // No estoy seguro si debe tener estos permisos y si debe aplicarse O_TRUNC (dejar el archivo a 0 bytes)
	if (fd == -1)
	{
		perror("open_file: Error opening file");
		exit(EXIT_FAILURE);
	}
	return (fd);
}
