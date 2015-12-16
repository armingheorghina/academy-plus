/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verify_length_modifiers.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 10:08:39 by vdruta            #+#    #+#             */
/*   Updated: 2015/12/16 10:09:24 by vdruta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_verify_length_modifiers(t_arg *arg, char *descriptor)
{
	int i;

	i = 0;
	while (descriptor[i])
	{
		if (descriptor[i] == 'h' && descriptor[i + 1] == 'h')
		{
			arg->lm_hh = 1;
			i++;
		}
		else if (descriptor[i] == 'h')
			arg->lm_h = 1;
		else if (descriptor[i] == 'l' && descriptor[i + 1] == 'l')
		{
			arg->lm_ll = 1;
			i++;
		}
		else if (descriptor[i] == 'l')
			arg->lm_l = 1;
		else if (descriptor[i] == 'j')
			arg->lm_j = 1;
		else if (descriptor[i] == 'z')
			arg->lm_z = 1;
		i++;
	}
}
