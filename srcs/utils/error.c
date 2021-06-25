#include "minishell.h"
#include "utils.h"

void	error_numeric_argument(char *str)
{
    ft_putstr_fd("bash: exit: ", 2);
    ft_putstr_fd(str, 2);
    ft_putendl_fd(": numeric argument required", 2);
}