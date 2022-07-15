#include "ft_builtin.h"
#include <unistd.h>
#include <limits.h>

int main(int argc, char **argv, char **env)
{
	char **g_env;
	g_env = env;
	find_env(env, "PATH");
	// ft_cd(argv, argv);
    // ft_pwd();
    return 0;
}