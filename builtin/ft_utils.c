/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: park <park@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 18:46:01 by park              #+#    #+#             */
/*   Updated: 2022/07/15 23:00:00 by park             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t ft_strlen(char *str)
{
    size_t i;

	i = 0;
    while (str[i] != '\0')
        i++;
    return i;
}

int		ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	if (s1 == 0)
		return (-1);
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	if (s1[i] == '\0' && s2[i] == '\0')
		return (0);
	return (s1[i] - s2[i]);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*s1_str;
	unsigned char	*s2_str;

	i = 0;
	s1_str = (unsigned char *)s1;
	s2_str = (unsigned char *)s2;
	while (n--)
	{
		if (s1_str[i] != s2_str[i] || s1_str[i] == '\0'
			|| s2_str[i] == '\0')
			return (s1_str[i] - s2_str[i]);
		i++;
	}
	return (0);
}
