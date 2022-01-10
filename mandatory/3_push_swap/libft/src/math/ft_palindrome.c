/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_palindrome.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrossig <adrossig@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 17:38:45 by adrossig          #+#    #+#             */
/*   Updated: 2021/05/26 16:46:51 by adrossig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

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
		ft_printf("%d is a palindrome.", original_num);
	else
		ft_printf("%d is not a palindrome.", original_num);
	return (OK);
}
