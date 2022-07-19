/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 14:47:27 by park              #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/07/19 16:36:19 by chanhale         ###   ########.fr       */
=======
/*   Updated: 2022/07/19 15:29:26 by jeounpar         ###   ########.fr       */
>>>>>>> main
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_builtin.h"
#include <stdio.h>

static int	check_num(char *str)
{
	int	i;

	i = 0;
	while(str[i] == '-' || str[i] == '+')
		i++;
	while(str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return FAIL;
		i++;
	}
	return SUCCESS;
}

int	ft_exit(char **argv)
{
	int	i;
	int	rst;

	i = 0;
	if (argv[1] == NULL)
	{
		printf("exit\n");
		return(34);
	}
	while (argv[i] != NULL)
		i++;
	if (i > 2)
	{
		printf("bash: exit: too many arguments\n");
		return (255);
	}
	else
	{
		if (check_num(argv[1]) == SUCCESS)
		{
			rst = ft_atoi(argv[1]);
			printf("exit\n");
			return (rst);
		}
		printf("exit\n");
		printf("bash: exit: %s: numeric argument required\n", argv[1]);
		return (255);
	}
}