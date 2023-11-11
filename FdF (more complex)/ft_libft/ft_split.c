/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ookamonu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 06:10:28 by ookamonu          #+#    #+#             */
/*   Updated: 2023/04/18 00:54:33 by ookamonu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_strings(const char *s, char delimiter)
{
	size_t	strings;

	strings = 0;
	while (*s)
	{
		while (*s == delimiter && *s)
			++s;
		if (*s != delimiter && *s)
		{
			++strings;
			while (*s != delimiter && *s)
				++s;
		}
	}
	return (strings);
}

static void	fill_matrix(char **matrix, const char *s, char delimiter)
{
	size_t	i;
	size_t	j;
	size_t	len;

	i = 0;
	j = 0;
	while (*(s + i))
	{
		len = 0;
		while (*(s + i) == delimiter)
			++i;
		while (*(s + i) != delimiter && *(s + i))
		{
			++len;
			++i;
		}
		if (len)
			matrix[j] = malloc(len + 1);
		if (NULL == matrix[j])
			matrix[j] = NULL;
		ft_strlcpy(matrix[j++], (s + i) - len, len + 1);
	}
}

char	**ft_split(char const *s, char c)
{
	int		strings;
	char	**matrix;

	if (NULL == s)
		return (NULL);
	strings = count_strings(s, c);
	matrix = malloc((strings + 1) * sizeof(char *));
	if (NULL == matrix)
		return (NULL);
	matrix[strings] = NULL;
	fill_matrix(matrix, s, c);
	return (matrix);
}
