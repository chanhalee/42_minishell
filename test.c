# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

void	signal_handler(int signo)
{
	if (signo == SIGINT)
	{
		printf("\n");
		rl_on_new_line();
		rl_replace_line("", 1);
		rl_redisplay();
		// str = readline("bash& ");
	}
}

int main(void)
{
    char buffer[43];
	char *str;
    int intro_fd;
    int readsize;
	

    intro_fd = open("intro.txt", O_RDONLY);
    if (intro_fd < 0)
        return 1;
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

	signal(SIGINT, signal_handler);
    str = NULL;

    while(1)
    {
        str = readline("bash$ ");
        if (str)
            printf("%s\n", str);
        else
            break ;
        add_history(str);
        free(str);
		str = NULL;
    }
    return(0);
}
