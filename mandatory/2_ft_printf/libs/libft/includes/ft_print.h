/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arossign <arossign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 11:04:32 by adrossig          #+#    #+#             */
/*   Updated: 2022/02/16 10:55:53 by arossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINT_H
# define FT_PRINT_H

# include "libft.h"

void	ft_putnbr(int nb);
int		ft_putchar(char c);
void	ft_putendl(const char *s);
int		ft_putstr(const char *str);
void	ft_putnstr(const char *str, int n);
void	ft_putnbr_fd(int n, int fd);
int		ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(const char *s, int fd);
void	ft_putendl_fd(const char *s, int fd);
void	ft_putuint_base_fd(uintmax_t n, int base, int ch, int fd);
void	ft_putnstr_fd(const char *str, int n, int fd);

#endif
