/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ookamonu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 06:11:51 by ookamonu          #+#    #+#             */
/*   Updated: 2023/04/18 01:00:16 by ookamonu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*trimmed;

	if (NULL == s1 || NULL == set)
		return (NULL);
	if (!*s1)
		return (ft_strdup(s1));
	start = 0;
	end = ft_strlen(s1) - 1;
	while (*(s1 + start) && ft_strchr(set, *(s1 + start)))
		++start;
	while (end >= 0 && ft_strchr(set, *(s1 + end)))
		--end;
	if (start > end)
		return (ft_strdup(""));
	trimmed = malloc((end - start) + 2);
	if (NULL == trimmed)
		return (NULL);
	ft_strlcpy(trimmed, s1 + start, (end - start) + 2);
	return (trimmed);
}
