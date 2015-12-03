#include "ft_printf.h"

void	ft_process_o_(va_list ap, int *bytes, char *descriptor)
{
	unsigned int	nbr;
	uintmax_t		nbr2;
	char			*str;
	char			*findhh;
	
	if (ft_strchr(descriptor, 'l'))
		ft_process_oo_(ap, bytes, descriptor);
	else if ((findhh = ft_strchr(descriptor, 'h')) && findhh[1] == 'h')
		ft_process_c_(ap, bytes, descriptor);
	else if (ft_strchr(descriptor, 'j') || ft_strchr(descriptor, 'z'))
	{	
		nbr2 = va_arg(ap, uintmax_t);
		str = ft_itoabase(nbr2, 8);
	}
	else
	{
		nbr = va_arg(ap, unsigned int);
		str = ft_itoabase(nbr, 8);
	}
/*print side of the function*/	
	if (ft_strchr(descriptor, '#') && nbr != 0 && !ft_strchr(descriptor, 'l') && !((findhh = ft_strchr(descriptor, 'h')) && findhh[1] == 'h'))
	{
		ft_putchar('0');
		ft_putstr(str);
		*bytes = *bytes + ft_strlen(str) + 1;
	}
	else if (!ft_strchr(descriptor, 'l') && !((findhh = ft_strchr(descriptor, 'h')) && findhh[1] == 'h'))
	{
		ft_putstr(str);
		*bytes = *bytes + ft_strlen(str);
	}
}
