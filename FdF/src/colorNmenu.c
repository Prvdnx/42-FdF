/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colorNmenu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ookamonu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 01:20:56 by ookamonu          #+#    #+#             */
/*   Updated: 2023/11/13 02:00:22 by ookamonu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	display_menu(t_fdf *data)
{
	mlx_string_put(data->mlx, data->win, 20, 10, 0xFF14B6, "*=====MENU=====*");
	mlx_string_put(data->mlx, data->win, 20, 30, 0xFF14B6, "   ESC to Exit");
	mlx_string_put(data->mlx, data->win, 20, 50, 0xFF14B6, "I ISOMETRIC View");
	mlx_string_put(data->mlx, data->win, 20, 70, 0xFF14B6, "P  PARALLEL View");
	mlx_string_put(data->mlx, data->win, 20, 90, 0xF2D0EF, "V  VIBRANT Color");
	mlx_string_put(data->mlx, data->win, 20, 110, 0x860ACD, "E  ELEGANT Color");
	mlx_string_put(data->mlx, data->win, 20, 130, 0xFF14B6, "=======**=======");
}

void	vibrant_color(t_fdf *data, int x, int y)
{
	int	z;

	z = data->map[y][x];
	if (z > 0)
		data->color = 0x860ACD;
	else if (z * data->altitude < 0)
		data->color = 0x009292;
	else
		data->color = 0xF2D0EF;
}

void	elegant_color(t_fdf *data, int x, int y)
{
	int	z;

	z = data->map[y][x];
	if (z > 0)
		data->color = 0xF2D0EF;
	else if (z * data->altitude < 0)
		data->color = 0xCC1A99;
	else
		data->color = 0x860ACD;
}

void	color(t_fdf *data, int x, int y)
{
	if (data->palette == VIBRANT)
		vibrant_color(data, x, y);
	else if (data->palette == ELEGANT)
		elegant_color(data, x, y);
}
