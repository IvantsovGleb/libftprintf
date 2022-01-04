cflags		= -Wall -Wextra -Werror

rm			= rm -rf

name 		= libftprintf.a

header 		= ft_printf.h

src			= ft_printf.c ft_printf_utils.c ft_utoa.c

objs		= $(src:.c=.o)

all: $(name)

$(name): $(objs)
	ar crs $(name) *.o

$(objs): %.o: %.c $(header)
	$(MAKE) -C libft/
	ar x libft/libft.a
	$(CC) $(cflags) -c $< -o $@

clean:
	$(MAKE) clean -C libft/
	$(rm) *.o

fclean: clean
	$(MAKE) fclean -C libft/
	$(rm) $(name)

re: fclean all

.PHONY: all clean fclean re