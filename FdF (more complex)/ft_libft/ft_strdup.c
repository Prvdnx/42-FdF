/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ookamonu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 06:10:35 by ookamonu          #+#    #+#             */
/*   Updated: 2023/04/18 01:00:11 by ookamonu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*str;
	int		buf_size;

	buf_size = ft_strlen(src) + 1;
	str = malloc(buf_size);
	if (NULL == str)
		return (NULL);
	ft_strlcpy(str, src, buf_size);
	return (str);
}
