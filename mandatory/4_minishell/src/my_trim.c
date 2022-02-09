/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_trim.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arossign <arossign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 15:17:37 by arossign          #+#    #+#             */
/*   Updated: 2022/02/08 15:23:53 by arossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	ft_count_words(const char *s, char *set, int mtx[2])
{
	int		temp[2];

	temp[0] = 0;
	temp[1] = 0;
	while (s[mtx[0]] != '\0')
	{
		if (!ft_strchr(set, s[mtx[0]]))
		{
			mtx[1]++;
			while ((!ft_strchr(set, s[mtx[0]]) || temp[0]) && s[mtx[0]] != '\0')
			{
				if (!temp[1] && (s[mtx[0]] == '\"' || s[mtx[0]] == '\''))
					temp[1] = s[mtx[0]];
				temp[0] = (temp[0] + (s[mtx[0]] == temp[1])) % 2;
				temp[1] *= temp[0] != 0;
				mtx[0]++;
			}
			if (temp[0])
				return (-1);
		}
		else
			mtx[0]++;
	}
	return (mtx[1]);
}

static char	**ft_fill_array(char **aux, char const *s, char *set, int mtx[3])
{
	int	s_len;
	int	temp[2];

	temp[0] = 0;
	temp[1] = 0;
	s_len = ft_strlen(s);
	while (s[mtx[0]])
	{
		while (ft_strchr(set, s[mtx[0]]) && s[mtx[0]] != '\0')
			mtx[0]++;
		mtx[1] = mtx[0];
		while ((!ft_strchr(set, s[mtx[0]]) || temp[0] || temp[1]) && s[mtx[0]])
		{
			temp[0] = (temp[0] + (!temp[1] && s[mtx[0]] == '\'')) % 2;
			temp[1] = (temp[1] + (!temp[0] && s[mtx[0]] == '\"')) % 2;
			mtx[0]++;
		}
		if (mtx[1] >= s_len)
			aux[mtx[2]++] = "\0";
		else
			aux[mtx[2]++] = ft_substr(s, mtx[1], mtx[0] - mtx[1]);
	}
	return (aux);
}

/* Splits command and args into a matrix, taking quotes into account */
char	**my_trim(char const *str, char *set)
{
	char	**aux;
	int		number_words;
	int		mtx[3];
	int		counts[2];

	mtx[0] = 0;
	mtx[1] = 0;
	mtx[2] = 0;
	counts[0] = 0;
	counts[1] = 0;
	if (!str)
		return (NULL);
	number_words = ft_count_words(str, set, counts);
	if (number_words == -1)
		return (NULL);
	aux = malloc((number_words + 1) * sizeof(char *));
	if (aux == NULL)
		return (NULL);
	aux = ft_fill_array(aux, str, set, i);
	aux[number_words] = NULL;
	return (aux);
}
