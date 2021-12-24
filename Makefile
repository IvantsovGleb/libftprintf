CFLAGS		= -Wall -Wextra -Werror

RM			= rm -f

NAME 		= libftprintf.a

HEADER 		= libftprintf.h

SRCMODULES 	= ft_printf.c

OBJMODULES = $(SRCMODULES:.c=.o)

all: $(NAME)

$(NAME): $(OBJMODULES)
	ar crs $(NAME) $?

%.o: %.c $(HEADER)
	$(MAKE) all -C ./libft
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) clean -C ./libft
	$(RM) *.o

fclean: clean
	$(MAKE) fclean -C ./libft
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re