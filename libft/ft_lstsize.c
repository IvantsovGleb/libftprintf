#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	l_size;

	l_size = 0;
	while (lst)
	{
		l_size++;
		lst = lst->next;
	}
	return (l_size);
}
