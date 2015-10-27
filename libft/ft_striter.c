/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/27 19:37:50 by vdruta            #+#    #+#             */
/*   Updated: 2015/10/27 20:34:48 by vdruta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**Aplica functia f la fiecare caracter din sirul de caractere trimis
**ca parametru. Adresa fiecarui caracter este trimisa ca
**parametru la functia f pentru a putea sa o modifice in caz de
**nevoie
*/

void	ft_striter(char *s, void (*f)(char *))
{
	unsigned int i;

	i = 0;
	while (s[i])
	{
		f((char *)(s + i));
		i++;
	}
}
