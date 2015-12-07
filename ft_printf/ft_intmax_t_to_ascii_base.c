
#include "ft_printf.h"

char	*ft_intmax_t_to_ascii_base(intmax_t val, int base)
{
	static char	buf[32] = "0";
	int		i;
	uintmax_t		val2;;

	i = 30;
	if (val == 0)
		return (ft_strdup("0"));
	if (val < 0)
	{
		val2 = -val;
		while (val2 > 0 && i > 0)
		{
			buf[i] = "0123456789abcdef"[val2 % base];
			val2 = val2 / base;
			--i;
		}
		buf[i] = '-';
		return (buf + i + 1);
	}
	while (val > 0 && i > 0)
	{
		buf[i] = "0123456789abcdef"[val % base];
		val = val / base;
		--i;
	}
	return (buf + i + 1);
}
