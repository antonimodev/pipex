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

void	validate_arguments(int ac, char **av)
{
	ac--;
	av++;
	if (ac == 4)
	{
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

/* Devuelve un str de la ruta exacta del comando */
char	*get_path(char **cmd_paths)
{
	char	*cmd_dir;
	int		i;

	i = 0;
	while (cmd_paths[i])
	{
		if (access(cmd_paths[i], F_OK | X_OK) == 0)
		{
			cmd_dir = ft_strdup(cmd_paths[i]);
			return (cmd_dir);
		}
		i++;
	}
	return (NULL);
}

char	**create_matrix(int n)
{
	char	**matrix;

	if (n < 0)
	{
		perror("create_matrix: Parameter must be positive");
		return (NULL);
	}
	matrix = malloc((n + 1) * sizeof(char *));
	if (!matrix)
	{
		perror("create_matrix: Error allocating matrix memory");
		return (NULL);
	}
	ft_memset(matrix, 0, (n + 1) * sizeof(char *));
	return (matrix);
}

void	free_matrix(char **matrix)
{
	int	i;

	i = 0;
	if (matrix)
	{
		while (matrix[i])
			free(matrix[i++]);
		free(matrix);
	}
}
// METERLO AL .H Y ORDENARLO
int	ft_matrixlen(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
		i++;
	return (i);
}
