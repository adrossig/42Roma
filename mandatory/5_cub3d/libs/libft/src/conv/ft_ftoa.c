/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrossig <adrossig@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 11:00:16 by adrossig          #+#    #+#             */
/*   Updated: 2021/02/04 13:37:30 by adrossig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/*
** Convertit un nombre à virgule flottante donné ou un double,
** en une chaîne de caractères.
** =======
** #1: Numéro d'entrée.
** #2: Tableau où la chaîne de sortie doit être stockée.
** #3: Nombre de chiffres à prendre en compte après le point.
** =======
** Retourne la chaine de caractères représentant le float.
*/

char				*ft_ftoa(long double f, int precision, int dot)
{
	unsigned long long	dec;
	char				*ipart;
	char				*fpart;
	char				*joint;
	int					i;

	f = f + ft_rounding(precision, f);
	f *= (f < 0) ? -1 : 1;
	dec = f;
	ipart = ft_itoa_uimax(dec);
	f = precision ? (f - dec) : 0;
	fpart = ft_strnew(precision + 2);
	fpart[0] = (dot == 1 && precision > 0) ? '.' : '\0';
	i = 1;
	while (precision-- > 0)
	{
		f *= 10;
		dec = f;
		f -= dec;
		fpart[i++] = dec + '0';
	}
	joint = ft_strjoin(ipart, fpart);
	free(fpart);
	free(ipart);
	return (joint);
}
