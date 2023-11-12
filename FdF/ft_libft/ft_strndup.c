/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ookamonu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 06:08:39 by ookamonu          #+#    #+#             */
/*   Updated: 2023/11/12 20:23:26 by ookamonu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Duplicates the string at most size bytes that given size in the function.
// and returns a pointer to null-terminated byte string.

char	*ft_strndup(const char *str, size_t len)
{
	size_t		i;
	char		*result;

	i = 0;
	result = ft_strnew(len);
	if (!result)
	{
		return (NULL);
	}
	while (i < len)
	{
		result[i] = str[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}
