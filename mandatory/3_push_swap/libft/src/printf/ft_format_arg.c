/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_arg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrossig <adrossig@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 09:55:20 by adrossig          #+#    #+#             */
/*   Updated: 2020/10/09 10:18:38 by adrossig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
** Parse str jusqu'à trouver une conversion à faire.
** Pour chacune, imprime la partie précédente de str n'en nécéssitant pas,
** puis récupère le format de la conversion à faire.
** Si les indications de formatage sont valides, la fonction effectue
** la conversion et l'imprime. Puis elle recommence jusquà la fin de str.
** =========
** #1 : la chaîne de caractères, premier argument de ft_printf().
** #2 : un pointeur sur la position actuelle dans str.
** #3 : un pointeur sur l'élément actuel de la liste d'arguments.
** #4 : un pointeur sur le retour de ft_printf().
** =========
*/

void	ft_arg(const char *str, t_position *ptr_pos, va_list ap, int *ret_pf)
{
	t_position	bis;
	t_format	ret_format;

	bis = *ptr_pos;
	while (str[bis.index] != '\0')
	{
		if (str[bis.index] == '%')
		{
			*ret_pf += ft_get_string(str, &bis.pos);
			ret_format = ft_get_format(str, &bis.pos, ap);
			if (ft_check_format(ret_format) != -1)
			{
				*ret_pf += ft_print_arguments(ret_format, ap);
				bis.index = bis.pos - 1;
			}
			else
				return ;
		}
		bis.index++;
	}
	*ptr_pos = bis;
	return ;
}
