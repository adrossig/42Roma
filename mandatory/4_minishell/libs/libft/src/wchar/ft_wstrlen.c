/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arossign <arossign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 11:01:28 by arossign          #+#    #+#             */
/*   Updated: 2022/01/11 11:01:29 by arossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

size_t	ft_wstrlenz(wint_t *wstr)
{
	if (!wstr || *wstr == L'\0')
		return (0);
	return (ft_wchar_len(*wstr) + ft_wstrlenz(wstr + 1));
}
