/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_add_precision.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrossig <adrossig@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 09:30:12 by adrossig          #+#    #+#             */
/*   Updated: 2021/01/14 14:13:17 by adrossig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
** Alloue (avec malloc(3)) et retourne une chaine de
** caractères représentant un nombre après son formatage de précision.
** =======
** #1 : la chaîne de caractère représentant le nombre à formater.
** #2 : le champ précision du format.
** =======
** Retourne la chaine de caractères nbr
** une fois le formatage de précision effectué.
*/

char	*ft_int_add_precision(char *nbr, int precision)
{
	int		i;
	int		j;
	int		k;
	int		len;
	char	*precised_int;

	i = 0;
	j = 0;
	len = (int)ft_strlen(nbr);
	precised_int = (char *)malloc(sizeof(char) * (precision + 2));
	if (precised_int == NULL)
		return (NULL);
	if (nbr[i] == '-')
	{
		precised_int[j++] = nbr[i++];
		len -= 1;
	}
	k = 0;
	while (k++ < (precision - len))
		precised_int[j++] = '0';
	while (nbr[i] != '\0')
		precised_int[j++] = nbr[i++];
	precised_int[j] = '\0';
	return (precised_int);
}
