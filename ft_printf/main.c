#include <stdio.h>
#include "ft_printf.h"
/*
void foo(char *fmt, ...)
{
	va_list ap;
	int d;
	char c;
	char *s;

	va_start(ap, fmt);
	while (*fmt)
		switch (*fmt++) 
		{
			case 's':             
				s = va_arg(ap, char *);
				printf("string %s\n", s);
				break;
			case 'd':              
				d = va_arg(ap, int);
				printf("int %d\n", d);
				break;
			case 'c':              
				
				c = (char) va_arg(ap, int);
				printf("char %c\n", c);
				break;
		}
	va_end(ap);
}
*/
int	main()
{

	//ft_printf("%%- %s - %%", "abcd");
	ft_printf("%s", "abcd");
	ft_printf("\n");
	printf("%%- %s - %%", "abcd");
	//ft_printf("% - %% - %s -", "abcd");
	//printf("%s - %% - %s", "abcd", "efgh");
	return (0);

}
