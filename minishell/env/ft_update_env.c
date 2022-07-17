/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update_env.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: park <park@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 02:33:54 by park              #+#    #+#             */
/*   Updated: 2022/07/16 02:56:37 by park             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linkedlist.h"
#include <stdio.h>

void	ft_update_env(t_list *list, char *key, char *value)
{
	t_env *curr;

	printf("key = %s, value =  %s\n", key, value);
	curr = list->head->next;
    while (curr != list->tail)
    {
        if (ft_strcmp(curr->key, key) == 0)
		{
			free(curr->value);
			curr->value = ft_strdup(value);
			break;
		}
        curr = curr->next;
    }
}