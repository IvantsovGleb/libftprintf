#ifndef PRINTF_H
# define PRINTF_H

# define OCTAL 8
# define DECIMAL 10
# define HEX 16

# include <stdarg.h>
# include "libft/libft.h"


t_list  *ft_split_format(t_list *head, const char *format);
char    *ft_recognize_conversion(void *content, va_list *args);

char    *ft_char(int c);
char    *ft_address(void *address, char *buffer);
char    *ft_utoa(unsigned long value, char *buffer, int radix);
char    *ft_utoa_upper(unsigned long value, char *buffer, int radix);

int     ft_printf(const char *, ...);

#endif