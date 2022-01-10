/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrossig <adrossig@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 15:57:43 by adrossig          #+#    #+#             */
/*   Updated: 2021/11/03 17:55:35 by adrossig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdint.h>

# include "../libs/libft/includes/libft.h"

typedef struct s_flags
{
	int		star;
	int		width;
	int		zero;
	int		minus;
	int		type;
	int		dot;
}	t_flags;

t_flags	ft_initialize(void);
t_flags	ft_minus_flag(t_flags flags);
t_flags	ft_digit_flag(char c, t_flags flags);
t_flags	ft_width_flag(va_list args, t_flags flags);
int		ft_isflag(int c);
int		ft_isconversion(int c);
int		ft_percent(t_flags flags);
int		ft_int(int i, t_flags flags);
int		ft_char(char c, t_flags flags);
int		ft_putsp(char *str, int precision);
int		ft_string(char *str, t_flags flags);
int		ft_width(int width, int minus, int zero);
int		ft_uint(unsigned int number, t_flags flags);
int		ft_handling(int c, t_flags flags, va_list args);
int		ft_handling_input(const char *str, va_list args);
int		ft_pointer(unsigned long long num, t_flags flags);
int		ft_hexa(unsigned int number, int lowercase, t_flags flags);
int		ft_parse(const char *str, int i, t_flags *flags, va_list args);
int		ft_dot_flag(const char *str, int start, t_flags *flags, va_list args);

#endif
