
#include "ft_printf.h"

void	ft_process_S_(va_list ap, int *bytes)
{
	wchar_t *wstr;
	int i;

	i = 0;
	wstr = va_arg(ap, wchar_t *);
	while (wstr[i])
	{
		ft_putwchar(wstr[i]);
		*bytes += ft_wcharsize(wstr[i]);
		i++;
	}
}
