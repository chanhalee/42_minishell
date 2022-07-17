#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <termios.h>
#include "./command_parse.h"
# include "./do_not_submit/do_not_submit.h"

void	signal_handler(int signo)
{
	if (signo == SIGINT)
	{
		printf("\n");
		rl_on_new_line();
		rl_replace_line("", 1);
		rl_redisplay();
	}
}

int main(int argc, char **argv, char **env)
{
    char buffer[43];
	char *str;
    int intro_fd;
    int readsize;
	struct termios term;
	t_cmd_list	*cmd_lst;

	ft_initlist(&(g_state.list));
	init_env(env, &(g_state.head), &(g_state.list));
	printf("%s\n", ft_getenv("PATH"));
    // intro_fd = open("intro.txt", O_RDONLY);
    // if (intro_fd < 0)
    //     return 1;
    // while (1)
    // {
    //     readsize = read(intro_fd, buffer, 42);
	// 	buffer[42] = '\0';
    //     if (readsize < 1) {
    //         printf("\n");
    //         break;
    //     }
    //     printf("%s", buffer);
    // }
    // close(intro_fd);

	// signal(SIGINT, signal_handler);
	// signal(SIGQUIT, SIG_IGN);

	// // ctrl + C 입력시 반향을 꺼줌
    // tcgetattr(STDIN_FILENO, &term);
    // term.c_lflag &= ~(ECHOCTL);
    // tcsetattr(STDIN_FILENO, TCSANOW, &term);


    // str = NULL;

    // while(1)
    // {
    //     str = readline("bash$ ");
    //     if (str){
    //         printf("input = %s\n", str);
	// 	cmd_lst = parse(ft_p_strdup(str));
	// 	print_cmd_lists(cmd_lst);
	// 	free_t_cmd_list(cmd_lst);
	// 	}
    //     else {
	// 		printf("\033[1A");
    //         printf("\033[5C");
    //         printf(" exit\n");
    //         break ;
	// 	}
    //     add_history(str);
    //     free(str);
	// 	str = NULL;
    // }
	// system("leaks test");
    // return(0);
}
