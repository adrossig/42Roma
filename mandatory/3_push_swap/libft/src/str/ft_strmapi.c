/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrossig <adrossig@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 15:40:06 by adrossig          #+#    #+#             */
/*   Updated: 2021/05/26 16:46:26 by adrossig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/*
** Applique la fonction f à chaque caractère de la
** chaine de caractères passée en argument pour créer
** une nouvelle chaine de caractères (avec malloc(3))
** résultant des applications successives de f.
** =========
** #1 : la chaine de caractères sur laquelle itérer
** #2 : la fonction à appliquer à chaque caractère
** =========
** Retourne La chaine de caractères résultant des applications
** successives de f, NULL si l’allocationéchoue
*/

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*mapped;

	if (!s || !f)
		return (NULL);
	mapped = ft_strnew(ft_strlen((char *)s));
	if (mapped == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		mapped[i] = (*f)(i, s[i]);
		i++;
	}
	return (mapped);
}
