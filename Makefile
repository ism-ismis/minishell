NAME	= minishell
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -I ./includes/
RFLAGS	= -I $(shell brew --prefix readline)/include
LDFLAGS = -lreadline -lhistory -L$(shell brew --prefix readline)/lib
# CFLAGS	+= -g -fsanitize=address
LIBFT	= srcs/libft/libft.a
LIBFTDIR	= srcs/libft/
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
			exec/redirect.c \
			exec/command_path.c
SRCS	= $(addprefix $(SRCDIR), $(SRCNAME))
OBJS	= $(SRCS:.c=.o)
LIBS	= -lft -L $(LIBFTDIR)

all:		$(NAME)

$(NAME):	$(OBJS) $(LIBFT)
			$(MAKE) -C $(LIBFTDIR)
			$(CC) $(CFLAGS) $(RFLAGS) $(LDFLAGS) $(OBJS) $(LIBS) -o $(NAME)
$(LIBFT):
			$(MAKE) -C $(LIBFTDIR)

clean:
	$(MAKE) -C $(LIBFTDIR) clean
	rm -f $(OBJS)

fclean:	clean
	$(MAKE) -C $(LIBFTDIR) fclean
	rm -f $(NAME)

re:	fclean	all

.PHONY: $(NAME) all clean fclean re
