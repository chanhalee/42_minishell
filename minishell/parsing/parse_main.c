/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 12:32:33 by chanhale          #+#    #+#             */
/*   Updated: 2022/07/12 20:32:50 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./command_parse.h"
# include "./do_not_submit/do_not_submit.h"

int	main(int argc, char **argv)
{
	t_parse_token	*sep;
	int		index;

	if(argc >=2){
		printf("|%s|\n", argv[1]);
		sep = create_empty_t_parse_token();
		sep->token_type = TYPE_TOKEN_CHUNK;
		sep->string = ft_strdup(argv[1]);
		tokenize_handle_quotaion(sep);
		print_token_list(sep);
	}
	//system("leaks test");
	exit(1);
}

t_cmd_list *parse(char *raw_cmd_string)
{
	t_parse_token *token_list;
	char	*dup_cmd_str;
	
	dup_cmd_str = ft_strdup(raw_cmd_string);
	if (dup_cmd_str == NULL)
		return (NULL);
	if (add_t_parse_token_to_list(&token_list, 0,
		TYPE_TOKEN_CHUNK, NULL) == NULL)
		return (NULL);
	if (add_t_parse_token_to_list(&token_list, 0,
		TYPE_TOKEN_CHUNK, dup_cmd_str) == NULL)
		return (NULL);
	
}

// parse_env_from_str 테스트
//
// int	main(int argc, char **argv)
// {
// 	char *str1;
// 	char	**sep;
// 	int		index;

// 	if(argc >=2){
// 		str1 = ft_strdup(argv[1]);
// 		printf("|%s|\n", str1);
// 		str1 = parse_env_from_str(str1);
// 		printf("|%s|\n", str1);
// 		free (str1);
// 		//system("leaks test");
// 	}
// 	return (0);
// }

// quotaton test
// gcc *.c ./*/*.c -o test && ./test \'a\'ada\"\$ABC\"\' && rm test
// int	main(int argc, char **argv)
// {
// 	t_parse_token	*sep;
// 	int		index;

// 	if(argc >=2){
// 		printf("|%s|\n", argv[1]);
// 		sep = create_empty_t_parse_token();
// 		sep->token_type = TYPE_TOKEN_CHUNK;
// 		sep->string = ft_strdup(argv[1]);
// 		tokenize_handle_quotaion(sep);
// 		print_token_list(sep);
// 	}
// 	//system("leaks test");
// 	exit(1);
// }
