/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/20 20:08:38 by vdruta            #+#    #+#             */
/*   Updated: 2015/10/21 20:54:48 by vdruta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int		main(void)
{
	char str1[] = "    -2147483648";
	char str2[] = "   -";

	printf("%zu\n", ft_strlen(str1));			//test ft_strlen
	printf("%lu\n", strlen(str1));				//test strlen
	printf("%d\n", ft_atoi(str1));				//test ft_atoi
	printf("%d\n", atoi(str1));					//test atoi
	printf("%d\n", ft_isalpha('y'));			//test ft_isalpha
	printf("%d\n", isalpha('y'));				//test isalpha
	printf("%d\n", ft_isdigit('5'));			//test ft_isdigit
	printf("%d\n", isdigit('5'));				//test isdigit
	printf("%d\n", ft_isalnum(' '));			//test ft_isalnum
	printf("%d\n", isalnum(' '));				//test isalnum
	printf("%d\n", ft_isascii(' '));			//test ft_isascii
	printf("%d\n", isascii(' '));				//test isascii
	printf("%d\n", ft_isprint(' '));			//test ft_isprint
	printf("%d\n", isprint(' '));				//test isprint
	printf("%c\n", ft_toupper('a'));			//test ft_toupper
	printf("%c\n", toupper('a'));				//test toupper
	printf("%c\n", ft_tolower('A'));			//test ft_tolower
	printf("%c\n", tolower('A'));				//test tolower
	printf("%d\n", ft_strcmp(str1, str2));		//test ft_strcmp
	printf("%d\n", strcmp(str1, str2));			//test strcmp
	printf("%d\n", ft_strncmp(str1, str2, 5));	//test ft_strncmp
	printf("%d\n", strncmp(str1, str2, 5));		//test strncmp
	printf("%s\n", ft_strstr(str1, str2));		//test ft_strstr
	printf("%s\n", strstr(str1, str2));			//test strstr
	printf("%s\n", ft_strnstr(str1, str2, 9));	//test ft_strnstr
	printf("%s\n", strnstr(str1, str2, 9));		//test strnstr
	printf("%s\n", ft_strchr(str1, '\0'));		//test ft_strchr
	printf("%s\n", strchr(str1, '\0'));			//test strchr
	printf("%s\n", ft_strrchr(str1, '4'));		//test ft_strrchr
	printf("%s\n", strrchr(str1, '4'));			//test strrchr
	printf("%s\n", ft_strdup(""));				//test ft_strdup
	printf("%s\n", strdup(""));					//test strdup
	printf("%s\n", ft_strcpy(str1, str2));		//test ft_strcpy
	printf("%s\n", strcpy(str1, str2));			//test strcpy
	printf("%s\n", ft_strncpy(str1, str2, 3));	//test ft_strncpy
	printf("%s\n", strncpy(str1, str2, 3));		//test strncpy







	return (0);
}
