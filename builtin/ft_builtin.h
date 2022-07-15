/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: park <park@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 18:37:36 by park              #+#    #+#             */
/*   Updated: 2022/07/15 21:17:49 by park             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BUILTIN_H
# define FT_BUILTIN_H

typedef int status_code;

# define PATH_MAX 1024

# include <stdlib.h>

int			ft_strncmp(const char *s1, const char *s2, size_t n);
size_t		ft_strlen(char *str);
status_code ft_echo(char **argv);
status_code	ft_pwd(void);
status_code ft_cd(char **argv, char **env);

#endif