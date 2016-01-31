/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2048.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <vdruta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 23:00:00 by vdruta            #+#    #+#             */
/*   Updated: 2016/01/31 23:00:04 by vdruta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "2048.h"

void	ft_make_score()
{
	int i;
	int j;

	g_score = 0;
	i = 0;
	while ( i <= 3 + size)
	{
		j = 0;
		while ( j <= 3 + size)
		{
			g_score = g_score + s[i][j];
			j++;
		}
		i++;
	}
}

int		ft_is_pow_of_two()
{
	int nbr;

	nbr = 2;
	while (nbr <= WIN_NUMBER)
		nbr = nbr * 2;
	if (nbr == WIN_NUMBER * 2)
		return (1);
	return (0);
}

int		ft_verify_map()
{
	int i;
	int j;
	int ok;

	ok = 1;
	i = 0;
	while(i <= 3 + size)
	{
		j = 0;
		while(j <= 3 + size)
		{
			if(s[i][j] == 0)
				ok = 0;
			j++;
		}
		i++;
	}
	if (ok == 1)
	{
	system("clear");
	ft_putstr("YOU LOST");
	ft_putstr("\n");
	ft_make_score();
	ft_putstr("Your score: ");
	ft_putnbr(g_score);
	}
	i = 0;
	while ( i <= 3 + size)
	{
		j = 0;
		while ( j <= 3 + size)
		{
			if ( s[i][j] == WIN_NUMBER )
			{
				system("clear");
				ft_putstr("YOU WON!!!");
				ft_putstr("\n");
				ft_make_score();
				ft_putstr("Your score: ");
			   	ft_putnbr(g_score);	
			}
			j++;
		}
		i++;
	}
	return (0); 
}

int		ft_give_me_a_random_nbr(int max_value)
{
	return (rand() % max_value);
}

int		rraand(void)
{
	int nr;

	srand(time(NULL));
	nr = ft_give_me_a_random_nbr(5);
	if (nr == 0)
		return (1);
	if (nr == 1)
		return (1);
	if (nr == 2)
		return (1);
	if (nr == 3)
		return (1);
	if (nr == 4)
		return (2);
	return (0);
}

void	ft_put_nbr_in_table()
{
	int i;
	int j;
	int ok;

	ok = 0;
	srand(time(NULL));
	while(ok == 0)
	{		i = ft_give_me_a_random_nbr(4 + size);
		j = ft_give_me_a_random_nbr(4 + size);
		if (s[i][j] == 0)
		{
			s[i][j] = rraand() * 2;
			ok++;
		}
	}
}
int 	ft_zero_collum(int i, int j, int direction)
{
	int finish;

	finish = 3 + size;
	if (direction == -1)
		finish = 0;
	while (i * direction <= finish)
	{
		if(s[i][j] != 0)
			return (1);
		i = i + direction;
	}
	return (0);
}

void		ft_tragi_inapoi(int i, int j, int direction)
{
	int finish;
	int back;

	back = 0;
	finish = 3 + size;
	if (direction == -1)
		finish = 0;
	while (i * direction < finish && ft_zero_collum(i, j, direction))
	{
		back = i + direction;
		while (back * direction <= finish)
		{
			if(s[i][j] == 0 && s[back][j] != 0)
			{
				s[i][j] = s[back][j];
				s[back][j] = 0;
				mov = 1;
			}
			back = back + direction;
		}
		i = i + direction;
	}
}

void		varianta_A(int j, int direction)
{
	int i;
	int finish;

	finish = 3 + size;
	i = 0;
	if (direction == -1)
	{
		i = 3 + size;
		finish = 0;
	}
	ft_tragi_inapoi(i, j, direction);
	while (i * direction <= finish)
	{
		if(s[i][j] == s[i + direction][j] && s[i][j] != 0)
		{
			s[i][j] *= 2;
			s[i + direction][j] = 0;
			ft_tragi_inapoi(i, j, direction);
		}
		i = i + direction;
	}
}

int		ft_zero_row(int i, int j, int direction)
{
	int	finish;

	finish = 3 + size;
	if (direction == -1)
		finish = 0;
	while(j * direction <= finish)
	{
		if (s[i][j] != 0)
			return (1);
		j = j + direction;
	}
	return (0);
}

void	ft_tragi(int i, int j, int direction)
{
	int finish;
	int back;

	back = 0;
	finish = 3 + size;
	if (direction == -1)
		finish = 0;
	while (j * direction < finish && ft_zero_row(i, j, direction))
	{
		back = j + direction;
		while(back * direction <= finish)
		{	
			if (s[i][j] == 0 && s[i][back] != 0)
			{
				s[i][j] = s[i][back];
				s[i][back] = 0;
				mov = 1;
			}

			back = back + direction;
		}
		j = j + direction;
	}
}

void	varianta_B(int i, int direction)
{
	int j;
	int finish;

	finish = 3 + size;
	j = 0;	
	if (direction == -1)
	{
		j = 3 + size;
		finish = 0;
	}
	ft_tragi(i, j, direction);
	while ( j * direction <= finish)
	{
		if(s[i][j] == s[i][j + direction] && s[i][j] != 0)
		{
			s[i][j] *= 2;
			s[i][j + direction] = 0;
			ft_tragi(i, j, direction);
		}
		j = j + direction; 
	}	

}
