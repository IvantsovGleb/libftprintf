//
// Created by Gleb Ivantsov on 29.12.2021.
//

#include "libft.h"

t_list      *ft_lstlast(t_list *lst)
{
    t_list      *tmp;

    tmp = lst;
    while (tmp)
    {
        if (!tmp->next)
            break ;
        tmp = tmp->next;
    }
    return (tmp);
}