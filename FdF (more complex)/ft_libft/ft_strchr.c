/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ookamonu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 06:10:32 by ookamonu          #+#    #+#             */
/*   Updated: 2023/04/18 00:50:15 by ookamonu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s != (char)c && *s)
		++s;
	if (*s)
		return ((char *)s);
	else if (!*s && 0 == (char)c)
		return ((char *)s);
	else
		return (NULL);
}
