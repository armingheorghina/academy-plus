#include "ft_printf.h"

char	*ft_itoaBase(unsigned long long val, int base)
{
	static char	buf[32] = "0";
	int		i;

	i = 30;
	if (val == 0)
		return (buf);
	while (val > 0 && i > 0)
	{
		buf[i] = "0123456789ABCDEF"[val % base];
		val = val / base;
		--i;
	}
	return (buf + i + 1);
}
