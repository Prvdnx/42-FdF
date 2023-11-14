/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_isometric.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ookamonu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 03:20:26 by ookamonu          #+#    #+#             */
/*   Updated: 2023/11/15 05:20:28 by ookamonu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*-------------------------------------------------------------------------*\
The isometric function applies an isometric projection to transform 3D
coordinates into 2D screen coordinates. The function takes the original x, y,
and z coordinates, performs calculations involving trigonometric functions
(cosine and sine), and updates the coordinates accordingly. The projection
function then applies this isometric projection to the start and end points
of a line.
\*--------------------------------------------------------------------------*/
void	isometric(int *x, int *y, int z)
{
	int	previous_x;
	int	previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = (previous_x - previous_y) * cos(0.523599);
	*y = -z + (previous_x + previous_y) * sin(0.523599);
}

void	projection(t_draw *info)
{
	isometric(&info->x, &info->y, info->z);
	isometric(&info->x2, &info->y2, info->z2);
}
