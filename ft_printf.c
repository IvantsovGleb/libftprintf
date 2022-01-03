#include "ft_printf.h"

#include <stdio.h>

int  ft_printf(const char *format, ...)
{
    char        *s;
    int         i;
    va_list     args;

    va_start(args, format);
    i = 0;
    while (*format)
    {
        if (*format == '%' && ft_strchr("cspdiuxX%", *(format + 1)))
        {
            s = ft_recognize_conversion((int)(*++format), &args);
            ft_putstr_fd(s, 1);
            i += ft_strlen(s);
            free(s);
            format++;
        }
        else
        {
            ft_putchar_fd(*format++, 1);
            i++;
        }
    }
    va_end(args);
    return (i);
}

int     main()
{
//
//    printf("TEST 1\n");
//    printf("len %d\n", ft_printf("%c\n", '0'));
//    printf("len %d\n", printf("%c\n", '0'));
//
//    printf("TEST 2\n");
//    ft_printf(" %c \n", '0');
//    printf(" %c \n", '0');
//
//    printf("TEST 3\n");
//    ft_printf(" %c\n", '0' - 256);
//    printf(" %c\n", '0' - 256);
//
//    printf("TEST 4\n");
//    ft_printf("%c \n", '0' + 256);
//    printf("%c \n", '0' + 256);
//
//    printf("TEST 5\n");
//    ft_printf(" %c %c %c \n", '0', 0, '1');
//    printf(" %c %c %c \n", '0', 0, '1');
//
//    printf("TEST 6\n");
//    ft_printf(" %c %c %c \n", ' ', ' ', ' ');
//    printf(" %c %c %c \n", ' ', ' ', ' ');
//
//    printf("TEST 7\n");
//    ft_printf(" %c %c %c \n", '1', '2', '3');
//    printf(" %c %c %c \n", '1', '2', '3');
//    printf("\n");
//
//    printf("TEST 8\n");
//    ft_printf(" %c %c %c \n", '2', '1', 0);
//    printf(" %c %c %c \n", '2', '1', 0);
//
//    printf("TEST 9\n");
//    ft_printf(" %c %c %c \n", 0, '1', '2');
//    printf(" %c %c %c \n", 0, '1', '2');
//
//    char *s2 = "Mussum Ipsum, cacilds vidis litro abertis. Posuere libero varius. Nullam a nisl ut ante blandit hendrerit. Aenean sit amet nisi. Atirei o pau no gatis, per gatis num morreus.";
//
//    printf("TEST 1\n");
//    ft_printf("%s\n", "");
//    printf("%s\n", "");
//
//    printf("TEST 2\n");
//    ft_printf(" %s\n", "");
//    printf(" %s\n", "");
//
//    printf("TEST 3\n");
//    ft_printf("%s \n", "");
//    printf("%s \n", "");
//
//    printf("TEST 4\n");
//    ft_printf(" %s \n", "");
//    printf(" %s \n", "");
//
//    printf("TEST 5\n");
//    ft_printf(" %s \n", "-");
//    printf(" %s \n", "-");
//
//    printf("TEST 6\n");
//    ft_printf(" %s %s \n", "", "-");
//    printf(" %s %s \n", "", "-");
//
//    printf("TEST 7\n");
//    ft_printf(" %s %s \n", " - ", "");
//    printf(" %s %s \n", " - ", "");
//
//    printf("TEST 8\n");
//    ft_printf(" %s %s %s %s %s\n", " - ", "", "4", "", s2);
//    printf(" %s %s %s %s %s\n", " - ", "", "4", "", s2);
//
//    printf("TEST 9\n");
//    ft_printf(" %s %s %s %s %s \n", " - ", "", "4", "", "2 ");
//    printf(" %s %s %s %s %s \n", " - ", "", "4", "", "2 ");
//
    printf("TEST 10\n");
    ft_printf(" NULL %s NULL \n", NULL);
    printf(" NULL %s NULL \n", (char *)((void *)0));
//
//
//    unsigned long   address = -1;
//
//    ft_printf(" %p \n", -1);
//    printf(" %p \n", (void *)address);
//
//    ft_printf(" %p \n", 1);
//    printf(" %p \n", (void *)address);
//
//    ft_printf(" %p \n", 15);
//    printf(" %p \n", (void *)address);
//
//    ft_printf(" %p \n", 16);
//    printf(" %p \n", (void *)address);
//
//    ft_printf(" %p \n", 17);
//    printf(" %p \n", (void *)address);
//
//    ft_printf(" %p %p \n", LONG_MIN, LONG_MAX);
//    printf(" %p %p \n", LONG_MIN, LONG_MAX);
//
//    ft_printf(" %p %p \n", INT_MIN, INT_MAX);
//    printf(" %p %p \n", INT_MIN, INT_MAX);
//
//    ft_printf(" %p %p \n", ULONG_MAX, -ULONG_MAX);
//    printf(" %p %p \n", ULONG_MAX, -ULONG_MAX);
//
//    ft_printf(" %p %p \n", 0, 0);
//    printf(" %p %p \n", (void *)0, (void *)0);
//
    return (0);
}