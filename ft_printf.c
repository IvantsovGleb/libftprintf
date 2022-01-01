#include "printf.h"
#include <stdio.h>

void    ft_print(t_list *lst)
{
    while (lst)
    {
        printf("%s", (char *)lst->content);
        lst = lst->next;
    }
}

int     ft_printf(const char *format, ...)
{
    char        *tmp;
    t_list      *lst;
    t_list      *head;
    va_list     args;

    va_start(args, format);
    head = (void *) 0;
    head = ft_split_format(head, format);
    ft_print(head);
    printf("\n");
    lst = head;
    while (lst->next)
    {
        tmp = ft_strjoin(lst->content, ft_recognize_conversion(lst->content, &args));
        free(lst->content);
        lst->content = tmp;
//        tmp = (void *) 0;
        lst = lst->next;
    }
    ft_print(head);
    va_end(args);
    ft_lstclear(&head, free);
    return (0); // count the number of characters that have been read
}

int     main()
{
    ft_printf("HELL%c %s%s%s %%%%", 'O', "Hello", "Gleb", "Moscow");

//    ft_print(ft_split_format(head, " %c "));
//    ft_print(ft_split_format(head, " %c"));
//    ft_print(ft_split_format(head, "%c "));
//    ft_print(ft_split_format(head, " %c %c %c "));

    return (0);
}