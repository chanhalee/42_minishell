/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeounpar <jeounpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 19:57:52 by park              #+#    #+#             */
/*   Updated: 2022/07/18 15:21:09 by jeounpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_builtin.h"
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