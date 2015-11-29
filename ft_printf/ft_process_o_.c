#include "ft_printf.h"

void	ft_process_o_(va_list ap, int *bytes)
{
	unsigned int 	nbr;
	char		*str;
	
	nbr = va_arg(ap, unsigned int);
	str = ft_itoabase(nbr, 8);
	ft_putstr(str);
	*bytes = *bytes + ft_strlen(str);
}
