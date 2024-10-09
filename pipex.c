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

	ac--;
	av++;
	validate_arguments(ac, av);
	printf("SE HA VALIDADO CORRECTAMENTE\n");
	pipe = create_pipe();
	printf("SE HA CREADO LA PIPE\n");
	child = fork();
	if (child == -1)
	{
		perror("fork: error at child process\n");
		exit(EXIT_FAILURE);
	}
	else if (child == 0)
		child_process(av, pipe, av[1]);
	parent_process(av, pipe, av[2]);
	printf("se ha hecho la funcion parent");
	exit(EXIT_SUCCESS);
}
