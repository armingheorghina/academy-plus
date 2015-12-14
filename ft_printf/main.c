#include <stdio.h>
#include "ft_printf.h"
#include <wchar.h>
#include <string.h>
#include <inttypes.h>
#include <limits.h>

int	main()
{
//	int bytes;
//	long a = 9223372036854775807;
	
	int bytes;
	long long a = -7;
//	t_arg arg;
//	wchar_t wc;
	
//	wc = L'本';

	//TODO +15.3d , 12
/*
	bytes = ft_printf("%f", 1444565444646.6465424242242);
	printf("\n%d\n", bytes);
	printf("--------\n");
	bytes = printf("%f", 1444565444646.6465424242242);
	printf("\n%d\n", bytes);
	*/
	
	bytes = ft_printf("%d", -12345);
	printf("\n%d\n", bytes);
	printf("--------\n");
	bytes = printf("%d", -12345);//444565444646.6465424242242);
	printf("\n%d\n", bytes);
	
//	int x;

//	x = 1;	
	//printf("%%- %s - %%", "abcd");
	//bytes = ft_printf("%-s --%d-- %s -%< - %% -%", "abcd", 455, "efgh");
	//bytes = ft_printf("%-s %s", "abcd", "efgh");
	//printf("%d", bytes);
	//bytes = ft_printf("%-s --%d-- %s -% - %% -%", "abcd", 455, "efgh");
	//printf("\n%d\n", bytes);
//	bytes = ft_printf("%D", a);
//	printf("\n%d\n", bytes);
//	printf("%D", a);
//	printf("\n%d\n", bytes);
	//ft_printf("%-s --%d-- %s -%< - %% -%", "abcd", 455, "efgh");
	//ft_printf("%%", "abcd", 455, "efgh");
	//ft_printf("\n");
	//ft_printf("% - %% - %s -", "abcd");
	//printf("%s - %% - %s", "abcd", "efgh");
	return (0);

}
