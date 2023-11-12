/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ookamonu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 06:09:36 by ookamonu          #+#    #+#             */
/*   Updated: 2023/11/11 02:46:12 by ookamonu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Outputs the string to the standard output followed by a new line.

void	ft_putendl(char const *str)
{
	if (str)
	{
		ft_putstr(str);
		ft_putchar('\n');
	}
}
