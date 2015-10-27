/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/27 20:05:31 by vdruta            #+#    #+#             */
/*   Updated: 2015/10/27 20:33:40 by vdruta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**Aplica functia f la fiecare caracter din sirul de caractere trimis
**ca parametru. Adresa fiecarui caracter este trimisa ca
**al doilea parametru, precizand indexul ca prim parametru la
**functia f pentru a putea sa o modifice in caz de nevoie.
*/

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int i;

	i = 0;
	while (*(char *)(s + i))
	{
		f(i, (char *)(s + i));
		i++;
	}
}
