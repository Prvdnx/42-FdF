/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ookamonu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 19:54:06 by ookamonu          #+#    #+#             */
/*   Updated: 2023/11/13 02:00:43 by ookamonu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	bresenham_algo(t_fdf *data, t_draw start, t_draw end, t_var *var)
{
	while (start.x != end.x || start.y != end.y)
	{
		mlx_pixel_put(data->mlx, data->win, data->pos_x + start.x,
			data->pos_y + start.y, data->color);
		if (start.x == end.x && start.y == end.y)
			break ;
		var->e2 = 2 * var->err;
		if (var->e2 >= var->dy)
		{
			var->err += var->dy;
			start.x += var->sx;
		}
		if (var->e2 <= var->dx)
		{
			var->err += var->dx;
			start.y += var->sy;
		}
	}
}
