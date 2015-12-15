/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialize_flags_and_lm.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 19:55:47 by vdruta            #+#    #+#             */
/*   Updated: 2015/12/15 19:56:39 by vdruta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_initialize_flags_and_lm(t_arg *arg)
{
	arg->precision = 0;
	arg->width = 0;
	arg->flag_hash = 0;
	arg->flag_zero = 0;
	arg->flag_minus = 0;
	arg->flag_plus = 0;
	arg->flag_space = 0;
	arg->lm_j = 0;
	arg->lm_z = 0;
	arg->lm_h = 0;
	arg->lm_hh = 0;
	arg->lm_l = 0;
	arg->lm_ll = 0;
}
