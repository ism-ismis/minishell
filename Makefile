NAME	= minishell
CC		= gcc
CFLAGS	= -I ./includes/
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
			lexer/expansion.c \
			builtin_executor/echo.c \
			builtin_executor/pwd.c 
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
