#include "ft_printf.h"

char    *ft_utoa(unsigned long value, char *buffer, int radix)
{
    char            *digits;

    digits = "0123456789abcdef";
    if (radix == OCTAL || radix == DECIMAL || radix == HEX)
    {
        *--buffer = '\0';
        while (value > 0)
        {
            *--buffer = digits[value % radix];
            value /= radix;
        }
        return (ft_strdup(buffer));
    }
    return ((void *) 0);
}

char    *ft_utoa_upper(unsigned long value, char *buffer, int radix)
{
    char    *s;

    s = ft_utoa(value, buffer, radix);
    if (!s)
        return ((void *) 0);
    while (s)
    {
        *s = (char)ft_toupper(*s);
        s++;
    }
    return (s);
}