/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linkedlist.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: park <park@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 23:14:48 by park              #+#    #+#             */
/*   Updated: 2022/07/16 01:09:03 by park             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINKEDLIST_H
# define LINKEDLIST_H

# include <stdlib.h>

typedef struct s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
	struct s_env	*prev;
}	t_env;

typedef struct s_list
{
    t_env *head;
    t_env *tail;
    int count;
}	t_list;

int		init_env(char **env, t_env **head, t_list *list);
int		ft_strcmp(char *s1, char *s2);
int		ft_lstdelone(t_list *list, char *key);
char	*ft_substr(char const *s, size_t start, size_t len);
size_t	ft_strlen(const char *str);
t_env	*ft_lstnew(char *key, char *value);
void	ft_lstadd(t_list *list, char *key, char *value);
void	ft_initlist(t_list *list);
void	ft_viewall(t_list *list);

#endif