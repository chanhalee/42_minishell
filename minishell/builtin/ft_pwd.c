/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: park <park@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 19:57:52 by park              #+#    #+#             */
/*   Updated: 2022/07/15 20:14:37 by park             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_builtin.h"
#include <stdio.h>
#include <unistd.h>

status_code ft_pwd(void)
{
    char	buff[PATH_MAX];

	if (getcwd(buff, PATH_MAX) != NULL)
	{
		printf("%s\n", buff);
		return 1;
	}
	return 0;
}