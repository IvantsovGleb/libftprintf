//
// Created by Gleb Ivantsov on 30.12.2021.
//

#include "libft.h"

void    ft_lstclear(t_list **lst, void (*del)(void*))
{
    t_list      *clear;

    if (!lst || !*lst || !del)
        return ;
    clear = *lst;
    while (*lst)
    {
        *lst = (*lst)->next;
        del(clear->content);
        free(clear);
        clear = *lst;
    }
}
