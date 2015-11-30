#include "ft_printf.h"

void	ft_process_O_(va_list ap, int *bytes)
{
	unsigned long 	nbr;
	char		*str;
	
	nbr = va_arg(ap, unsigned long);
	str = ft_itoabase(nbr, 8);
	ft_putstr(str);
	*bytes = *bytes + ft_strlen(str);
}
