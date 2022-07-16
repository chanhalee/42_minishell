/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: park <park@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 03:15:59 by park              #+#    #+#             */
/*   Updated: 2022/07/16 03:45:13 by park             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_builtin.h"
#include <stdio.h>

int	valid_env_key(char	*key)
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

status_code	ft_unset(t_list *list, char **argv)
{
	int	i;

	if (argv[1] == NULL)
		return 1;
	i = 1;
	while (argv[i] != NULL)
	{
		printf("argv = %s\n", argv[i]);
		if (valid_env_key(argv[i]) == -1)
			printf("bash: unset: `%s': not a valid identifier\n", argv[i]);
		else
			ft_lstdelone(list, argv[i]);
		i++;
	}
	return 1;
}