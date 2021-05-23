/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyamagum <yyamagum@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 00:58:32 by yyamagum          #+#    #+#             */
/*   Updated: 2021/05/24 00:01:23 by yyamagum         ###   ########.fr       */
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

int			get_next_line(int fd, char **line);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strldup(const char *src, long len);
char		*stradd(char *s1, char *s2);
void		ft_bzero(void *s, size_t n);

#endif
