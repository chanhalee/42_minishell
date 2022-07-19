#include <stdlib.h>
#include <unistd.h>

int	main(int argc, char *argv[], char *envp[])
{
	pid_t	pid;
	int		pde[2];

	pipe(pde);
	pid = fork();
	if (pid == 0)
	{
		dup2(pde[1], 1);
		close(pde[1]);
		execve("/bin/ls", (char *[]){"/bin/ls", "-l", NULL}, NULL);
	}
	else
	{
		close(pde[1]);
		pid = fork();
		if (pid == 0)
		{
			dup2(pde[0], 0);
			close(pde[0]);
			execve("/bin/cat", (char *[]){"/bin/cat", "-e",  NULL}, NULL);
		}
		close(pde[0]);
	}
}