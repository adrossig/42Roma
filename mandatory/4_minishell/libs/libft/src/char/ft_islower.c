/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_islower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arossign <arossign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 15:24:20 by adrossig          #+#    #+#             */
/*   Updated: 2022/02/11 23:16:58 by arossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * Checks if a character is lowercase.
 *
 * @param c The character to check.
 * @returns 1 if the character is lowercase, 0 otherwise.
 */
int	ft_islower(int c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	return (OK);
}
