/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_last_char.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 19:42:27 by chanhale          #+#    #+#             */
/*   Updated: 2022/07/13 19:45:34 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../command_parse.h"

char	ft_get_last_char(char *str)
{
	int		index;
	char	ret;

	index = -1;
	ret = '\0';
	if (str == NULL)
		return ('\0');
	while (str[++index] != '\0')
		ret = str[index];
	return (ret);
}