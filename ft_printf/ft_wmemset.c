
#include "ft_printf.h"
#include <string.h>

wchar_t		*ft_wmemset(wchar_t *b, wchar_t c, size_t len)
{
	size_t i;

	i = 0;
	while (i < len)
	{
		b[i] = c;
		i++;
	}
	return (b);
}
