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

void	ft_work_with_d_e(char *path, char *flag)
{
	if	(ft_get_file_type_(path) == 'd')
	{
		dirp = opendir(path);
		if (dirp == NULL)
		{
			ft_putstr("./ft_ls: ");
			perror(path);
		}
	}
}
