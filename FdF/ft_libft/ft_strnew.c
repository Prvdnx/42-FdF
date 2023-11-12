/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ookamonu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 06:08:39 by ookamonu          #+#    #+#             */
/*   Updated: 2023/11/12 20:19:50 by ookamonu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Allocates (with malloc) and returns a fresh string ending with '\0'.
Each character of the string is initialized at '\0'. If the allocation
fails the function returns NULL. */

char	*ft_strnew(size_t size)
{
	char	*str;
	size_t	i;

	i = 0;
	str = (char *)malloc(sizeof(char) * size + 1);
	if (!str)
	{
		return (NULL);
	}
	while (i <= size)
	{
		str[i] = '\0';
		i++;
	}
	return (str);
}
