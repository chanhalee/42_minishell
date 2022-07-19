/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 03:15:59 by park              #+#    #+#             */
/*   Updated: 2022/07/19 16:36:20 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_builtin.h"
#include <stdio.h>

static int	valid_env_key(char	*key)
{
	int	i;

	i = 0;
	while (key[i] != '\0')
	{
		if ((key[i] >= '0' && key[i] <= '9') || (key[i] >= 'a'
			&& key[i] <= 'z') || (key[i] >= 'A' || key[i] <= 'Z'))
			;
		else
			return (-1);
		i++;
	}
	return 1;
}

void	ft_unset(char **argv, t_list *list)
{
	int	i;

	if (argv[1] == NULL)
		;
	i = 1;
	while (argv[i] != NULL)
	{
		if (valid_env_key(argv[i]) == -1)
			printf("bash: unset: `%s': not a valid identifier\n", argv[i]);
		else
			ft_lstdelone(list, argv[i]);
		i++;
	}
}
