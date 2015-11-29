#include "ft_printf.h"

void	ft_process_c_(va_list ap, int *bytes)
{
	unsigned char c;
	
	c = va_arg(ap, int);
	ft_putchar(c);
	*bytes = *bytes + 1;
}
