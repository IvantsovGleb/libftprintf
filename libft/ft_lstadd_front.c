//
// Created by Gleb Ivantsov on 29.12.2021.
//

#include "libft.h"

void    ft_lstadd_front(t_list **lst, t_list *new)
{
    new->next = *lst;
    *lst = new;
}