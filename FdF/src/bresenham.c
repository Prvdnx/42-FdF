/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ookamonu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 19:54:06 by ookamonu          #+#    #+#             */
/*   Updated: 2023/11/15 05:20:35 by ookamonu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*-------------------------------------------------------------------------*\
The bresenham_algo function implements Bresenham's line-drawing algorithm to
draw a straight line between two points efficiently. This algorithm, based
on integer arithmetic, ensures that the pixels constituting the line are
precisely determined while minimizing computational complexity. The function
iterates over the line, incrementing either the x or y coordinate based on
the slope of line, ensuring a visually accurate & efficient representation
on screen. The use of Bresenham's algorithm in this function is fundamental
to achieving a smooth and optimized rendering of lines in the FdF program.
\*--------------------------------------------------------------------------*/
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
/*-------------------------------------------------------------------------*\
The Bresenham's Line Drawing Algorithm is an efficient method for drawing a
line between two points on a computer screen. It works by determining the
pixels that should be illuminated to create the illusion of a straight line.
The algorithm is widely used in computer graphics due to its simplicity and
efficiency.

Here's a step-by-step explanation of how the Bresenham's Line Drawing
Algorithm works:

1. **Initialization:**
   - Given two points `(x1, y1)` and `(x2, y2)` that define the endpoints of
   the line.
   - Calculate the differences between the endpoint coordinates: `dx = x2 -
   x1` and `dy = y2 - y1`.
   - Calculate the decision parameter `p = 2 * dy - dx`.
   - Initialize variables:
     - `x` and `y` with the starting point `(x1, y1)`.
     - `err` with the initial decision parameter `p`.

2. **Plotting the First Pixel:**
   - Plot the first pixel at the coordinates `(x, y)`.

3. **Main Loop:**
   - Iterate over the x-coordinates from `x1` to `x2`.
   - At each step, check the decision parameter `p`:
     - If `p < 0`, the next pixel is at `(x+1, y)`, and update the decision
	 parameter: `p = p + 2 * dy`.
     - If `p >= 0`, the next pixel is at `(x+1, y+1)`, and update the
	 decision parameter: `p = p + 2 * dy - 2 * dx`.

4. **Incremental Update of Variables:**
   - Increment `x` by 1 in each iteration.
   - If the decision parameter was updated, increment `y` by 1.

5. **Advantages of Bresenham's Algorithm:**
   - Bresenham's algorithm avoids the need for floating-point arithmetic,
   making it computationally more efficient.
   - The algorithm only uses integer addition and subtraction, making it
   suitable for devices that lack hardware support for multiplication or
   division.

6. **Application in FdF:**
   - In the FdF program, the Bresenham's Line Drawing Algorithm is used in
   the `bresenham_algo` function in the "bresenham.c" file.
   - The function takes the FdF data structure, the starting and ending
   points, and a variable structure as parameters.
   - It iterates over the x-coordinates, plotting pixels to draw a line on
   the graphical window.

In summary, Bresenham's Line Drawing Algorithm is a straightforward and
efficient method for drawing lines on a computer screen, particularly useful
in scenarios where integer arithmetic is preferred over floating-point
arithmetic. In FdF, it contributes to the rendering of lines to represent
the 3D wireframe terrain on the graphical window.
\*--------------------------------------------------------------------------*/
