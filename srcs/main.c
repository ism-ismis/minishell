#include "minishell.h"

int	main(void)
{
	char		*line;
	t_str_list	*splited_lines;

	write(1, "minishell > ", 12);
	while (minishell_get_next_line(0, &line) == 1)
	{
		splited_lines = shell_split(line);
		var_expansion(splited_lines);
		while (splited_lines)
		{
			printf("%s\n", splited_lines->s);
			if (!ft_strcmp(splited_lines->s, "exit"))
				exit(0);
			splited_lines = splited_lines->next;
		}
		free(line);
		write(1, "minishell > ", 12);
	}
	return (0);
}
