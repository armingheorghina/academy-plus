#include "ft_printf.h"

void	ft_process_o_flag_hash(int *bytes, char *str)
{
		ft_putchar('0');
		ft_putstr(str);
		*bytes = *bytes + ft_strlen(str) + 1;
}

void	ft_process_o_lm_j(va_list ap, int *bytes, t_arg arg)
{
	uintmax_t	nbr;
	char 		*str;

	nbr = va_arg(ap, uintmax_t);
	str = ft_uintmax_t_to_ascii_base(nbr, 8);
	if (arg.flag_hash && nbr != 0)
		ft_process_o_flag_hash(bytes, str);
	else
	{
		ft_putstr(str);
		*bytes = *bytes + ft_strlen(str);
	}
}

void	ft_process_o_lm_z(va_list ap, int *bytes, t_arg arg)
{
	size_t	nbr;
	char 	*str;

	nbr = va_arg(ap, size_t);
	str = ft_size_t_to_ascii_base(nbr, 8);
	if (arg.flag_hash && nbr != 0)
		ft_process_o_flag_hash(bytes, str);
	else
	{
		ft_putstr(str);
		*bytes = *bytes + ft_strlen(str);
	}
}

void	ft_process_o_lm_h(va_list ap, int *bytes, t_arg arg)
{
	unsigned short	nbr;
	char 			*str;

	nbr = va_arg(ap, unsigned int);
	str = ft_unsigned_short_to_ascii_base(nbr, 8);
	if (arg.flag_hash && nbr != 0)
		ft_process_o_flag_hash(bytes, str);
	else
	{
		ft_putstr(str);
		*bytes = *bytes + ft_strlen(str);
	}
}

void	ft_process_o_(va_list ap, int *bytes, char *descriptor, t_arg arg)
{
	unsigned int	nbr;
	char			*str;

	if (arg.lm_l)
		ft_process_oo_(ap, bytes, descriptor);
	else if (arg.lm_hh)
		ft_process_c_(ap, bytes, descriptor, arg);
	else if (arg.lm_h)
		ft_process_o_lm_h(ap, bytes, arg);
	else if (arg.lm_j)
		ft_process_o_lm_j(ap, bytes, arg);
	else if (arg.lm_z)
		ft_process_o_lm_z(ap, bytes, arg);
	else
	{
		nbr = va_arg(ap, unsigned int);
		str = ft_itoabase(nbr, 8);
		if (arg.flag_hash && nbr != 0)
			ft_process_o_flag_hash(bytes, str);
		else
		{
			ft_putstr(str);
			*bytes = *bytes + ft_strlen(str);
		}
	}
}
