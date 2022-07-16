#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

int main(int argc2, char **argv2, char **env)
{
	int pid;
	int status;

	char **new_argv;
	int argc = 2;
	new_argv = (char **)malloc((argc + 1) * sizeof(char *));
	new_argv[0] = (char *)malloc(256 * sizeof(char));
	new_argv[1] = (char *)malloc(256 * sizeof(char));
	new_argv[2] = (char *)malloc(256 * sizeof(char));

	pid = fork();
	if (pid > 0)
	{
		printf("부모 프로세스 생성\n");
		wait(&status);
		printf("자식 프로세스 기다리기 끝\n");
	}
	else if (pid == 0)
	{
		printf("자식 프로세스 생성\n");

		// cat < a.tx > b.tx > c.tx
		int fd = open("a.tx", O_WRONLY, 644);
		// int fd2 = open("b.tx", O_WRONLY | O_CREAT, 0644);
		// int fd3 = open("c.tx", O_WRONLY | O_CREAT, 0644);
		// dup2(fd, 0);
		// dup2(fd2, 1);
		// dup2(fd3, 1);
		strcpy(new_argv[0], "ls");
		strcpy(new_argv[1], "-al");
		new_argv[argc] = NULL;
		// 맨 마지막은 NULL
		execve(new_argv[0], new_argv, env);
		// free(new_argv[0]);
		// free(new_argv[1]);
		// free(new_argv[2]);
		// free(new_argv);
	}
	else if (pid <= -1)
	{
		perror("fork error : ");
		exit(0);
	}
}