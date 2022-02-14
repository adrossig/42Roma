/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_subsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arossign <arossign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 15:24:41 by arossign          #+#    #+#             */
/*   Updated: 2022/02/11 22:53:49 by arossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	ft_count_words(char *str, char *set, int count)
{
	int		mtx[2];
	int		i;

	i = 0;
	mtx[0] = 0;
	mtx[1] = 0;
	while (str && str[i] != '\0')
	{
		count++;
		if (!ft_strchr(set, str[i]))
		{
			while ((!ft_strchr(set, str[i]) || mtx[0] || mtx[1]) && str[i] != '\0')
			{
				mtx[0] = (mtx[0] + (!mtx[1] && str[i] == '\'')) % 2;
				mtx[1] = (mtx[1] + (!mtx[0] && str[i] == '\"')) % 2;
				i++;
			}
			if (mtx[0] || mtx[1])
				return (-1);
		}
		else
			i++;
	}
	return (count);
}

/**
 * Splits a string into an array of strings based on a set of delimiters.
 *
 * @param str The string to split.
 * @param set The set of delimiters.
 *
 * @returns An array of strings.
 */
static char	**ft_fill_array(char **aux, char *str, char *set, int i[3])
{
	int		mtx[2];

	mtx[0] = 0;
	mtx[1] = 0;
	while (str && str[i[0]] != '\0')
	{
		i[1] = i[0];
		if (!ft_strchr(set, str[i[0]]))
		{
			while ((!ft_strchr(set, str[i[0]]) || mtx[0] || mtx[1]) && str[i[0]])
			{
				mtx[0] = (mtx[0] + (!mtx[1] && str[i[0]] == '\'')) % 2;
				mtx[1] = (mtx[1] + (!mtx[0] && str[i[0]] == '\"')) % 2;
				i[0]++;
			}
		}
		else
			i[0]++;
		aux[i[2]++] = ft_substr(str, i[1], i[0] - i[1]);
	}
	return (aux);
}

/* Copy of ft_split but includes separators and takes quotes into account */
/**
 * Splits a string into an array of strings based on a delimiter.
 *
 * @param s The string to split.
 * @param set The delimiter to split the string by.
 *
 * @returns An array of strings split by the delimiter.
 */
char	**ft_cmdsubsplit(char const *s, char *set)
{
	char	**aux;
	int		number_words;
	int		mtx[3];

	mtx[0] = 0;
	mtx[1] = 0;
	mtx[2] = 0;
	if (!s)
		return (NULL);
	number_words = ft_count_words((char *)s, set, 0);
	if (number_words == -1)
		return (NULL);
	aux = malloc((number_words + 1) * sizeof(char *));
	if (aux == NULL)
		return (NULL);
	aux = ft_fill_array(aux, (char *)s, set, mtx);
	aux[number_words] = NULL;
	return (aux);
}
