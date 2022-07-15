/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: park <park@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 22:37:24 by park              #+#    #+#             */
/*   Updated: 2022/07/15 22:59:04 by park             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "ft_builtin.h"

int	find_env(char **env, char *key)
{
	int i = 0;
	while (env[i] != NULL)
	{
		printf("1\n");
		if (ft_strncmp(key, env[i], ft_strlen(key)) == 0)
		{
			printf("key, value = %s\n", env[i]);
			break;
		}
		i++;
	}
	return 1;
}