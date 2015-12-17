#include "ft_printf.h"
#include <stdio.h>

int	main()
{
	int bytes;

	bytes = ft_printf("%-15d", 7);
	printf("\n%d\n", bytes);
	printf("--------\n");
	bytes = printf("%-15d", 7);
	printf("\n%d\n", bytes);
	return (0);
}
