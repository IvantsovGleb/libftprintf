#include "printf.h"

char    *ft_address(void *address, char *buffer)
{
    return (ft_strjoin("0x", ft_utoa((unsigned long)address, buffer, HEX)))
}