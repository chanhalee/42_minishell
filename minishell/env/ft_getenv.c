/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: park <park@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 01:11:28 by park              #+#    #+#             */
/*   Updated: 2022/07/16 01:47:27 by park             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/command_parse.h"

char	*ft_getenv(char *key)
{
    t_env	*curr;
	t_list	*list;

	list = &(g_state.list);
	curr = list->head->next;
    while (curr != list->tail)
    {
        if (ft_strcmp(curr->key, key) == 0)
			return (curr->value);
        curr = curr->next;
    }
    return (NULL);
}