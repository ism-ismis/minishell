#include "minishell.h"

int	main(void)
{
	char	*line;
	char	**splited_lines;
	int		i;

	write(1, "minishell > ", 12);
	while (get_next_line(0, &line) == 1)
	{
		splited_lines = shell_split(line);
		if (!ft_strcmp(line, "exit"))
			exit(0);
		i = 0;
		while (splited_lines[i])
		{
			printf("%d %s\n", i, splited_lines[i]);
			i++;
		}
		free(line);
		write(1, "minishell > ", 12);
	}
	return (0);
}
