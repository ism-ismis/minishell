/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyamagum <yyamagum@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 00:58:32 by yyamagum          #+#    #+#             */
/*   Updated: 2021/06/09 10:28:59 by yyamagum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <limits.h>
# define BUFFER_SIZE 10
# define QUOTE 1
# define DQUOTE 2

int			minishell_get_next_line(int fd, char **line);
char		*ft_strljoin(char const *s1, char const *s2, int len);
char		*ft_strldup(const char *src, long len);
char		*stradd(char *s1, char *s2);
void		ft_bzero(void *s, size_t n);
int			handle_odd_quote(int quote_type);

#endif
