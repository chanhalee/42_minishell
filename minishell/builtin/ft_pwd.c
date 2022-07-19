/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 19:57:52 by park              #+#    #+#             */
/*   Updated: 2022/07/19 16:36:19 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_builtin.h"
#include <stdio.h>
#include <unistd.h>

void	ft_pwd(void)
{
    char	buff[PATH_MAX];

	if (getcwd(buff, PATH_MAX) != NULL)
	{
		printf("%s\n", buff);
		return ;
	}
}