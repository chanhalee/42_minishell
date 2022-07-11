# include <readline/readline.h>
# include <readline/history.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

int main(void)
{
    char *str;
    char buffer[42];
    int intro_fd;
    int readsize;

    intro_fd = open("intro.txt", O_RDONLY);
    if (intro_fd < 0)
        return 1;
    while (1)
    {
        readsize = read(intro_fd, buffer, 42);
        if (readsize < 1) {
            printf("\n");
            break;
        }
        printf("%s", buffer);
    }
    close(intro_fd);
    
    while(1)
    {
        str = readline("bash$ ");
        if (str)
            printf("%s\n", str);
        else
            break ;
        add_history(str);
        free(str);
    }
    return(0);
}
