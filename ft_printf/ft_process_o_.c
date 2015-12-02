#include "ft_printf.h"

void	ft_process_o_(va_list ap, int *bytes, char *descriptor)
{
	unsigned int 	nbr;
	char		*str;
	
	nbr = va_arg(ap, unsigned int);
	str = ft_itoabase(nbr, 8);
	if (ft_strchr(descriptor, '#') && nbr != 0)
	{
		ft_putchar('0');
		ft_putstr(str);
		*bytes = *bytes + ft_strlen(str) + 1;
	}
	else
	{
		ft_putstr(str);
		*bytes = *bytes + ft_strlen(str);
	}
}
