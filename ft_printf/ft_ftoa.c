#include "ft_printf.h"

char	*ft_ftoa(float val, int precision)
{
	char 	*str;
	int	i;
	int 	int_part;
	int 	decimal_part;

	int_part = (int)val;
	i = 0;
	val = val - int_part;
	while (i < precision)
	{
		val = val * 10;
		i++;
	}
	decimal_part = (int)val;
	if (decimal_part < 0)
		decimal_part = -1 * decimal_part;
	str = ft_itoa(int_part);
	str = ft_strjoin(str, ".");
	str = ft_strjoin(str, ft_itoa(decimal_part));
	return (str);
}
