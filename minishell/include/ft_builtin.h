/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeounpar <jeounpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 18:37:36 by park              #+#    #+#             */
/*   Updated: 2022/07/18 17:06:10 by jeounpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BUILTIN_H
# define FT_BUILTIN_H

# define PATH_MAX 1024
# define SUCCESS 1
# define FAIL 0

# include "ft_utils.h"
# include "linkedlist.h"
# include "command_parse.h"

int		find_env(char **env, char *key);
void	ft_echo(char **argv, t_list *list);
void	ft_exit(char **argv);
void	ft_pwd(void);
void	ft_env(t_list *list);
void	ft_cd(char **argv, t_list *list);
void	ft_unset(char **argv, t_list *list);
void	ft_exec(t_cmd_list *lists);
void	ft_export(char **argv, t_list *list);

#endif