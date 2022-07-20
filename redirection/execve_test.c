#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

int main(void)
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
		int exit_code;
		// printf("부모 프로세스 생성\n");
		wait(&status);
		exit_code = WEXITSTATUS(status);
		printf("exit_code = %d\n", exit_code);
		// printf("자식 프로세스 기다리기 끝\n");
	}
	else if (pid == 0)
	{
		// // dup2(fd2, 1);
		// // dup2(fd3, 1);
		strcpy(new_argv[0], "/bin/qwe");
		// new_argv[0] = NULL;
		new_argv[1] = NULL;
		// strcpy(new_argv[1], "");
		// printf("%s %s\n", new_argv[0], new_argv[1]);
		new_argv[argc] = NULL;
		// 맨 마지막은 NULL
		execve(new_argv[0], new_argv, NULL);
		printf("qqq\n");
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