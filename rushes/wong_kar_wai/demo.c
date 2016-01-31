/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   demo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <vdruta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 23:00:13 by vdruta            #+#    #+#             */
/*   Updated: 2016/01/31 23:00:16 by vdruta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "2048.h"

char *g_choices[] = {
	"Star Game",
	"Exit",
};

int g_mchoices = sizeof(g_choices) / sizeof(char *);

WINDOW *creat_win(int h, int w, int y, int x)
{
	WINDOW *geam;
	geam = newwin(h, w, y, x);
	box(geam , 0, 0);
	wrefresh(geam);
	return (geam);
}

void	menu(WINDOW *geam, int lumina)
{
	int x, y, i;

	i = 0;
	x = 2;
	y = 2;
	box(geam, 0, 0);	
	while (i < g_mchoices)
	{
		if (lumina == i + 1)
		{
			wattron(geam, A_REVERSE | A_BLINK | COLOR_PAIR(3));
			mvwprintw(geam, y, x+3, "%s", g_choices[i]);
			wattroff(geam, A_REVERSE | A_BLINK | COLOR_PAIR(3));
		}
		else
			mvwprintw(geam, y, x+3, "%s", g_choices[i]);
		i++;
		y++;
	}
	wrefresh(geam);
}

void	ft_calc(int ch)
{
	int i;

	if (ch == 'a')
		for (i = 0; i <= 3 + size; i++)
			varianta_A(i, 1);
	else if (ch == 'd')
		for (i = 0; i <= size + 3; i++)
			varianta_A(i, -1);
	else if (ch == 's')
		for (i = 0; i <= size + 3; i++)
			varianta_B(i, -1);
	else if (ch == 'w')
		for ( i= 0; i <= size + 3; i++)
			varianta_B(i, 1);
	if (mov == 1)
		ft_put_nbr_in_table();
}

void	scrie()
{
	WINDOW *geam;
	int ch;
	int var;

	var = 0;
	ft_put_nbr_in_table();
	ft_put_nbr_in_table();
	geam = creat_win(30, 50, 5, 20);
	keypad(geam, TRUE);
	wrefresh(geam);
	clear();
	refresh();
	int i = 4, j = 2, x = 0, y = 0;	
	while (x <= 3 + size)
	{
		j = 2;
		y = 0;
		while (y <= 3 + size)
		{
			wattron(geam, COLOR_PAIR(3));
			if (s[x][y] == 0)
				mvwprintw(geam, j ,i , ".   " , s[x][y]);
			else
				mvwprintw(geam, j, i, "%d", s[x][y]);
			wattroff(geam, COLOR_PAIR(3));
			j += 5;
			y++;
		}
		i += 7;
		x++;
	}
	while (1)
	{
		x = 0;
		i = 4;
		mov = 0;
		ch = wgetch(geam);
		if (ch == 'q' || ch == 27)
			return;
		ft_calc(ch);
		while (x <= 3 + size)
		{
			j = 2;
			y = 0;
			while (y <= 3 + size)
			{
				wattron(geam, COLOR_PAIR(3));
				if (s[x][y] == 0)
					mvwprintw(geam, j, i, ".   ", s[x][y]);
				else
					mvwprintw(geam, j, i, "%d   ", s[x][y]);
				wattroff(geam, COLOR_PAIR(3));
				j += 5;
				y++;
			}
			i += 7;
			x++;
		}
		ft_verify_map();
	}
}

int	main(void)
{
	WINDOW *geam;
	int startx, starty, width, height;
	int ch;
	int lumina = 1;
	int choice = 0;

	if ( ft_is_pow_of_two() == 0)
	{
		ft_putnbr(WIN_NUMBER);
		ft_putstr(" is not power of 2!");
		return (0);
	}
	initscr();
	noecho();
	curs_set(FALSE);
	cbreak();
	start_color();
	height = 10;
	init_pair(3, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_GREEN, COLOR_BLACK);
	init_pair(1, COLOR_BLUE, COLOR_BLACK);
	init_pair(4, COLOR_CYAN, COLOR_BLACK);
	width = 20;
	starty = (LINES - width) / 5;
	startx = (COLS -height) / 5;
	geam = newwin(height - 1, width, starty + 5, startx + 5);
	keypad(geam, TRUE);
	attron(COLOR_PAIR(2));
	mvprintw(5, 34, "WONG KAR WAI");
	attroff(COLOR_PAIR(2));
	doupdate();
	refresh();
	menu(geam, lumina);
	while (1)
	{
		ch = wgetch(geam);
		if (ch == KEY_UP)
		{
			if (lumina == 1)
				lumina = g_mchoices;
			else
				--lumina;
		}
		else if (ch == KEY_DOWN)
		{
			if (lumina == g_mchoices)
				lumina = 1;
			else
				++lumina;
		}
		else if (ch == 10)
			choice = lumina;
		if (choice != 0)
			break;
		menu(geam, lumina);
	}
	endwin();
	if (choice == 1)
		scrie();
	clrtoeol();
	refresh();
	endwin();
	return (0);
}
