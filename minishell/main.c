#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <termios.h>
#include "./include/command_parse.h"
#include "./include/ft_builtin.h"

# include "./parsing/do_not_submit/do_not_submit.h"

int ft_exec(t_cmd_list *lists);

void	signal_handler(int signo)
{
	if (signo == SIGINT)
	{
		if (g_state.is_fork == 0)
		{
			printf("\n");
			rl_on_new_line();
			rl_replace_line("", 1);
			rl_redisplay();
			g_state.exit_code = 1;
		}
		else
		{
			g_state.exit_code = 130;
			printf("\n");
		}
	}
}

void	print_intro(void)
{
	int		intro_fd;
    int		readsize;
	char	buffer[43];

	intro_fd = open("intro.txt", O_RDONLY);
    if (intro_fd < 0)
	{
		printf("fail to open intro.txt\n");
        return ;
	}
    while (1)
    {
        readsize = read(intro_fd, buffer, 42);
		buffer[42] = '\0';
        if (readsize < 1) {
            printf("\n");
            break;
        }
        printf("%s", buffer);
    }
    close(intro_fd);
}

void	init_env_and_signal(char **env)
{
	struct termios term;

	ft_initlist(&(g_state.list));
	init_env(env, &(g_state.head), &(g_state.list));
	g_state.exit_code = 0;

	signal(SIGINT, signal_handler);
	signal(SIGQUIT, SIG_IGN);

    tcgetattr(STDIN_FILENO, &term);
    term.c_lflag &= ~(ECHOCTL);
    tcsetattr(STDIN_FILENO, TCSANOW, &term);
}

void	prompt(t_cmd_list *cmd_lst, char *str)
{
	int ret;

    while(1)
    {
        str = readline("bash$ ");
        if (str)
		{
			if (str[0] != 0)
			{
				cmd_lst = parse(ft_p_strdup(str));
				// print_cmd_lists(cmd_lst);
				ft_heredoc(cmd_lst);
				if (cmd_lst->status == TYPE_SYNTAX_ERR)
					printf("bash: syntax error near unexpected token `%s'\n", cmd_lst->cmd_list->exec_file_name);
				else
					ret = ft_exec(cmd_lst);
				unlink_tmp_file(cmd_lst);
				free_t_cmd_list(cmd_lst);
				add_history(str);
				// printf("exit_code = %d\n", g_state.exit_code);
			}
		}
        else
		{
			printf("\033[1A");
            printf("\033[5C");
            printf(" exit\n");
            break ;
		}
		free(str);
		str = NULL;
		if (ret == 34)
			return ;
    }
}

int main(int argc, char **argv, char **env)
{
	t_cmd_list	*cmd_lst;
	char		*str;
	
	print_intro();
	init_env_and_signal(env);
	prompt(cmd_lst, str);

	system("leaks minishell");
    return(0);
}
