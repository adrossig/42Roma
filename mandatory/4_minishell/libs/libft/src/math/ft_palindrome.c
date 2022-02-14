/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_palindrome.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arossign <arossign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 17:38:45 by adrossig          #+#    #+#             */
/*   Updated: 2022/02/11 23:38:03 by arossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * Checks if a number is a palindrome.
 *
 * @param number The number to check.
 *
 * @returns None
 */
int	ft_palindrome(int number)
{
	int	reversed_num;
	int	original_num;

	reversed_num = 0;
	original_num = number;
	while (number != 0)
	{
		reversed_num = reversed_num * 10 + number % 10;
		number /= 10;
	}
	if (original_num == reversed_num)
		ft_putstr("is a palindrome.");
	else
		ft_putstr("is not a palindrome.");
	return (OK);
}
