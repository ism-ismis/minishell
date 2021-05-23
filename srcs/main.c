#include "minishell.h"

int	main(void)
{
	char *line;

	write(1, "minishell > ", 12);
	while (get_next_line(0, &line) == 1)
	{
		if (!ft_strcmp(line, "exit"))
			exit(0);
		printf("%s\n", line);
		free(line);
		write(1, "minishell > ", 12);
	}
	return (0);
}
