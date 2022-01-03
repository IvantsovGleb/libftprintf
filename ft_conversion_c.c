#include "ft_printf.h"

char    *ft_char(int c)
{
    char    *chr;

    chr = malloc(2);
    if (!chr)
        return ((void *) 0);
    chr[0] = (char)c;
    chr[1] = '\0';
    return (chr);
}