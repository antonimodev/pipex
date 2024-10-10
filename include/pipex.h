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
# include <sys/types.h>
# include <fcntl.h>
# include "../lib/libft/libft.h"

# ifndef LINUX_PATH
#  define LINUX_PATH "/home/antonimo/.pyenv/shims:/home/antonimo/.pyenv/bin:\
/home/antonimo/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:\
/bin:/usr/games:/usr/local/games:/snap/bin"

# endif

enum e_mode
{
	READ,
	WRITE,
};

typedef struct s_pipe
{
	int	read_pipe;
	int	write_pipe;
}	t_pipe;

/* CHECK_CMD */
bool	cmd_validation(char *cmd1, char *cmd2);
char	**split_paths(char *envp);
char	**concat_paths(char **splitted_paths, char *cmd);
char	*cmdcat(char *s1, char *s2);
bool	path_validation(char **cmd_path);

/* CHECK_FD */
bool	fd_validation(const char *file1);

/* EXEC */
void	exec_cmd(char *cmd_arg);

/* MATRIX UTILS*/
char	**create_matrix(int n);
void	free_matrix(char **matrix);
int		ft_matrixlen(char **matrix);

/* PIPES */
t_pipe	create_pipe(void);

/* PIPEX UTILS 	*/
void	validate_arguments(int ac, char **av);
char	*get_path(char **cmd_paths);
int		open_file(char *file, enum e_mode mode);
void	fd_redirection(int from, int to);

/* PROCESS */
void	child_process(char **av, t_pipe pipe, char *cmd, pid_t child);
void	parent_process(char **av, t_pipe pipe, char *cmd);

#endif