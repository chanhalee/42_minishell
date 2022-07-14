/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 13:24:31 by chanhale          #+#    #+#             */
/*   Updated: 2022/07/12 17:32:26 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../command_parse.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	length_s1;
	size_t	iter;

	length_s1 = 0;
	iter = 0;
	while (s1[length_s1] != '\0')
		length_s1++;
	while (iter < length_s1)
	{
		if (s1[iter] != s2[iter])
			break ;
		iter++;
	}
	return (((unsigned char *)s1)[iter] - ((unsigned char *)s2)[iter]);
}
