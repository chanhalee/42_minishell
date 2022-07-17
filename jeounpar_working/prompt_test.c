#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <termios.h>
#include "../minishell/parsing/command_parse.h"

void signal_handler(int signo)
{
	if (signo == SIGINT)
	{
		printf("\n");
		rl_on_new_line();
		rl_replace_line("", 1);
		rl_redisplay();
	}
}

int main(void)
{
	char buffer[43];
	char *str;
	int intro_fd;
	int readsize;
	struct termios term;

	intro_fd = open("intro.txt", O_RDONLY);
	if (intro_fd < 0)
		return 1;
	while (1)
	{
		readsize = read(intro_fd, buffer, 42);
		buffer[42] = '\0';
		if (readsize < 1)
		{
			printf("\n");
			break;
		}
		printf("%s", buffer);
	}
	close(intro_fd);

	signal(SIGINT, signal_handler);
	signal(SIGQUIT, SIG_IGN);

	// ctrl + C 입력시 반향을 꺼줌
	tcgetattr(STDIN_FILENO, &term);
	term.c_lflag &= ~(ECHOCTL);
	tcsetattr(STDIN_FILENO, TCSANOW, &term);

	str = NULL;

	while (1)
	{
		str = readline("bash$ ");
		if (str)
		{
			if (str[0] != 0)
			{
				printf("input = %s\n", str);
				add_history(str);
			}
		}
		else
		{
			printf("\033[1A");
			printf("\033[5C");
			printf(" exit\n");
			break;
		}
		free(str);
		str = NULL;
	}
	return (0);
}
