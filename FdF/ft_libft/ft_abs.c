/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ookamonu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 06:02:56 by ookamonu          #+#    #+#             */
/*   Updated: 2023/11/12 20:20:50 by ookamonu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*`ft_abs` calculates the absolute value of an integer. The absolute
value of a number is its value without regard to its sign.In the function,
if the input `n` is greater than or equal to 0, the function returns `n`
as it is. If `n` is less than 0, the function returns the negation of `n`
to obtain its positive equivalent. 
This function ensures that the returned value is always a non-negative integer,
effectively discarding any negative sign that might be present in the input.*/

int	ft_abs(int n)
{
	int	nb;

	if (n >= 0)
	{
		nb = n;
	}
	else
	{
		nb = -n;
	}
	return (nb);
}
