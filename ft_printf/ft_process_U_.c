#include "ft_printf.h"

void	ft_process_U_(va_list ap, int *bytes)
{
	unsigned long 	nbr;
	char		*str;
	
	nbr = va_arg(ap, unsigned long);
	str = ft_itoabase(nbr, 10);
	ft_putstr(str);
	*bytes = *bytes + ft_strlen(str);
}
