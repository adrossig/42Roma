/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrossig <adrossig@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 10:43:59 by adrossig          #+#    #+#             */
/*   Updated: 2021/02/06 00:02:35 by adrossig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STR_H
# define FT_STR_H

# include "libft.h"

int				ft_strequ(const char *s1, const char *s2);
int				ft_strcmp(const char *str1, const char *str2);
int				ft_strnequ(const char *s1, const char *s2, size_t n);
int				ft_strncmp(const char *str1, const char *str2, size_t i);
void			ft_strclr(char *s);
void			ft_strdel(char **as);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strrev(char *str);
char			*ft_strnew(size_t size);
char			**ft_strfree(char **str);
char			*ft_strdup(const char *str);
char			**ft_split(const char *s, char c);
char			*ft_strchr(const char *str, int c);
char			*ft_toupper_str(char *str, int len);
char			*ft_tolower_str(char *str, int len);
char			*ft_strrchr(const char *str, int c);
char			*ft_strndup(const char *s, size_t n);
char			*ft_strnjoin(char *s1, char *s2, int n);
char			*ft_strcat(char *dest, const char *src);
char			*ft_strcpy(char *dest, const char *src);
char			*ft_strmap(const char *s, char(*f)(char));
char			*ft_strjoin(const char *s1, const char *s2);
char			*ft_strtrim(const char *s1, const char *set);
char			*ft_strstr(const char *str, const char *to_find);
char			*ft_strncpy(char *dest, const char *src, size_t i);
char			*ft_strncat(char *dest, const char *src, size_t n);
char			*ft_substr(const char *s, unsigned int start, size_t len);
char			*ft_strmapi(const char *s, char (*f)(unsigned int, char));
char			*ft_strnstr(const char *haystack, const char *needle, size_t n);
int				ft_strlen(const char *str);
size_t			ft_strnlen(const char *s, char c);
size_t			ft_strlcpy(char *dest, const char *src, size_t size);
size_t			ft_strlcat(char *dest, const char *src, size_t size);

#endif
