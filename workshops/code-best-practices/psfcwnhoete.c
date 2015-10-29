/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psfcwnhoete.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/26 18:05:43 by vdruta            #+#    #+#             */
/*   Updated: 2015/10/29 15:54:05 by vdruta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void	ft_add_to_str(char *a, char *buff, int k, int i)
{
	a[k] = buff[i];
	if (buff[i + 1] == ';' || buff[i + 1] == 0)
		a[k + 1] = '\0';
}

int	main(void)
{
	FILE *fp;
	char buff[255];
	char a[20],b[20],c[20],d[5],e[10];
	int i=0,j=0,k=0;

	fp = fopen("students.csv", "r");
	while(fscanf(fp, "%s", buff) > 0)
	{
		j=0;k=0;i=0;
		while(buff[i] != 0)
		{
			if(buff[i] == ';')
			{
				j++;
				k = 0;
			}
			else
			{
				if (j == 0)
					ft_add_to_str(a, buff, k, i);
				if (j == 1)
					ft_add_to_str(b, buff, k, i);
				if (j == 2)
					ft_add_to_str(c, buff, k, i);
				if (j == 3)
					ft_add_to_str(d, buff, k, i);
				if (j == 4)
					ft_add_to_str(e, buff, k, i);
				k++;
			}
			i++;
		}
		if(strcmp(e,"Cluj") == 0 && atof(d) > 8.00)
			printf("%s %s\n",a,b);
	}
	return (0);
}
