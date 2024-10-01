#include "pipex.h"

bool	cmd_validation(const char *cmd1, const char *cmd2)
{
	if (access(cmd1, F_OK) == 0)
	{
		if (access(cmd2, F_OK) == 0)
			return (true);
	}
	return (false);
}

int	main()
{
	if (cmd_validation("ls", "wc"))
		printf("sí");
	return (0);
}