/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: park <park@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 18:37:36 by park              #+#    #+#             */
/*   Updated: 2022/07/15 23:14:36 by park             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BUILTIN_H
# define FT_BUILTIN_H

typedef int status_code;

# define PATH_MAX 1024

# include <stdlib.h>

int			ft_strcmp(char *s1, char *s2);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			find_env(char **env, char *key);
size_t		ft_strlen(char *str);
status_code ft_echo(char **argv);
status_code	ft_pwd(void);
status_code ft_cd(char **argv, char **env);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strdup(const char *src);

#endif