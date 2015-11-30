
#include "ft_printf.h"

void	ft_process_C_(va_list ap, int *bytes)
{
	wchar_t wc;

	wc = va_arg(ap, wchar_t);
	ft_putwchar(wc);
	*bytes += ft_wcharsize(wc);
}
