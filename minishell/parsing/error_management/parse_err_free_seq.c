/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_err_free_seq.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 15:49:28 by chanhale          #+#    #+#             */
/*   Updated: 2022/07/12 17:43:38 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../command_parse.h"

void	*parse_err_free_two_d_char(char **ptr)
{
	int	index;

	index = -1;
	if (ptr == NULL)
		return (NULL);
	while (ptr[++index] != NULL)
		free(ptr[index]);
	free(ptr);
	return (NULL);
}

void	*parse_err_free_multi_str(char *ptr1, char *ptr2, char *ptr3, char *ptr4)
{
	if (ptr1 != NULL)
		free(ptr1);
	if (ptr2 != NULL)
		free(ptr2);
	if (ptr3 != NULL)
		free(ptr3);
	if (ptr4 != NULL)
		free(ptr4);
	return (NULL);
}
