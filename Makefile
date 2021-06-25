NAME	= minishell
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -I ./includes/
#INCLUDES	= ./includes/
RFLAGS	= -I $(shell brew --prefix readline)/include
#CFLAGS	+= -I $(shell brew --prefix readline)/include
LDFLAGS = -lreadline -lhistory -L$(shell brew --prefix readline)/lib
#CFLAGS += -lreadline -lhistory -L$(shell brew --prefix readline)/lib
# CFLAGS	+= -g -fsanitize=address
LIBFT	= srcs/libft/libft.a
LIBFTDIR	= srcs/libft/
FTPRINTF	= srcs/printf/libftprintf.a
FTPRINTFDIR	= srcs/printf/
SRCDIR	= srcs/
SRCNAME	= main.c \
			utils/get_next_line.c \
			utils/get_next_line_utils.c \
			utils/error.c \
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
			builtin/exit.c \
			exec/redirect.c
SRCS	= $(addprefix $(SRCDIR), $(SRCNAME))
OBJS	= $(SRCS:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJS)
	make -C $(LIBFTDIR)
	make -C $(FTPRINTFDIR)
	$(CC) $(CFLAGS) $(LDFLAGS) $(LIBFT) $(FTPRINTF) $^ -o $@
#	$(CC) $(CFLAGS) $(RFLAGS) $(LDFLAGS) $(LIBFT) $(FTPRINTF) $^ -o $@

fclean:	clean
	make -C $(LIBFTDIR) fclean
	make -C $(FTPRINTFDIR) fclean
	rm -f $(NAME)

re:	fclean	all

#.c.o:
#	$(CC) $(CFLAGS)  $^
#	$(CC) $(CFLAGS) -I $(INCLUDES) $(RFLAGS) $(LDFLAGS) $^

.PHONY: $(NAME) all clean fclean re
