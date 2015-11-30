#include "ft_printf.h"

void	ft_process_D_(va_list ap, int *bytes)
{
	long 		nbr;
	unsigned long	ulnbr;
	char 		*str;

	nbr = va_arg(ap, long);
	if (nbr < 0)
	{
		ulnbr = -1 * nbr;
		str = ft_itoabase(ulnbr, 10);
		ft_putstr(ft_strjoin("-", str));
		*bytes += ft_strlen(str) + 1;
	}
	else
	{
		str = ft_itoabase(nbr, 10);
		ft_putstr(str);
		*bytes += ft_strlen(str);
	}

}
