/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ookamonu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 06:03:32 by ookamonu          #+#    #+#             */
/*   Updated: 2023/11/11 05:52:37 by ookamonu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Appends the string pointed to by src to the end of the string pointed to
// by dest. dest=Hello src=World return HelloWorld.

char	*ft_strcat(char *dest, const char *src)
{
	int	i;
	int	l;

	i = 0;
	l = 0;
	while (dest[l])
	{
		l++;
	}
	while (src[i])
	{
		dest[l] = src[i];
		l++;
		i++;
	}
	dest[l] = '\0';
	return (dest);
}
