#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define OCTAL 8
# define DECIMAL 10
# define HEX 16

# include <stdarg.h>
# include "libft/libft.h"

//typedef char *(*f)(void *);

t_list  *ft_split_format(t_list *head, const char *format);
char    *ft_recognize_conversion(void *content, va_list *args);

char    *ft_char(int c);
char    *ft_address(void *address);

int     ft_printf(const char *, ...);

#endif