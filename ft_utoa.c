//
// Created by Gleb Ivantsov on 01.01.2022.
//

#include "printf.h"

int     ft_get_char(unsigned int reminder, const char *digigts, char format)
{
    if (reminder > 9 && format == 'X')
        return (ft_toupper(digigts[reminder]));
    return (digigts[reminder]);
}

static char     *ft_utoa(unsigned int n, char format)
{
    unsigned char     buffer[sizeof(unsigned int) * 8 + 1];
    size_t  bsize;
    int     radix;

    bsize = sizeof(unsigned int) * 8;
    buffer[bsize] = '\0';
    if (format == 'u')
        radix = DECIMAL;
    else
        radix = HEX;
    while (n)
    {
        buffer[--bsize] = ft_get_char(n % radix, "0123456789abcdef", format);
        n /= radix;
    }
    return (ft_strdup((const char *) &buffer[bsize]));
}

char    *utoa(unsigned int value, char *buffer, int radix)
{
    char            *digits;
    unsigned int    bsize;

    digits = "0123456789abcdef";
    if (radix == OCTAL || radix == DECIMAL || radix == HEX)
    {
        while (value)
        {
            buffer[--bsize] = digits[value % radix];
            value /= radix;
        }
    }
    return ((void *) 0);
}