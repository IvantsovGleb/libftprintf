//
// Created by Gleb Ivantsov on 29.12.2021.
//

#include "libft.h"

void    ft_lstadd_back(t_list **lst, t_list *new)
{
    t_list      *tmp;

    if (!*lst)
    {
        *lst = new;
        return ;
    }
    tmp = *lst;
    while (tmp->next)
        tmp = tmp->next;
    tmp->next = new;
}

