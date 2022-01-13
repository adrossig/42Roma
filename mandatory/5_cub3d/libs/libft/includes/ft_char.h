/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrossig <adrossig@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 11:06:43 by adrossig          #+#    #+#             */
/*   Updated: 2020/09/15 11:08:21 by adrossig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CHAR_H
# define FT_CHAR_H

# include "libft.h"

int				ft_isascii(int i);
int				ft_iscntrl(int i);
int				ft_isdigit(int i);
int				ft_isprint(int i);
int				ft_isblank(int i);
int				ft_isalpha(int i);
int				ft_isgraph(int i);
int				ft_islower(int i);
int				ft_ispunct(int i);
int				ft_isspace(int i);
int				ft_isupper(int i);
int				ft_tolower(int i);
int				ft_toupper(int i);
int				ft_isalnum(int i);
int				ft_charset(char str, char *charset);

#endif
