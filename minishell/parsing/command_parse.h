/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_parse.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 12:32:25 by chanhale          #+#    #+#             */
/*   Updated: 2022/07/10 22:49:41 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_PARSE_H
# define COMMAND_PARSE_H

# include <unistd.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>

# define TYPE_ERR_CODE_ALLOC 1
# define TYPE_INITIAL_STATUS 0
# define TYPE_TOKEN_LOW_PIPELINE 11
# define TYPE_TOKEN_LOW_CMD 12

typedef struct s_cmd_redirection
{
	char				*file;
	int					red_type;
	t_cmd_redirection	*next;
}	t_cmd_redirection;

typedef	struct s_cmd
{
	char						*exec_file_path;
	char						**environment;
	char						**argv;
	char						**input_buffer;
	char						*output_buffer;
	struct s_cmd_redirection	*redirection_list;
	struct s_cmd				*next;
}	t_cmd;

typedef	struct s_cmd_list
{
	struct s_cmd				*cmd_list;
	char						*first_cmd_input;
	int							status;
	struct s_cmd_list			*next_list;
}	t_cmd_list;

typedef	struct s_parse_token
{
	int						token_type;
	char					*string;
	struct s_string_list	*next;
}	t_parse_token;

t_cmd_list		*create_empty_t_cmd_list(void);
t_cmd			*add_empty_t_cmd(t_cmd_list *cmd_list);
void			free_first_t_cmd_node(t_cmd_list *cmd_list);
t_cmd			*get_last_node(t_cmd *cmd_list);
t_cmd			*get_empty_t_cmd(void);
char			*ft_strdup(const char *src);
char			*ft_strtrim(char const *s1, char const *set);
char			*ft_strchr(const char *s, int c);
char			**ft_split(char const *s, char c);

#endif