/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_fd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonimo <antonimo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 14:10:48 by antonimo          #+#    #+#             */
/*   Updated: 2024/10/02 14:11:08 by antonimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

bool	fd_validation(const char *fd1, const char *fd2)
{
	if (access(fd1, F_OK | R_OK) == 0)
	{
		if (access(fd2, F_OK | W_OK) == -1)
			exec_touch(fd2);
		return (true);
	}
	return (false);
}
