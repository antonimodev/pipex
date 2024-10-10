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

#include "../include/pipex.h"

int	main(int ac, char **av)
{
	t_pipe	pipe;
	pid_t	child;

	ac--;
	av++;
	validate_arguments(ac, av);
	pipe = create_pipe();
	child = fork();
	child_process(av, pipe, av[1], child);
	parent_process(av, pipe, av[2]);
	exit(EXIT_SUCCESS);
}
