#include <stdio.h>
#include <stdlib.h>
#include "env_handling.h"
#include <string.h>

int main(int argc, char **argv, char **env)
{
	printf()
	memset(env[0], 0, strlen(env[0]));
	// find_env(env);
}

// env[0] = PWD=/Users/park/42cursus/minishell/env_handling
// env[1] = APPLICATION_INSIGHTS_NO_DIAGNOSTIC_CHANNEL=true
// env[n] = "??"

// heap -> 성공 : char *, 실패시 : NULL
// stack?
