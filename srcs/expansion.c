#include "minishell.h"

int	find_var(char *word)
{
	int	i;

	i = 0;
	while (word[i] && word[i] != '$')
		i++;
	return (i);
}

t_str_list	*replace_var(int i, char *word, t_str_list *splited_lines)
{
	char	*var;
	char	*env;
	int		j;
	t_str_list	*splited_env;
	t_str_list	*tmp;

	j = 0;
	while (word[j] && word[j] != '$' && word[j] != '"'
		&& word[j] != '\'' && !is_separator(word[j]))
		j++;
	var = ft_strldup(word, j);
	env = getenv(var);
	if (!env)
		return (splited_lines);
	printf("getenv(%s) = [%s]\n", var, env);
	splited_env = shell_split(env);
	splited_lines->s = ft_strldup(splited_lines->s, i);
	splited_lines->s = ft_strjoin(splited_lines->s, splited_env->s);
	tmp = splited_lines->next;
	splited_lines->next = splited_env->next;
	while (splited_lines->next)
		splited_lines = splited_lines->next;
	if (word[j])
	{
		splited_lines->next = malloc(sizeof(t_str_list));
		splited_lines = splited_lines->next;
		splited_lines->s = ft_strdup(word + j);
	}
	splited_env->next = tmp;
	return (splited_env);
}

char	*remove_quotations(char *s)
{
	char	*trimed_s;

	if (*s == '\'')
		trimed_s = ft_strtrim(s, "'");
	else if (*s == '"')
		trimed_s = ft_strtrim(s, "\"");
	else
		trimed_s = s;
	return (trimed_s);
}

t_str_list	*var_expansion(t_str_list *splited_lines)
{
	char		*word;
	t_str_list	*start;
	int			i;

	start = splited_lines;
	while (splited_lines)
	{
		splited_lines->s = remove_quotations(splited_lines->s);
		word = splited_lines->s;
		i = find_var(word);
		word += i;
		while (*word)
		{
			word++;
			splited_lines = replace_var(i, word, splited_lines);
			while (*word && *word != '$' && *word != '"'
				&& *word != '\'' && !is_separator(*word))
				word++;
			i = find_var(word);
			word += i;
		}
		splited_lines = splited_lines->next;
	}
	return (start);
}
