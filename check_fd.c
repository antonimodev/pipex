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

/* Valida si existe el file1 y el file2, si el file2 no existe, lo crea */
bool	fd_validation(const char *file1, const char *file2)
{
	if (access(file1, F_OK | R_OK) == 0)
	{
		if (access(file2, F_OK | W_OK) == -1)
			exec_touch(file2);
		return (true);
	}
	return (false);
}
