#include "ft_printf.h"

size_t	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

size_t	ft_putstr(char *s)
{
	size_t	count;

	if (!s)
		count = write(1, "(null)", 6);
	else
		count = write(1, s, ft_strlen(s));
	return (count);
}

char	*ft_address(void *address, char *buffer)
{
	char	*tmp;
	char	*add;

	tmp = ft_utoa((unsigned long)address, buffer, HEX);
	add = ft_strjoin("0x", tmp);
	free(tmp);
	return (add);
}
