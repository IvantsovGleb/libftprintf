#include "ft_printf.h"
#include <stdio.h>

static int     ft_get_char(unsigned int reminder, const char *digigts, char format)
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

static void     ft_output_address(void *address)
{
    unsigned long   num;

    num = (unsigned long)address;
    if (num >= HEX)
        ft_output_address((void *)(num / HEX));
    else
        ft_putstr_fd("0x", 1);
    ft_putchar_fd((char)ft_get_char(num % HEX, "0123456789abcdef", 'u'), 1);
}

static void     ft_which_conversion(char c, va_list *args)
{
    char *str;

    if (c == '%')
        ft_putchar_fd('%', 1);
    if (c == 'c')
        ft_putchar_fd((char) va_arg(*args, int), 1);
    if (c == 's')
        ft_putstr_fd(va_arg(*args, char *), 1);
    if (c == 'p')
        ft_output_address(va_arg(*args, void *));
    if (c == 'd' || c == 'i')
        ft_putnbr_fd(va_arg(*args, int), 1);
    str = NULL;
    if (c == 'u' || c == 'x' || c == 'X')
    {
        str = ft_utoa(va_arg(*args, unsigned int), c);
        ft_putstr_fd(str, 1);
        free(str);
    }
}

int     ft_printf(const char *format, ...)
{
    size_t      i;
    va_list     args;

    va_start(args, format);
    i = 0;
    while (format[i])
    {
        if (format[i] == '%')
        {
            ft_which_conversion(format[++i], &args);
            i++;
        }
        if (format[i] && format[i] != '%')
            ft_putchar_fd(format[i++], 1);
    }
    va_end(args);
    return (0);
}

//int main()
//{
//    char            c = 'G';
//    char            *str = "HELLO!";
//
//    printf("%lu\n", sizeof(void *));
//    printf("%lu\n", sizeof(char *));
//    printf("%lu\n", sizeof(int *));
//    printf("%lu\n", sizeof(unsigned int *));
//    printf("%lu\n", sizeof(long *));
//    printf("%lu\n", sizeof(unsigned long *));
//    printf("%lu\n", sizeof(long long *));
//    printf("%lu\n", sizeof(unsigned long long *));
//    printf("123%cabc\nn 123%sabc\n 123%pabc\n 123%dabc\n 123%iabc\n 123%uabc\n 123%xabc\n 123%Xabc\n", c, "Hello world!", (void *)str, 42, 0x12, -1, 4510, 4510);
//    printf("\n");
//    ft_printf("123%cabc\nn 123%sabc\n 123%pabc\n 123%dabc\n 123%iabc\n 123%uabc\n 123%xabc\n 123%Xabc\n", c, "Hello world!", (void *)str, 42, 0x12, -1, 4510, 4510);
//    printf("\n");
//    printf("%c %s %p %d %i %u %x %X\n", c, "Hello world!", (void *)str, 42, 0x12, -1, 4510, 4510);
//    ft_printf("%c %s %p %d %i %u %x %X\n", c, "Hello world!", (void *)str, 42, 0x12, -1, 4510, 4510);
//
//    return (0);
//}