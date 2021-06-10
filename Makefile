NAME	= minishell
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -I ./includes/
#CFLAGS	+= -g -fsanitize=address
LIBFT	= srcs/libft/libft.a
LIBFTDIR	= srcs/libft/
FTPRINTF	= srcs/printf/libftprintf.a
FTPRINTFDIR	= srcs/printf/
SRCDIR	= srcs/
SRCNAME	= main.c \
			utils/get_next_line.c \
			utils/get_next_line_utils.c \
			parser/parser.c \
			lexer/split.c \
			lexer/split_utils.c \
			lexer/expansion.c \
			builtin/echo.c \
			builtin/cd.c \
			builtin/pwd.c \
			builtin/export.c \
			builtin/unset.c \
			builtin/env.c \
			builtin/exit.c
SRCS	= $(addprefix $(SRCDIR), $(SRCNAME))
OBJS	= $(SRCS:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJS)
	make -C $(LIBFTDIR)
	make -C $(FTPRINTFDIR)
	$(CC) $(CFLAGS) $(LIBFT) $(FTPRINTF) $^ -o $@

clean:
	make -C $(LIBFTDIR) clean
	make -C $(FTPRINTFDIR) clean
	rm -f $(OBJS)

fclean:	clean
	make -C $(LIBFTDIR) fclean
	make -C $(FTPRINTFDIR) fclean
	rm -f $(NAME)

re:	fclean	all

.PHONY: $(NAME) all clean fclean re
