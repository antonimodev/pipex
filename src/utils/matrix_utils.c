/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonimo <antonimo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 11:25:46 by antonimo          #+#    #+#             */
/*   Updated: 2024/10/07 11:47:59 by antonimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex.h"

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
	ft_memset(matrix, 0, (size_t)((n + 1) * sizeof(char *)));
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

int	ft_matrixlen(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
		i++;
	return (i);
}
