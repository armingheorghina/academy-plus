/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/20 20:08:38 by vdruta            #+#    #+#             */
/*   Updated: 2015/10/20 22:56:58 by vdruta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int		main(void)
{
	char str[] = "   -2147483648";
	

	printf("%zu\n", ft_strlen(str));		//test ft_strlen
	printf("%lu\n", strlen(str));			//test strlen
	printf("%d\n", ft_atoi(str));			//test ft_atoi
	printf("%d\n", atoi(str));				//test atoi
	printf("%d\n", ft_isalpha('y'));		//test ft_isalpha
	printf("%d\n", isalpha('y'));			//test isalpha
	printf("%d\n", ft_isdigit('5'));		//test ft_isdigit
	printf("%d\n", isdigit('5'));			//test isdigit
	printf("%d\n", ft_isalnum(' '));		//test ft_isalnum
	printf("%d\n", isalnum(' '));			//test isalnum
	printf("%d\n", ft_isascii(' '));		//test ft_isascii
	printf("%d\n", isascii(' '));			//test isascii
	printf("%d\n", ft_isprint(' '));		//test ft_isprint
	printf("%d\n", isprint(' '));			//test isprint




	return (0);
}
