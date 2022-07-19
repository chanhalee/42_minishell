/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 19:57:52 by park              #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/07/19 16:36:19 by chanhale         ###   ########.fr       */
=======
/*   Updated: 2022/07/19 15:16:16 by jeounpar         ###   ########.fr       */
>>>>>>> main
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_builtin.h"
#include <stdio.h>
#include <unistd.h>

int	ft_pwd(void)
{
    char	buff[PATH_MAX];

	if (getcwd(buff, PATH_MAX) != NULL)
		printf("%s\n", buff);
	return (0);
}