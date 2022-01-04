#ifndef PRINTF_H
# define PRINTF_H

# define OCTAL 8
# define DECIMAL 10
# define HEX 16

# include <stdarg.h>
# include "libft/libft.h"

char    *ft_address(void *address, char *buffer);
char    *ft_utoa(unsigned long value, char *buffer, int radix);
char    *ft_utoa_upper(unsigned long value, char *buffer, int radix);

int     ft_printf(const char *, ...);

#endif