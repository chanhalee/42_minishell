/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: park <park@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 21:26:46 by park              #+#    #+#             */
/*   Updated: 2022/07/15 22:32:56 by park             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

char	*find_env(char **env)
{
	int	idx;

	idx = -1;
	while (env[++idx] != NULL)
		printf("%s\n", env[idx]);
	return NULL;
}