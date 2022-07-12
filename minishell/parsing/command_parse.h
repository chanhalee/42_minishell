/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_parse.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 12:32:25 by chanhale          #+#    #+#             */
/*   Updated: 2022/07/13 00:32:51 by chanhale         ###   ########.fr       */
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
# define TYPE_RED_LEFT 0

# define TYPE_TOKEN_CHUNK 11
# define TYPE_TOKEN_ARGV 22
# define TYPE_TOKEN_SPACE 33
# define TYPE_TOKEN_IO_RED 44
# define TYPE_TOKEN_PIPELINE 55
# define TYPE_TOKEN_EXEC 66

typedef struct s_cmd_redirection
{
	char						*file;
	int							red_type;
	struct s_cmd_redirection	*next;
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
	struct s_parse_token	*next;
}	t_parse_token;

t_cmd_list		*create_empty_t_cmd_list(void);
t_cmd			*add_empty_t_cmd(t_cmd_list *cmd_list);
void			free_first_t_cmd_node(t_cmd_list *cmd_list);
void			free_t_cmd_list(t_cmd_list *cmd_list);
t_cmd			*get_last_node(t_cmd *cmd_list);
t_cmd			*get_empty_t_cmd(void);
char			*ft_strdup(const char *src);
char			*ft_strtrim(char const *s1, char const *set);
char			*ft_strchr(const char *s, int c);
char			**ft_split_custom(char const *s, char c);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
int				ft_strcmp(const char *s1, const char *s2);
size_t			ft_strlen(const char *s);
t_parse_token	*add_token(t_parse_token **token_list, size_t index, int type, char *content);
t_parse_token	*create_empty_t_parse_token(void);
void			free_t_parse_token_list(t_parse_token *token_list);
void			free_single_t_parse_token(t_parse_token *token_list);
t_parse_token	*parse_tokenize(char *cmd_string);
void			*parse_err_free_two_d_char(char **ptr, int max);
void			*parse_err_free_multi_str(char *ptr1, char *ptr2, char *ptr3, char *ptr4);
char 			*parse_env_from_str(char *str);
void			parse_env_from_token_list(t_parse_token *tok_lst);
void			tokenize_handle_quotaion(t_parse_token *tok_list);
char			**seperate_quote(char *str);
void			parse_tokenize_space(t_parse_token *tok_lst);

#endif