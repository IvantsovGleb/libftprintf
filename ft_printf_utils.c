#include "printf.h"
#include <stdio.h>

t_list      *ft_split_format(t_list *head, const char *format)
{
    t_list      *new;
    const char  *offset;
    size_t      len;
    size_t      i;

    offset = format;
    i = -1;
    while (format[++i])
    {
        if (format[i] == '%' && ft_strchr("cspdiuxX%", format[i + 1]))
        {
            i++;
            len = i - (offset - format) + 1;
            new = ft_lstnew((char *)ft_substr(format, offset - format, len));
            ft_lstadd_back(&head, new);
            offset += len;
        }
    }
    new = ft_lstnew(ft_strdup(offset));
    ft_lstadd_back(&head, new);
    return (head);
}

char    *ft_recognize_conversion(void *content, va_list *args)
{
    char    c;
    char    *offset;

    offset = ft_strchr((const char *)content, '%');
    if (offset)
    {
        *offset = '\0';
        c = *(offset + 1);
        if (c == 'c')
            return (ft_char(va_arg(*args, int)));
        if (c == 's')
            return (va_arg(*args, char *));
//        if (c == 'p')
//            return (ft_address(va_arg(*args, void *)));
        if (c == 'd' || c == 'i')
        {
            // ToDo()
        }
        if (c == 'u' || c == 'x' || c == 'X')
        {
            // ToDo()
        }
        if (c == '%')
            return (ft_char('%'));
    }
    return (content);
}