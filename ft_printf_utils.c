#include "ft_printf.h"

char    *ft_recognize_conversion(int  c, va_list *args)
{
    char    buffer[sizeof(int) * 5 + 1];

    if (c == 'c')
        return (ft_char(va_arg(*args, int)));

    if (c == 's')
        return (ft_strdup(va_arg(*args, char *)));

    if (c == 'p')
        return (ft_address(va_arg(*args, void *), &buffer[sizeof(int) * 5 + 1]));

    if (c == 'd' || c == 'i')
        return (ft_itoa(va_arg(*args, int)));

    if (c == 'u')
        return (ft_utoa(va_arg(*args, unsigned int), &buffer[sizeof(int) * 5 + 1], DECIMAL));

    if (c == 'x')
        return (ft_utoa(va_arg(*args, unsigned int), &buffer[sizeof(int) * 5 + 1], HEX));

    if (c == 'X')
        return (ft_utoa_upper(va_arg(*args, unsigned int), &buffer[sizeof(int) * 5 + 1], HEX));

    if (c == '%')
        return (ft_char('%'));

    return ((void *) 0);
}