/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atouni.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrossig <adrossig@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 16:27:15 by adrossig          #+#    #+#             */
/*   Updated: 2021/11/03 16:27:16 by adrossig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static int	get_atouni_width(wchar_t wc)
{
	if (wc < 0x80)
		return (1);
	else if (wc < 0x800)
		return (2);
	else if (wc < 0x10000)
		return (3);
	else
		return (4);
}

char	*ft_atouni(wchar_t w)
{
	int		n;
	int		i;
	char	*utf;
	int		utf_frame;

	n = get_atouni_width(w);
	utf = malloc(n + 1);
	if (utf == NULL)
		return (NULL);
	utf[n] = '\0';
	if (n == 1)
		utf[0] = w;
	else
		return (0);
	if (n == 1)
		return (utf);
	i = 0;
	utf_frame = 0b10000000;
	while (i + 1 <= n)
	{
		utf[n - 1 - i] = ((w >> (6 * i)) & 0b00111111) | utf_frame;
		i++;
	}
	while (n-- > 1)
	{
		utf_frame = utf_frame >> 1 | 0b10000000;
		utf[0] = utf[0] | utf_frame;
	}
	return (utf);
}
