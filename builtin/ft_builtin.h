/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: park <park@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 18:37:36 by park              #+#    #+#             */
/*   Updated: 2022/07/16 03:37:51 by park             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BUILTIN_H
# define FT_BUILTIN_H

typedef int status_code;

# define PATH_MAX 1024

# include "ft_utils.h"
# include "./linkedlist/linkedlist.h"
# include "ft_utils.h"

int			find_env(char **env, char *key);
status_code ft_echo(char **argv);
status_code	ft_pwd(void);
status_code ft_cd(char **argv, t_list *list);
status_code	ft_unset(t_list *list, char **argv);

#endif