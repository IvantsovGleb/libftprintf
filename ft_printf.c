#include "ft_printf.h"

#include <stdio.h>

static char     *ft_recognize_conversion(int  c, va_list *args)
{
    char    buffer[sizeof(int) * 5 + 1];

    if (c == 'c')
        ft_putchar_fd(va_arg(*args, int), 1);
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
        ft_putchar_fd('%', 1);

    return ((void *) 0);
}

static size_t      ft_putstr(char *s)
{
    size_t      count;

    count = 0;
    if (!s)
        count++;
    else
    {
        ft_putstr_fd(s, 1);
        count = ft_strlen(s);
        free(s);
    }
    return (count);
}

int  ft_printf(const char *format, ...)
{
    char        *s;
    size_t      count;
    va_list     args;

    va_start(args, format);
    count = 0;
    while (*format)
    {
        if (*format == '%')
        {
            s = ft_recognize_conversion((int)(*++format), &args);
            count += ft_putstr(s);
            format++;
        }
        else
        {
            ft_putchar_fd(*format++, 1);
            count++;
        }
    }
    va_end(args);
    return (count);
}

int     main()
{

//******************************************************************
    printf("category: s TEST 10\n");
    ft_printf(" NULL %s NULL \n", NULL);
    printf(" NULL %s NULL \n", (char *)((void *)0));
//******************************************************************

    return (0);
}