#include "minishell.h"

int	find_var(char *word)
{
	int	i;

	i = 0;
	if (word)
		while (word[i] && word[i] != '$')
			i++;
	return (i);
}

t_str_list	*insert_list(t_str_list *splited_lines, char *env)
{
	t_str_list	*splited_env;
	t_str_list	*tmp;

	if (env)
	{
		//splited_env = shell_split(env);
		splited_env = malloc(sizeof(t_str_list));
		splited_env->s = env;
		splited_env->next = NULL;
		splited_lines->s = ft_strjoin(splited_lines->s, splited_env->s);
		if (splited_env->next)
		{
			tmp = splited_lines->next;
			splited_lines->next = splited_env->next;
			while (splited_lines->next)
				splited_lines = splited_lines->next;
			splited_lines->next = tmp;
		}
	}
	return (splited_lines);
}

t_str_list	*replace_var(int i, char *word, t_str_list *splited_lines, int *status)
{
	char		*var;
	char		*env;
	int			j;

	j = 0;
	while (word[j] && word[j] != '$' && word[j] != '"'
		&& word[j] != '\'' && !is_separator(word[j]))
		j++;
	var = ft_strldup(word, j);
	env = getenv(var);
	if (!ft_strcmp(var, "?"))
	{
		printf("$? -> %d or %d or %d\n", *status, WEXITSTATUS(*status), WTERMSIG(*status));
		if (WIFSIGNALED(*status))
			env = ft_strdup(ft_itoa(WEXITSTATUS(*status)));
		else if (WIFEXITED(*status))
			env = ft_strdup(ft_itoa(WTERMSIG(*status)));
		else
			env = ft_strdup(ft_itoa(*status));
	}
	printf("getenv(%s) = \"%s\"\n", var, env);
	splited_lines->s = ft_strldup(splited_lines->s, i);
	splited_lines = insert_list(splited_lines, env);
	if (word[j])
		splited_lines->s = ft_strjoin(splited_lines->s, word + j);
	return (splited_lines);
}

char	*remove_quotations(char *s)
{
	int		i;
	int		j;
	char	*tmp;

	printf("s[%p]:%s\n", s, s);
	i = 0;
	while (s[i])
	{
		j = 1;
		if (s[i] == '\'')
		{
			while (s[i + j] != '\'')
				j++;
			tmp = s;
			s = ft_strltrim(s, i--);
			free(tmp);
			tmp = s;
			s = ft_strltrim(s, i + j);
			free(tmp);
		}
		else if (s[i] == '"')
		{
			while (s[i + j] != '"')
				j++;
			tmp = s;
			s = ft_strltrim(s, i--);
			free(tmp);
			tmp = s;
			s = ft_strltrim(s, i + j);
			free(tmp);
		}
		i += j;
	}
	return (s);
}

t_str_list	*var_expansion(t_str_list *splited_lines, int *status)
{
	char		*word;
	t_str_list	*start;
	int			i;

	printf("expansion!\n");
	start = splited_lines;
	while (splited_lines)
	{
		word = splited_lines->s;
		i = find_var(word);
		word += i;
		while (word && *word)
		{
			word++;
			splited_lines = replace_var(i, word, splited_lines, status);
			while (*word && *word != '$' && *word != '"'
				&& *word != '\'' && !is_separator(*word))
				word++;
			i = find_var(word);
			word += i;
		}
		splited_lines = splited_lines->next;
	}
	printf("end expansion!\n");
	return (start);
}
