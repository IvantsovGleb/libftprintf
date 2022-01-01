//
// Created by Gleb Ivantsov on 29.12.2021.
//

#include "libft.h"

t_list      *ft_lstnew(void *content)
{
    t_list  *node;

    node = malloc(sizeof(t_list));
    if (!node)
        return ((void *) 0);
    node->content = content;
    node->next = (void *)0;
    return (node);
}