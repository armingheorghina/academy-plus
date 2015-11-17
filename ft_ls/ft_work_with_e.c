/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_work_with_e.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/17 19:31:48 by vdruta            #+#    #+#             */
/*   Updated: 2015/11/17 19:43:14 by vdruta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_work_with_e(int i, char **argv)
{
	DIR	*dirp;

	if (ft_get_file_type(i, argv) == 'e')
	{
		dirp = opendir(argv[i]);
		if (dirp == NULL)
		{
			ft_putstr(argv[0]);
			ft_putstr(": ");
			perror(argv[i]);
		}
	}
}
