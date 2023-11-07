/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ookamonu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 06:09:18 by ookamonu          #+#    #+#             */
/*   Updated: 2023/04/18 00:59:17 by ookamonu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	typedef unsigned char byte;
	if ((NULL == src && NULL == dst) || len < 0)
		return (dst);
	if (dst > src)
		while (len--)
			*((byte *)dst + len) = *((byte *)src + len);
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
