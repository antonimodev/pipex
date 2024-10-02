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
	ac--;
	if (ac == 4)
	{
		av++;
		if (!fd_validation(av[0], av[3]) || !cmd_validation(av[1], av[2]))
		{
			perror("No valid arguments");
			exit(EXIT_FAILURE);
		}
		printf("Argumentos válidos, se puede continuar\n");
	}
	else
	{
		perror("No valid arguments\n");
		exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);
}
