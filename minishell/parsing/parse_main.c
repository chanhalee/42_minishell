/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 12:32:33 by chanhale          #+#    #+#             */
/*   Updated: 2022/07/13 01:16:58 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./command_parse.h"
# include "./do_not_submit/do_not_submit.h"

int	main(int argc, char **argv)
{
	char	**sep;
	t_parse_token *tok;
	int		index = -1;

	if(argc >=2){
		printf("|%s|\n", argv[1]);
		tok = parse_tokenize(ft_strdup(argv[1]));
		print_token_list(tok);
		free_t_parse_token_list(tok);
	}
	//system("leaks test");
	exit(1);
	return (0);
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
// 		sep->next = NULL;
// 		print_token_list(sep);
// 		tokenize_handle_quotaion(sep);
// 		print_token_list(sep);
// 	}
// 	//system("leaks test");
// 	exit(1);
// }
