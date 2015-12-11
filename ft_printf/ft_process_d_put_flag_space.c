#include "ft_printf.h"

void	ft_process_d_put_flag_space(int *bytes, char **str, t_arg arg)
{
	if (arg.width > ft_strlen(ft_itoabase(g_nbr, 10)) && g_nbr >= 0 && !arg.precision && !arg.flag_space)
		*str[0] = ' ';
	else if (arg.width > ft_strlen(ft_itoabase(g_nbr, 10)) && g_nbr >= 0 && !arg.precision && arg.flag_space)
		*str[0] = ' ';
	else if (!arg.flag_space)
	{
		ft_putchar(' ');
		*bytes += 1;
	}
	else
	{
		ft_putchar(' ');
		*bytes += 1;
	}
}
