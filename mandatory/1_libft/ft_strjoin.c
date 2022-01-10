/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrossig <adrossig@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 15:38:49 by adrossig          #+#    #+#             */
/*   Updated: 2021/10/28 11:44:07 by adrossig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*locma;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	if (!s1 && !s2)
		return (NULL);
	locma = (char *)malloc(sizeof(s1) + sizeof(s2) + 1);
	if (!(locma))
		return (NULL);
	while (s1 && s1[i])
	{
		locma[i] = s1[i];
		i++;
	}
	while (s2 && s2[j])
	{
		locma[i + j] = s2[j];
		j++;
	}
	locma[i + j] = '\0';
	return (locma);
}
