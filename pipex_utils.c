/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonimo <antonimo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 14:03:40 by antonimo          #+#    #+#             */
/*   Updated: 2024/10/02 14:26:20 by antonimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	arg_validation(int ac, char **av)
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
	}
	else
	{
		perror("No valid arguments\n");
		exit(EXIT_FAILURE);
	}
}

void	*exec_touch(const char *fd2)
{
	char	**touch_matrix;

	touch_matrix = malloc((3 + 1) * sizeof(char *));
	if (!touch_matrix)
		return (NULL);
	touch_matrix[0] = "touch";
	touch_matrix[1] = (char *)fd2;
	touch_matrix[2] = NULL;
	touch_matrix[3] = NULL;
	if (execve(TOUCH_PATH, touch_matrix, NULL) == -1)
	{
		free_matrix(touch_matrix);
		perror("Error creating a file");
		exit(EXIT_FAILURE);
	}
	free_matrix(touch_matrix);
	return (NULL);
}

void	free_matrix(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
		free(matrix[i++]);
	free(matrix);
}
