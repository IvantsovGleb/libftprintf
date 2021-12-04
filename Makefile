CFLAGS	= -Wall -Wextra -Werror

rm		= rm -f

name 	= libftprintf.a

header 	= libftprintf.h

sources = ft_printf.c \

objects	= $(sources:.c=.o)

subdirs	= ./libft

all: $(name)

$(name): $(objects)
	ar crs $(name) $?

$(objects): $(sources) $(header)
	$(MAKE) -C $(subdirs)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) clean -C $(subdirs)
	$(rm) *.o

fclean: clean
	$(MAKE) fclean -C $(subdirs)
	$(rm) $(name)

re: fclean all

.PHONY: all clean fclean re