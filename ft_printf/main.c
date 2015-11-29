#include <stdio.h>
#include "ft_printf.h"
int	main()
{
	int bytes;
//	int x;

//	x = 1;	
	//printf("%%- %s - %%", "abcd");
	//bytes = ft_printf("%-s --%d-- %s -%< - %% -%", "abcd", 455, "efgh");
	//bytes = ft_printf("%-s %s", "abcd", "efgh");
	//printf("%d", bytes);
	//bytes = ft_printf("%-s --%d-- %s -% - %% -%", "abcd", 455, "efgh");
	//printf("\n%d\n", bytes);
	bytes = ft_printf("%X", 25544);
	printf("\n%d\n", bytes);
	//ft_printf("%-s --%d-- %s -%< - %% -%", "abcd", 455, "efgh");
	//ft_printf("%%", "abcd", 455, "efgh");
	//ft_printf("\n");
	//ft_printf("% - %% - %s -", "abcd");
	//printf("%s - %% - %s", "abcd", "efgh");
	return (0);

}
