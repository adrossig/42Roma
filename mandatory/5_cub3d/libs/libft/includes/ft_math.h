/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrossig <adrossig@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 10:57:43 by adrossig          #+#    #+#             */
/*   Updated: 2021/02/04 14:17:01 by adrossig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MATH_H
# define FT_MATH_H

# include "libft.h"

int				ft_palindrome(int number);
long long		ft_abs(long long n);
void			ft_armstrong(int num);
int				ft_lcm(int nbr1, int nbr2);
int				ft_is_prime(int nbr);
int				ft_fibonacci(int index);
int				ft_gcd(int nbr1, int nbr2);
int				ft_power(int nbr, int power);
int				ft_surface(int width, int height);
int				ft_perimeter(int width, int height);
double			ft_sqrt(double nbr);
int				ft_int_length_uimax(intmax_t n);
void			ft_swap(int *a, int *b);
long double		ft_rounding(int precision, long double f);

#endif
