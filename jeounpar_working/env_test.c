#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv, char **env)
{
	int idx = 0;
	while (env[idx] != NULL)
	{
		printf("%s\n", env[idx]);
		idx++;
	}
}