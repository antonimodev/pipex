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

	arg_validation(ac, av);
	pipe = create_pipe();
	child = fork();
	if (child == 0)
	{
		//proceso de comando 1
	}
	else
		//wait child
		//proceso de comando 2
	exit(EXIT_SUCCESS);
}

/* Función que recibe un file descriptor y un comando. Busca
la ruta del cmd para poder ejecutarlo en el file descriptor con
execve. */
void	exec_to_file(int fd, char *cmd)
{
	char	**splitted_paths;
	char	**cmd_paths;
	char	*cmd_dir;

	splitted_paths = split_paths(LINUX_PATH); // free_matrix
	cmd_paths = concat_paths(splitted_paths, cmd); // free_matrix
	cmd_dir = get_path(cmd_paths); // hay que liberarlo
	//execve(cmd_dir, (matriz: comando, fd, NULL), NULL);
}
/* Devuelve un str de la ruta exacta del comando */
char	*get_path(char **cmd_paths)
{
	char	*cmd_dir;
	int	i;

	i = 0;
	while (cmd_paths[i])
	{
		if (access(cmd_paths[i], F_OK | X_OK) == 0)
		{
			cmd_dir = malloc((ft_strlen(cmd_paths[i]) + 1) * sizeof(char));
			cmd_dir = cmd_paths[i];
			return (cmd_dir);
		}
		i++;
	}
	return (NULL);
}
