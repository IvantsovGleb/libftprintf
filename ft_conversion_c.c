#include "printf.h"

char    *ft_char(int c)
{
    int     *chr;

    chr = malloc(2);
    if (!chr)
        return ((void *) 0);
    chr[0] = c;
    chr[1] = 0;
    return ((char *)chr);
}
