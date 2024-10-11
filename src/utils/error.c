/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonimo <antonimo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 10:59:17 by antonimo          #+#    #+#             */
/*   Updated: 2024/10/11 11:02:41 by antonimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex.h"

void	error_cmd(char *cmd)
{
	char	*error_msg;
	char	*test;

	error_msg = ft_strdup("command not found: ");
	test = ft_strjoin(error_msg, cmd);
	free(error_msg);
	error_msg = ft_strjoin(test, "\n");
	ft_putstr_fd(error_msg, 2);
	free(test);
	free(error_msg);
}

void	error_fd(const char *file)
{
	char	*error_msg;
	char	*test;

	error_msg = ft_strdup("no such file or directory: ");
	test = ft_strjoin(error_msg, file);
	free(error_msg);
	error_msg = ft_strjoin(test, "\n");
	ft_putstr_fd(error_msg, 2);
	free(test);
	free(error_msg);
}
