#include "ft_printf.h"
#include <stdio.h>

t_list      *ft_split_format(t_list *head, const char *format)
{
    t_list      *new;
    const char  *offset;
    size_t      len;
    size_t      i;

    offset = format;
    i = 0;
    while (format[i])
    {
        if (format[i] == '%' && ft_strchr("cspdiuxX%", format[i + 1]))
        {
            i++;
            len = i - (offset - format) + 1;
            new = ft_lstnew(ft_substr(format, offset - format, len));
            if (!new)
                return ((void *) 0);
            ft_lstadd_back(&head, new);
            offset += len;
        }
        i++;
    }
    new = ft_lstnew(ft_strdup(offset));
    ft_lstadd_back(&head, new);
    return (head);
}

char    *ft_recognize_conversion(void *content, va_list *args)
{
    char    c;
    char    *offset;
    char    buffer[sizeof(int) * 5 + 1];

    offset = ft_strchr((const char *)content, '%');
    if (!offset)
        return (ft_strdup((char *) content));
    *offset = '\0';
    c = *(offset + 1);
    if (c == 'c')
        return (ft_char((char *)content, va_arg(*args, int)));
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
        return (ft_char((char *)content, '%'));
    return ((void *) 0);
}