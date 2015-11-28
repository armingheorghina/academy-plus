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
	int bytes;
	char *str;
	
	str = "abc";
	//printf("%%- %s - %%", "abcd");
	//bytes = ft_printf("%-s --%d-- %s -%< - %% -%", "abcd", 455, "efgh");
	//bytes = ft_printf("%-s %s", "abcd", "efgh");
	//printf("%d", bytes);
	//bytes = ft_printf("%-s --%d-- %s -% - %% -%", "abcd", 455, "efgh");
	//printf("\n%d\n", bytes);
	bytes = printf("%p", &str);
	printf("\n%d\n", bytes);
	//ft_printf("%-s --%d-- %s -%< - %% -%", "abcd", 455, "efgh");
	//ft_printf("%%", "abcd", 455, "efgh");
	//ft_printf("\n");
	//ft_printf("% - %% - %s -", "abcd");
	//printf("%s - %% - %s", "abcd", "efgh");
	return (0);

}
