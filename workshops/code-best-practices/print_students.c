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
#include <unistd.h>
#include <errno.h>

void	ft_add_to_str(char *a, char *buff, int k, int i)
{
	a[k] = buff[i];
	if (buff[i + 1] == ';' || buff[i + 1] == 0)
		a[k + 1] = '\0';
}

void	ft_stock_line_data_into_corresponding_str(char *fname, char *lname, char *email, char *grade, char *county, char *buff)
{
	int i,j,k;
	i = 0; j = 0; k = 0;
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
				ft_add_to_str(fname, buff, k, i);
			if (j == 1)
				ft_add_to_str(lname, buff, k, i);
			if (j == 2)
				ft_add_to_str(email, buff, k, i);
			if (j == 3)
				ft_add_to_str(grade, buff, k, i);
			if (j == 4)
				ft_add_to_str(county, buff, k, i);
			k++;
		}
		i++;
	}
}

void	ft_print_results(char *fname, char *lname, char *grade, char *county)
{
	if((strcmp(county,"Cluj") == 0 || strcmp(county,"cluj") == 0) && atof(grade) > 8.00)
		printf("%s %s\n", fname, lname);
}

void	ft_validate_line(char *buff)
{
	int i;
	int cnt;

	i = 0;
	cnt = 0;
	while (buff[i])
	{
		if (buff[i] == ';')
			cnt++;
		i++;
	}
	if (cnt < 4)
		printf("Error. Incomplete line: %s\n", buff);
	if (cnt > 4)
		printf("Error. Too many values in one line: %s\n", buff);
}

int	ft_isalpha(int c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	if (c >= 'A' && c <= 'Z')
		return (1);
	return (0);
}

void	ft_validate_fname(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (!ft_isalpha(str[i]))
			printf("Error. First name contains ilegal characters: %s\n", str);
		i++;
	}
}

void	ft_validate_lname(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (!ft_isalpha(str[i]))
			printf("Error. Last name contains ilegal characters: %s\n", str);
		i++;
	}
}
	
void	ft_validate_grade(char *grade)
{
	int i;
	
	i = 0;
	while(grade[i])
	{
		if (!(grade[i] >= '0' && grade[i] <= '9') && grade[i] != '.')
			printf("Error. Invalid characters in grade field: %s\n", grade);
		i++;
	}
}

int	ft_validate_open(FILE *fp)
{
	if (fp == NULL)
	{
		perror("Error opening file");
		return (0);
	}
	else
		return (1);
}

int	main(void)
{
	FILE *fp;
	char buff[255];
	char fname[20],lname[20],email[20],grade[5],county[10];


	fp = fopen("students7.csv", "r");
	if (!ft_validate_open(fp))
		return (0);
	while(fscanf(fp, "%s", buff) > 0)
	{
		ft_validate_line(buff);
		ft_stock_line_data_into_corresponding_str(fname, lname, email, grade, county, buff);
		ft_validate_fname(fname);
		ft_validate_lname(lname);
		ft_validate_grade(grade);
		ft_print_results(fname, lname, grade, county);
	}
	return (0);
}
