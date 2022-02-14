/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isblank.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arossign <arossign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 15:23:05 by adrossig          #+#    #+#             */
/*   Updated: 2022/02/11 23:14:31 by arossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * Checks if a character is a blank character.
 *
 * @param c The character to check.
 * @returns 1 if the character is a blank character, 0 otherwise.
 */
int	ft_isblank(int c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (OK);
}
