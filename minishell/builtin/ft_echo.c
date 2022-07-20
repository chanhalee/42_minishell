/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeounpar <jeounpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 18:37:43 by park              #+#    #+#             */
/*   Updated: 2022/07/21 00:07:51 by jeounpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_builtin.h"
#include <stdio.h>

static void	echo_helper(char **argv, int idx)
{
	char	*key;
	char	*value;

	while (argv[idx] != NULL)
	{
		if (argv[idx][0] == '$')
		{
			key = ft_substr(argv[idx], 1, ft_strlen(argv[idx]));
			value = ft_getenv(key);
			printf("%s\n", value);
			free(key);
		}
		else
			printf("%s", argv[idx]);
		if (argv[idx + 1] != NULL)
			printf(" ");
		idx++;
	}
}

int	ft_echo(char **argv, t_list *list)
{
	int		newline;
	int		idx;
	char	*key;
	char	*value;

	newline = 0;
	idx = 1;
	if (ft_strcmp(argv[1], "-n") == 0)
	{
		idx = 2;
		newline = 1;
	}
	echo_helper(argv, idx);
	if (newline == 0)
		printf("\n");
	return (0);
}
