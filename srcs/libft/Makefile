# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yyamagum <yyamagum@student.42tokyo.>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/04 11:41:25 by yyamagum          #+#    #+#              #
#    Updated: 2021/06/26 14:01:39 by yyamagum         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a
CC		=	gcc
CFLAGS	=	-Wall	-Wextra	-Werror
RM		=	rm -f
INCDIR	=	./libft
SRCDIR	=	./
SRCNAME	=	ft_strdup.c ft_strjoin.c ft_atoi.c ft_strlcat.c ft_bzero.c ft_strlcpy.c ft_calloc.c ft_memccpy.c ft_strlen.c ft_isalnum.c ft_memchr.c ft_strmapi.c ft_isalpha.c ft_memcmp.c ft_strcmp.c ft_strncmp.c ft_isascii.c ft_memcpy.c ft_isspace.c ft_isdigit.c ft_memmove.c ft_strnstr.c ft_isprint.c ft_memset.c ft_strrchr.c ft_itoa.c ft_putchar_fd.c ft_strtrim.c ft_putendl_fd.c ft_substr.c ft_putnbr_fd.c ft_tolower.c ft_putstr_fd.c ft_toupper.c ft_split.c ft_strchr.c \
			ft_lstiter.c ft_lstdelone.c ft_lstadd_front.c ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c ft_lstadd_back.c ft_lstclear.c

SRCS	=	$(addprefix $(SRCDIR), $(SRCNAME))
OBJS	=	$(SRCS:.c=.o)
.c.o:
			$(CC) $(CFLAGS)	-I $(INCDIR) -c $< -o $(<:.c=.o)
$(NAME):	$(OBJS)
			ar	rc	$(NAME)	$(OBJS)
all:		$(NAME)
clean:
			$(RM) $(OBJS) 
fclean:		clean
			$(RM) $(NAME)
re:			fclean all
.PHONY:	all clean fclean re
