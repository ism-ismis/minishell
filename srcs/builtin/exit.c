#include "minishell.h"
#include "utils.h"
#include "parser.h"
#include <limits.h>

int	is_overflow(long long n, int sign, char *str)
{
	int is_next_num;

    is_next_num = ft_isdigit(str[1]);
    if (is_next_num == 0)
        return (0);
    n *= sign;
	if (is_next_num && (n > LONG_MAX / 10 || (n == LONG_MAX / 10 && str[1] > '7')))
        return (1);
    else if (is_next_num && (n < LONG_MIN / 10 || (n == LONG_MIN / 10 && str[1] > '8')))
        return (1);
	return (0);
}

int	is_digit_without_overflow(char *str)
{
	int				sign;
	long long		res;

	sign = 1;
	res = 0;
	while ((*str >= '\t' && *str <= '\r') || *str == ' ')
		str++;
	if (*str == '-')
	{
		sign *= -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str && ft_isdigit(*str))
	{
		printf("in loop\n");
        if (res)
			res *= 10;
		res += *str - '0';
		if (is_overflow(res, sign, str) == 1)
			return (0);
		str++;
	}
	if (*str != '\0')
		return (0);
    return (1);
}

void	free_node(t_node *node)
{
	int	i;

	if (node)
	{
		if (node->lhs)
			free_node(node->lhs);
		if (node->rhs)
			free_node(node->rhs);
		i = 1;
		if (node->tokens)
		{
			while (node->tokens[i])
				free(node->tokens[i++]);
			free(node->tokens);
		}
	}
}

void	ft_exit(t_node *node)
{
	int	exit_code;
	
	exit_code = 0;
	if (node->tokens[1])
	{
		if (is_digit_without_overflow(node->tokens[1]))
			exit_code = ft_atoi(node->tokens[1]);
		else
		{
			error_numeric_argument(node->tokens[1]);
			exit_code = 255;
		}
	}
	printf("exit code:%d\n", exit_code);
	// system("leaks minishell");
	exit(exit_code);
}
