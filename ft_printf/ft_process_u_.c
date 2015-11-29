#include "ft_printf.h"

void	ft_process_u_(va_list ap, int *bytes)
{
	unsigned int 	nbr;
	char		*str;
	
	nbr = va_arg(ap, unsigned int);
	str = ft_itoabase(nbr, 10);
	ft_putstr(str);
	*bytes = *bytes + ft_strlen(str);
}
