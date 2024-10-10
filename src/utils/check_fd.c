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

#include "../../include/pipex.h"

bool	fd_validation(const char *file1)
{
	if (access(file1, F_OK | R_OK) == 0)
		return (true);
	perror("fd");
	return (false);
}
