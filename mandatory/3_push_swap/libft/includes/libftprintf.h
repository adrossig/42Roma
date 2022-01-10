/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrossig <adrossig@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 11:22:53 by adrossig          #+#    #+#             */
/*   Updated: 2021/01/14 12:04:25 by adrossig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include "libft.h"
/*
**	Define text colors.
*/

# define BLACK			"\033[0:30m"
# define BOLD_BLACK		"\033[1:30m"
# define RED 			"\033[0;31m"
# define BOLD_RED 		"\033[1;31m"
# define GREEN 			"\033[0;32m"
# define BOLD_GREEN 	"\033[1;32m"
# define YELLOW 		"\033[0;33m"
# define BOLD_YELLOW 	"\033[01;33m"
# define BLUE 			"\033[0;34m"
# define BOLD_BLUE 		"\033[1;34m"
# define MAGENTA 		"\033[0;35m"
# define BOLD_MAGENTA 	"\033[1;35m"
# define CYAN 			"\033[0;36m"
# define BOLD_CYAN 		"\033[1;36m"
# define WHITE			"\033[0:37m"
# define BOLD_WHITE		"\033[1:37m"
# define RESET 			"\033[0m"

/*
**	Define background colors.
*/

# define BG_BLACK			"\033[0:40m"
# define BG_BOLD_BLACK		"\033[1:40m"
# define BG_RED 			"\033[0;41m"
# define BG_BOLD_RED 		"\033[1;41m"
# define BG_GREEN 			"\033[0;42m"
# define BG_BOLD_GREEN 		"\033[1;42m"
# define BG_YELLOW 			"\033[0;43m"
# define BG_BOLD_YELLOW 	"\033[1;43m"
# define BG_BLUE 			"\033[0;44m"
# define BG_BOLD_BLUE 		"\033[1;44m"
# define BG_MAGENTA 		"\033[0;45m"
# define BG_BOLD_MAGENTA 	"\033[1;45m"
# define BG_CYAN 			"\033[0;46m"
# define BG_BOLD_CYAN 		"\033[1;46m"
# define BG_WHITE			"\033[0:47m"
# define BG_BOLD_WHITE		"\033[1:47m"

/*
**	Other "necessities".
*/

# define BOLD 				"\033[1m"
# define UL 				"\033[4m"
# define REV 				"\033[7m"

/*
**STRUCTURE
*/

typedef struct s_format
{
	int		fd;
	int		flag;
	int		width;
	int		precision;
	int		dot;
	char	specifier;
}				t_format;

typedef struct s_position
{
	size_t	index;
	size_t	pos;
}				t_position;

/*
**PROTOTYPE
*/

int				ft_printf(const char	*s, ...);
int				ft_dprintf(int fd, const char *str, ...);
void			ft_arg(const char	*s, t_position *p_pos, va_list ap, int *pf);

/*
**Basic
*/

char			*ft_join(char	*s1, char	*s2);
char			*ft_str_null(char	*s1, char	*s2);
int				ft_get_string(const char *str, size_t	*p_pos);
int				ft_print_arguments(t_format form, va_list ap);

/*
**Format
*/

t_format		ft_f(const char	*s, size_t	*p_pos, t_format form);
t_format		ft_w(const char	*s, size_t	*p_pos, va_list ap, t_format form);
t_format		ft_p(const char	*s, size_t	*p_pos, va_list ap, t_format form);
char			ft_s(const char	*s, size_t	*p_pos);
t_format		ft_get_format(const char	*s, size_t	*p_pos, va_list ap);
int				ft_check_format(t_format form);
char			*ft_calloc_flag(size_t count, int c);

/*
**String
*/

int				ft_print_str(t_format format, va_list ap);
char			*ft_extract_buffer_part(int precision, char	*buffer);
int				ft_format_trans(int	*ptr_precision, int	*p_width, char	*s);
char			*ft_to_add(int flag, int nbr_space);
char			*ft_printed(int flag, char	*new_buffer, char	*to_add);

/*
**Character
*/

int				ft_print_c(t_format form, va_list ap);
int				ft_print_per(t_format form);
char			*ft_add_front_to_char(char c, char	*s);
char			*ft_add_back_to_char(char c, char	*s);
int				ft_put_formatted_char(t_format form, char c);
void			ft_char_cp(char c, int	*p_with_form);

/*
**Number
*/

char			*ft_int_add_precision(char	*nbr, int precision);
char			*ft_int_add_width(t_format form, char *nbr);
int				ft_put_formatted_nbr(t_format form, char	*number);
int				ft_print_signed_dec(t_format form, va_list ap);
int				ft_print_unsigned_dec(t_format form, va_list ap);
int				ft_print_hex(t_format form, va_list ap);
int				ft_print_adr(t_format	form, va_list ap);
char			*ft_zeroes_cp(int cp, int size);
char			*ft_int_cp(int precision, int width, int len, char	*nbr);
int				ft_print_adr_cp(void *adr, t_format format);

#endif
