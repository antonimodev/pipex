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

#include "../../include/pipex.h"

void	validate_arguments(int ac, char **av)
{
	if (ac == 4)
	{
		if (!fd_validation(av[0]) || !cmd_validation(av[1], av[2]))
			exit(EXIT_FAILURE);
	}
	else
	{
		ft_putstr_fd("invalid format: ./pipex infile cmd1 cmd2 outfile\n", 2);
		exit(EXIT_FAILURE);
	}
}

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

int	open_file(char *file, enum e_mode mode)
{
	int	fd;

	if (mode == READ)
		fd = open(file, O_RDONLY);
	else
		fd = open(file, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd == -1)
	{
		perror("open_file: Error opening file");
		exit(EXIT_FAILURE);
	}
	return (fd);
}

void	fd_redirection(int from, int to)
{
	if (dup2(to, from) == -1)
	{
		perror("dup2: error duplicating fd");
		exit(EXIT_FAILURE);
	}
}
