#include "ft_printf.h"

char    *ft_char(char *content, int c)
{
    char    *chr;
    char    *ret;

    chr = malloc(2);
    if (!chr)
        return ((void *) 0);
    chr[0] = (char)c;
    chr[1] = '\0';
    ret = ft_strjoin(content, (char *)chr);
    free(chr);
    return (ret);
}
