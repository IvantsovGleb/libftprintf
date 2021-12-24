#ifndef LIBFTPRINTF_FT_PRINTF_H
# define LIBFTPRINTF_FT_PRINTF_H
//# define OCTAL 8
# define DECIMAL 10
# define HEX 16
# include <stdarg.h>
# include "libft/libft.h"

//static int      ft_get_char(unsigned int reminder, const char *digigts, char format);
//static char     *ft_utoa(unsigned int n, char format);
//static void     ft_output_address(void *address);
//static void     ft_which_conversion(char c, va_list *args);
int             ft_printf(const char *, ...);

#endif