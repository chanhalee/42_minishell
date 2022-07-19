/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 01:27:14 by park              #+#    #+#             */
/*   Updated: 2022/07/19 16:36:17 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UTILS_H
# define FT_UTILS_H

#include <stdlib.h>

int		ft_strcmp(char *s1, char *s2);
int		ft_isalnum(int c);
int		ft_atoi(const char *nptr);
int		ft_isdigit(int c);
size_t	ft_strlen(char *str);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *src);
char	*ft_substr(char const *s, size_t start, size_t len);

#endif