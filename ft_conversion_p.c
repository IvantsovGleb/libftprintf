#include "ft_printf.h"

char    *ft_address(void *address, char *buffer)
{
    char    *tmp;
    char    *add;

    tmp = ft_utoa((unsigned long)address, buffer, HEX);
    add = ft_strjoin("0x", tmp);
    free(tmp);
    return (add);
}