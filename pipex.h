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
# include "./lib/libft/libft.h"

# ifndef LINUX_PATH
#  define LINUX_PATH "/home/antonimo/.pyenv/shims:/home/antonimo/.pyenv/bin:\
/home/antonimo/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:\
/bin:/usr/games:/usr/local/games:/snap/bin"

# endif

# ifndef TOUCH_PATH
#  define TOUCH_PATH "/usr/bin/touch"

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

/* CHECK_FD */
bool	fd_validation(const char *file1, const char *file2);

/* CHECK_CMD */
bool	cmd_validation(char *cmd1, char *cmd2);
char	**split_paths(char *envp);
char	**concat_paths(char **splitted_paths, char *cmd);
char	*cmdcat(char *s1, char *s2);
bool	path_validation(char **cmd_path);

/* PIPEX UTILS 	*/
void	validate_arguments(int ac, char **av);
char	*get_path(char **cmd_paths);
char	**create_matrix(int n);
void	free_matrix(char **matrix);

/* MATRIX UTILS*/
char	**create_matrix(int n);
void	free_matrix(char **matrix);
int		ft_matrixlen(char **matrix);

/* PIPES */
t_pipe	create_pipe(void);

/* EXEC */
void	exec_cmd_to_file(char *cmd_arg);
void	*exec_touch(const char *file);

/* PROCESS */
void	ft_child(int fd, t_pipe pipe, char *cmd);
void	ft_parent(int fd, t_pipe pipe, char *cmd);

/**/
int		open_file(char *file, enum e_mode mode);

#endif