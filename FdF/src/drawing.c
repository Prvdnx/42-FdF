/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ookamonu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 14:15:24 by ookamonu          #+#    #+#             */
/*   Updated: 2023/11/15 05:21:13 by ookamonu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*-------------------------------------------------------------------------*\
This handles the drawing of the terrain map. The draw_lines function sets up
drawing information, including the 3D coordinates of the start and end points,
and then calls the bresenham_algo function to draw lines between these points
using Bresenham's line-drawing algorithm. The set_coordinates function
iterates through the map, calling draw_lines for each pair of adjacent points,
effectively drawing the entire map. The draw_map function serves as the entry
point for map drawing, clearing the window, displaying the menu, and then
calling set_coordinates to draw the complete map. All this play a crucial
roles in visualizing the terrain, transforming 3D coordinates into 2D screen
coordinates and utilizing Bresenham's algorithm for efficient line drawing.
\*--------------------------------------------------------------------------*/
static void	draw_now(t_fdf *data, t_draw start, t_draw end)
{
	t_var	var;

	var.dx = ft_abs(end.x - start.x);
	if (start.x < end.x)
		var.sx = 1;
	else
		var.sx = -1;
	var.dy = -ft_abs(end.y - start.y);
	if (start.y < end.y)
		var.sy = 1;
	else
		var.sy = -1;
	var.err = var.dx + var.dy;
	bresenham_algo(data, start, end, &var);
}

/* Using bresenham Algorithm
static void	draw_now(t_fdf *data, t_draw start, t_draw end)
{
	t_var	var;

	var.dx = ft_abs(end.x - start.x);
	if (start.x < end.x)
		var.sx = 1;
	else
		var.sx = -1;
	var.dy = -ft_abs(end.y - start.y);
	if (start.y < end.y)
		var.sy = 1;
	else
		var.sy = -1;
	var.err = var.dx + var.dy;
	while (start.x != end.x || start.y != end.y)
	{
		mlx_pixel_put(data->mlx, data->win, data->pos_x + start.x, \
		data->pos_y + start.y, data->color);
		if (start.x == end.x && start.y == end.y)
			break ;
		var.e2 = 2 * var.err;
		if (var.e2 >= var.dy)
		{
			var.err += var.dy;
			start.x += var.sx;
		}
		if (var.e2 <= var.dx)
		{
			var.err += var.dx;
			start.y += var.sy;
		}
	}
}*/

// draw_lines function giving all information to "draw_pixels"
// function to draw a straight line
void	draw_lines(t_fdf *data, t_draw start, t_draw end)
{
	t_draw	*info;

	info = (t_draw *)malloc(sizeof(t_draw));
	if (!info)
		exit(-1);
	info->z = data->map[start.y][start.x] * data->altitude;
	info->z2 = data->map[end.y][end.x] * data->altitude;
	info->x = start.x * data->zoom;
	info->x2 = end.x * data->zoom;
	info->y = start.y * data->zoom;
	info->y2 = end.y * data->zoom;
	if (data->projection == ISOMETRIC)
		projection(info);
	start.x = info->x;
	start.y = info->y;
	end.x = info->x2;
	end.y = info->y2;
	draw_now(data, start, end);
	free(info);
}

void	set_coordinates(t_fdf *data, int x, int y)
{
	t_draw	coordinates[2];

	color(data, x, y);
	coordinates[0].x = x;
	coordinates[0].y = y;
	if (x < data->width - 1)
	{
		coordinates[1].x = x + 1;
		coordinates[1].y = y;
		draw_lines(data, coordinates[0], coordinates[1]);
	}
	if (y < data->height - 1)
	{
		coordinates[1].x = x;
		coordinates[1].y = y + 1;
		draw_lines(data, coordinates[0], coordinates[1]);
	}
}

void	draw_map(t_fdf *data)
{
	int	x;
	int	y;

	y = 0;
	mlx_clear_window(data->mlx, data->win);
	display_menu(data);
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			set_coordinates(data, x, y);
			x++;
		}
		y++;
	}
}
