#include "ft_printf.h"

static size_t      ft_countconversion(const char *format)
{
    char    delim;
    size_t  count;
    size_t  i;

    delim = '%';
    count = 0;
    i = 0;
    while (format[i])
    {
        if (format[i + 1] && format[i] == delim && ft_strchr("cspdiuxX%", format[i + 1]))
            count++;
//        i = ft_strchr(format, delim) - format;
        i++;
    }
    return (count);
}

int     ft_printf(const char *format, ...)
{
    size_t      count;
//    char        **types;
    va_list     args;

    count = ft_countconversion(format);
    printf("count == %lu", count);
    va_start(args, format);

    va_end(args);
    return (0);
}
