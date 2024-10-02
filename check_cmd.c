/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonimo <antonimo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 11:49:06 by antonimo          #+#    #+#             */
/*   Updated: 2024/10/02 14:25:44 by antonimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/* Verifica si el comando recibido existe y es posible ejecutarlo.
En caso de que exista y pueda ejecutarse devuelve True */
bool	cmd_validation(char *cmd1, char *cmd2)
{
	char	**splitted_path;
	char	**cmd1_path;
	char	**cmd2_path;
	bool	res;

	res = false;
	splitted_path = split_path(LINUX_PATH);
	cmd1_path = concat_path(splitted_path, cmd1);
	cmd2_path = concat_path(splitted_path, cmd2);
	if (path_validation(cmd1_path))
	{
		if (path_validation(cmd2_path))
			res = true;
	}
	free_matrix(splitted_path);
	free_matrix(cmd1_path);
	free_matrix(cmd2_path);
	return (res);
}

/* Spliteamos la macro definida en el .h que indica la variable
de entorno PATH del sistema (LINUX) */
char	**split_path(char *envp)
{
	char	**splitted_path;

	splitted_path = ft_split(envp, ':');
	if (!splitted_path)
		exit(EXIT_FAILURE);
	return (splitted_path);
}

/* Concatena cmd a cada str de la matriz */
char	**concat_path(char **splitted_path, char *cmd)
{
	int		i;

	i = 0;
	while (splitted_path[i])
	{
		splitted_path[i] = cmdcat(splitted_path[i], cmd);
		i++;
	}
	return (splitted_path);
}

/* Concatena S1 con S2 usando reserva (dinámica) con malloc.
nos aseguramos de que añada '/' antes de concatenar el comando recibido
por parámetro */
char	*cmdcat(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*cmdcat;

	i = 0;
	j = 0;
	cmdcat = malloc((ft_strlen(s1) + ft_strlen(s2) + 2) * sizeof(char));
	if (!cmdcat)
		return (NULL);
	while (s1[i])
	{
		cmdcat[i] = s1[i];
		i++;
	}
	cmdcat[i] = '/';
	while (s2[j])
		cmdcat[i++] = s2[j++];
	cmdcat[i] = '\0';
	return (cmdcat);
}

bool	path_validation(char **cmd_path)
{
	int	i;

	i = 0;
	while (cmd_path[i])
	{
		if (access(cmd_path[i], F_OK | X_OK) == 0)
			return (true);
		i++;
	}
	return (false);
}
