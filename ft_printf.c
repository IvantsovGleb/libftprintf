#include "ft_printf.h"
#include <stdio.h>

void    ft_print(t_list *lst)
{
    while (lst)
    {
        printf("%s\n", (char *)lst->content);
        lst = lst->next;
    }
}

static char    *ft_foo(t_list *lst)
{
    char    *tmp;
    char    *s;

    s = (void *) 0;
    tmp = "";
    while (lst)
    {
        tmp = ft_strjoin(tmp, (char *)lst->content);
        if (!tmp)
            break ;
        if (!s)
            free(s);
        s = tmp;
        lst = lst->next;
    }
    return (s);
}

int     ft_printf(const char *format, ...)
{
    char        *tmp;
    t_list      *lst;
    t_list      *head;
    va_list     args;
    size_t      len;

    va_start(args, format);
    head = (void *) 0;
    head = ft_split_format(head, format);
//    ft_print(head);
//    printf("\n");
    lst = head;
    while (lst)
    {
        tmp = ft_recognize_conversion(lst->content, &args);
        free(lst->content);
        lst->content = tmp;
        tmp = (void *) 0;
        lst = lst->next;
    }
    va_end(args);
//    printf("\n");
//    ft_print(head);
    tmp = ft_foo(head);
    len = ft_strlen(tmp);
    ft_putstr_fd(tmp, 1);
    free(tmp);
    ft_lstclear(&head, free);
    return (len);
}

//int     main()
//{
//    int     value = 123;

//    ft_printf("%cHELLO", '0');
//    printf("\n");
//    ft_printf(" %c ", '0');
//    printf("\n");
//    ft_printf(" %c", '0' - 256);
//    printf("\n");
//    ft_printf("%c ", '0' + 256);
//    printf("\n");
//    ft_printf(" %c %c %c ", '0', 0, '1');
//    printf("\n");
//    ft_printf(" %c %c %c ", ' ', ' ', ' ');
//    printf("\n");
//    ft_printf(" %c %c %c ", '1', '2', '3');
//    printf("\n");
//    ft_printf(" %c %c %c ", '2', '1', 0);
//    printf("\n");
//    ft_printf(" %c %c %c ", 0, '1', '2');
//
//    printf("%d\n", printf("HELL%c %s%s%s %%%% %p %d\n", 'O', "Hello", "Gleb", "Moscow", &value, 455));
//    printf("%d\n", ft_printf("HELL%c %s%s%s %%%% %p %d", 'O', "Hello", "Gleb", "Moscow", &value, 455));
//    return (0);
//}