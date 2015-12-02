#include "ft_printf.h"

void	ft_process_x_(va_list ap, int *bytes, char *descriptor)
{
	unsigned int 	nbr;
	char		*str;
	
	nbr = va_arg(ap, unsigned int);
	str = ft_itoabase(nbr, 16);
	if (ft_strchr(descriptor, '#') && nbr != 0)
	{
		ft_putstr("0x");
		ft_putstr(str);
		*bytes = *bytes + ft_strlen(str) + 2;
	}
	else
	{
		ft_putstr(str);
		*bytes = *bytes + ft_strlen(str);
	}
}
