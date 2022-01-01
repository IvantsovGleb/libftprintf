//
// Created by Gleb Ivantsov on 30.12.2021.
//

#include "libft.h"

t_list      *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
    t_list      *new;
    t_list      *head;

    if (!lst || !f || !del)
        return ((void *) 0);
    head = (void *) 0;
    while (lst)
    {
        new = ft_lstnew(f(lst->content));
        if (!new)
        {
            ft_lstclear(&head, del);
            return ((void *) 0);
        }
        ft_lstadd_back(&head, new);
        lst = lst->next;
    }
    return (head);
}