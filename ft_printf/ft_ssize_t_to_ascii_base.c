
#include "ft_printf.h"

char	*ft_ssize_t_to_ascii_base(ssize_t val, int base)
{
	static char	buf[32] = "0";
	int		i;
	int		ok;

	i = 30;
	ok = 0;
	if (val == 0)
		return (buf);
	if (val < 0)
	{
		val = -val;
		ok = 1;
	}
	while (val > 0 && i > 0)
	{
		buf[i] = "0123456789abcdef"[val % base];
		val = val / base;
		--i;
	}
	if (ok == 1)
	{
		buf[i] = '-';
		return (buf + i);
	}
	return (buf + i + 1);
}
