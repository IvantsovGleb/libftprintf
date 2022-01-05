# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fsinestr <fsinestr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/05 15:53:50 by fsinestr          #+#    #+#              #
#    Updated: 2022/01/05 15:58:11 by fsinestr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

cflags		= -Wall -Wextra -Werror

rm			= rm -rf

name 		= libftprintf.a

header 		= ft_printf.h

src			= ft_printf.c ft_printf_utils.c

objs		= $(src:.c=.o)

all: $(name)

$(name): $(objs)
	ar -crs $(name) libft/ft_*.o $?

$(objs): %.o: %.c $(header)
	$(MAKE) -C libft/
	$(CC) $(cflags) -c $< -o $@

clean:
	$(MAKE) clean -C libft/
	$(rm) *.o

fclean: clean
	$(MAKE) fclean -C libft/
	$(rm) $(name)

re: fclean all

.PHONY: all clean fclean re