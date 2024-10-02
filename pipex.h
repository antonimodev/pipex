/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonimo <antonimo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 13:41:34 by antonimo          #+#    #+#             */
/*   Updated: 2024/10/02 14:12:50 by antonimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <stdbool.h>
# include "../libft/libft.h"

# ifndef LINUX_PATH
#  define LINUX_PATH "/home/antonimo/.pyenv/shims:/home/antonimo/.pyenv/bin:\
/home/antonimo/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:\
/bin:/usr/games:/usr/local/games:/snap/bin"

# endif

/* typedef	struct s_pipex
{
	int	read_pipe;
	int write_pipe;
}	t_pipex; */

/* CHECK_FD */
bool	fd_validation(const char *fd1, const char *fd2);

/* CHECK_CMD */
bool	cmd_validation(char *cmd1, char *cmd2);
char	**split_path(char *envp);
char	**concat_path(char **splitted_path, char *cmd);
char	*cmdcat(char *s1, char *s2);
bool	path_validation(char **cmd_path);

/* PIPEX UTILS 	*/
void	free_matrix(char **matrix);

#endif