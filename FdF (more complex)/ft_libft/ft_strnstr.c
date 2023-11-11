/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ookamonu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 06:11:44 by ookamonu          #+#    #+#             */
/*   Updated: 2023/04/18 00:45:20 by ookamonu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include <string.h>
#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	j;
	size_t	k;

	j = 0;
	if (!*needle || (NULL == haystack && !len))
		return ((char *)haystack);
	while (*(haystack + j) && j < len)
	{
		k = 0;
		while (*(haystack + j + k) == *(needle + k) && (k + j) < len)
		{
			if (0 == *(needle + k + 1))
				return ((char *)haystack + j);
			++k;
		}
		++j;
	}
	return (NULL);
}
