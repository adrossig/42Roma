/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fromdec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrossig <adrossig@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 14:19:25 by adrossig          #+#    #+#             */
/*   Updated: 2021/10/28 13:16:58 by adrossig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static char	value(int number)
{
	if (number >= 0 && number <= 9)
		return ((char)(number + '0'));
	else
		return ((char)(number - 10 + 'A'));
}

static void	strev(char *str)
{
	int		lenght;
	int		i;
	char	temp;

	lenght = strlen(str);
	i = 0;
	while (i < lenght / 2)
	{
		temp = *(str + i);
		*(str + i) = *(str + lenght + i - 1);
		*(str + lenght - i - 1) = temp;
		i++;
	}
}

char	*ft_fromdec(int number, int base, char *result)
{
	int	index;

	index = 0;
	while (number > 0)
	{
		*(result + index++) = value(number % base);
		number /= base;
	}
	*(result + index) = '\0';
	strev(result);
	return (result);
}
