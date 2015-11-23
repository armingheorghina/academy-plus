/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_work_with_d_e.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 18:55:14 by vdruta            #+#    #+#             */
/*   Updated: 2015/11/23 18:58:59 by vdruta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_work_with_d_e(char *path, char *flag)
{
	DIR *dirp;
	int i;
	
	i = 0;
	while (flag[i++])	//just to use the flag. for the moment :)
	if (ft_get_file_type_2(path) == 'd')
	{
		dirp = opendir(path);
		if (dirp == NULL)
		{
			ft_putstr("./ft_ls: ");
			perror(path);
		}
	}
}
