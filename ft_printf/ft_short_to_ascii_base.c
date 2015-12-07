
#include "ft_printf.h"

char	*ft_short_to_ascii_base(short val, int base)
{
	static char	buf[32] = "0";
	int		i;
	int		ok;
	int		val2;

	val2 = val;
	i = 30;
	ok = 0;
	if (val2 == 0)
		return (ft_strdup("0"));
	if (val2 < 0)
	{
		val2 = -val2;
		ok = 1;
	}
	while (val2 > 0 && i > 0)
	{
		buf[i] = "0123456789abcdef"[val2 % base];
		val2 = val2 / base;
		--i;
	}
	if (ok == 1)
	{
		buf[i] = '-';
		return (buf + i + 1);
	}
	return (buf + i + 1);
}
