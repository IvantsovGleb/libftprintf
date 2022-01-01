#include "printf.h"

int     ft_get_char(unsigned int reminder, const char *digigts, char format)
{
    if (reminder > 9 && format == 'X')
        return (ft_toupper(digigts[reminder]));
    return (digigts[reminder]);
}

char*    ft_output_address(void *address)
{
    static unsigned char     buffer[sizeof(unsigned int) * 8 + 1];
    unsigned long   num;

    num = (unsigned long)address;
    if (num >= HEX)
        ft_output_address((void *)(num / HEX));
    else
        ft_putstr_fd("0x", 1);
    ft_putchar_fd((char)ft_get_char(num % HEX, "0123456789abcdef", 'u'), 1);
}
