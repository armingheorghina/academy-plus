#include "ft_printf.h"

void	ft_process_f_float(va_list ap, int *bytes, char *descriptor, t_arg arg)
{
	double		nbr;
	char 		*str;

	nbr = va_arg(ap, double);
	g_nbr = nbr;
	str = ft_ftoa(nbr, 6);
	if (arg.precision)
		str = ft_ftoa(nbr, arg.precision);
	if (nbr < 0 && !arg.precision && !arg.width)
		str = ft_strjoin("-", str);
	if (arg.precision == 0 && nbr == 0 && ft_strchr(descriptor, '.'))
		str[0] = '\0';
	if(arg.width)
		str = ft_process_d_width(str, arg);
	if (arg.flag_plus && nbr >= 0)
		ft_process_d_put_flag_plus(bytes, &str, arg);
	else if (arg.flag_space && nbr >= 0)
		ft_process_d_put_flag_space(bytes, &str, arg);
	ft_putstr(str);
	*bytes += ft_strlen(str);
}

void	ft_process_f_(va_list ap, int *bytes, char *descriptor, t_arg arg)
{
	ft_process_f_float(ap, bytes, descriptor, arg);
}
