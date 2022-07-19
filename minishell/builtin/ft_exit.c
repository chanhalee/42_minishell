/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 14:47:27 by park              #+#    #+#             */
/*   Updated: 2022/07/19 16:36:19 by chanhale         ###   ########.fr       */
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

void	ft_exit(char **argv)
{
	int	i;
	int	rst;

	i = 0;
	if (argv[1] == NULL)
	{
		printf("exit\n");
		exit(0);
	}
	while (argv[i] != NULL)
		i++;
	if (i > 2)
	{
		printf("bash: exit: too many arguments\n");
		return ;
	}
	else
	{
		if (check_num(argv[1]) == SUCCESS)
		{
			rst = ft_atoi(argv[1]);
			printf("exit\n");
			exit(rst);
		}
		printf("exit\n");
		printf("bash: exit: %s: numeric argument required\n", argv[1]);
		exit(1);
	}
}