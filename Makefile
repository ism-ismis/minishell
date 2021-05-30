NAME	= minishell
CC		= gcc
CFLAGS	= -I ./includes/
LIBFT	= srcs/libft/libft.a
LIBFTDIR	= srcs/libft/
SRCDIR	= srcs/
SRCNAME	= main.c \
			split.c \
			utils/get_next_line.c \
			utils/get_next_line_utils.c \
			parser/parser.c
SRCS	= $(addprefix $(SRCDIR), $(SRCNAME))
OBJS	= $(SRCS:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJS)
	make -C $(LIBFTDIR)
	$(CC) $(CFLAGS) $(LIBFT) $^ -o $@

clean:
	make -C $(LIBFTDIR) clean
	rm -f $(OBJS)

fclean:	clean
	make -C $(LIBFTDIR) fclean
	rm -f $(NAME)

re:	fclean	all

.PHONY: $(NAME) all clean fclean re
