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
		//abrir un fd en modo lectura
		//debe usar la pipe para escribir y darle salida a padre	
	}
	//proceso padre: abre fd en modo escritura
	//debe usar la pipe para leer la salida de child
	exit(EXIT_SUCCESS);
}
void	child(char **av, int *p_fd, char **env)
{
	int		fd;

	fd = open_file(av[1], 0);
	dup2(fd, 0);
	dup2(p_fd[1], 1);
	close(p_fd[0]);
	exec(av[2], env);
}