/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ookamonu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 01:17:53 by ookamonu          #+#    #+#             */
/*   Updated: 2023/11/15 05:15:51 by ookamonu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*-------------------------------handle_error-------------------------------*\
The handle_error function is responsible 4 managing error handling within the
program. It utilizes the ft_putendl function from ft_libft library to display
the specified error message to the user. Upon displaying error, the program
exits with the EXIT_FAILURE status to indicate an unsuccessful execution.
\*--------------------------------------------------------------------------*/
void	handle_error(char *error)
{
	ft_putendl(error);
	exit(EXIT_FAILURE);
}

/*-------------------------------win_interface------------------------------*\
The win_interface function dynamically adjusts the window parameters based on
size of the map. It assesses dimensions of the map & adjusts the zoom, map
height, and map width accordingly, ensuring suitable display for various map
sizes. This function is integral in providing a responsive and adaptable
interface, optimizing the visual representation of the map based on its
characteristics. By tailoring the window parameters to the map size, the
win_interface function contributes to enhanced user experience, accommodating
different scales and dimensions of input maps.
\*--------------------------------------------------------------------------*/
void	win_interface(t_fdf *data)
{
	if (data->height > 300 || data->width > 300)
	{
		data->zoom = 1;
		data->map_h = 1300;
		data->map_w = 2400;
	}
	else if (data->height > 200 || data->width > 200)
	{
		data->zoom = 2;
		data->map_h = 1200;
		data->map_w = 2200;
	}
	else if (data->height > 100 || data->width > 100)
	{
		data->zoom = 4;
		data->map_h = 1000;
		data->map_w = 2000;
	}
	else if (data->height > 25 || data->width > 25)
	{
		data->zoom = 8;
		data->map_h = 1000;
		data->map_w = 1600;
	}
}

/*------------------------------setup_image---------------------------------*\
The function initializes various parameters within the t_fdf struct,
setting up the initial state for the MiniLibX window and the map display. It
defines the initial zoom level, map height, map width, color, altitude, palette,
projection, and position. This function is pivotal in establishing the baseline
configuration for the graphical representation of the map, ensuring consistent
starting point for the subsequent rendering and user interaction. By providing
default values and configurations, setup_image sets the stage for a visually
appealing and functionally sound display.
\*--------------------------------------------------------------------------*/
void	setup_image(t_fdf *data)
{
	data->zoom = 25;
	data->map_h = 800;
	data->map_w = 1000;
	data->color = 0xFFFFFF;
	data->altitude = 1;
	data->palette = VIBRANT;
	data->projection = ISOMETRIC;
	win_interface(data);
	data->pos_x = data->map_w / 2 - (data->map_w / 15);
	data->pos_y = 200;
}

/*------------------------------control_keys--------------------------------*\
This function serves as an event handler for keyboard input, responding
to specific key presses & triggering corresponding actions. It is called in
context of the MiniLibX event loop when a key is pressed. Function interprets
key codes to execute actions such as program termination, window clearing, and
switching btw different projections and color palettes. By providing dynamic
control over these aspects, control_keys enhances user's ability to interact
with the program, facilitating a more immersive and responsive experience.
\*--------------------------------------------------------------------------*/
int	control_keys(int key, t_fdf *data)
{
	if (key == 53)
		exit(0);
	else if (key == 8)
		mlx_clear_window(data->mlx, data->win);
	else if (key == 34)
		data->projection = ISOMETRIC;
	else if (key == 35)
		data->projection = PARALLEL;
	else if (key == 14)
		data->palette = ELEGANT;
	else if (key == 9)
		data->palette = VIBRANT;
	draw_map(data);
	return (0);
}

/*----------------------------------main-----------------------------------*\
 The program begins with the definition of the main function.
 Inside this function, memory is allocated for the FdF data structure,
 and command-line arguments are checked to ensure the correct number is
 provided. If the arguments are valid, the map file is read using the reading
 function, and the FdF data is initialized with default values in the
 setup_image function. The MiniLibX library is then initialized, a window
 is created, and the initial map is drawn. The control_keys function is
 registered as a callback using mlx_hook to handle user input. The program
 enters the event loop with mlx_loop, continuously responding to user actions,
 updating the display, and providing an interactive environment for exploring
 the terrain.
\*--------------------------------------------------------------------------*/
int	main(int argc, char **argv)
{
	t_fdf	*data;

	data = (t_fdf *)malloc(sizeof(t_fdf));
	if (!data)
		exit(1);
	if (argc != 2)
	{
		handle_error("Number of arguments are incorrect!");
		return (1);
	}
	reading(argv[1], data);
	setup_image(data);
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, data->map_w, data->map_h, "FDF");
	draw_map(data);
	mlx_hook(data->win, 2, 0, control_keys, data);
	mlx_loop(data->mlx);
	free(data);
	return (0);
}
/*----------------------------------matrix-----------------------------------*\
1. **Understanding a Matrix:**
   - In mathematics, a matrix is like a grid of numbers. Think of it as a
   box filled with values.
   - For example, a 2x2 matrix might look like this:

     ```
     | a  b |
     | c  d |
     ```

2. **Transformation Matrix:**
   - In computer graphics, we often use matrices to perform transformations
   on points in 3D space.
   - A transformation matrix is a special kind of matrix that helps us
   change the position, size, or orientation of objects.

3. **Matrix Multiplication:**
   - When we want to apply a transformation to a point, we use matrix
   multiplication.
   - Imagine we have a point (x, y, z) & a transformation matrix like this:

     ```
     | a  b  c  |
     | d  e  f  |
     | g  h  i  |
     | 0  0  0  |
     ```

   - To get the new coordinates (x', y', z'), we multiply the
   matrix by the point:

     ```
     x' = ax + by + cz
     y' = dx + ey + fz
     z' = gx + hy + iz
     ```

4. **Applying to Perspective Projection:**
   - In the FdF program, perspective projection is used to make 3D
   points appear on a 2D screen.
   - The projection matrix might look like this:

     ```
     | 1  0  0  0 |
     | 0  1  0  0 |
     | 0  0  1  0 |
     | 0  0  1/d 0 |
     ```

   - To project a point (x, y, z), we use matrix multiplication:

     ```
     x' = x
     y' = y
     z' = z
     w' = 1 / (z / d)
     ```

   - And then, the final 2D coordinates are obtained by dividing
   x', y', and z' by w':

     ```
     x2d = x' / w'
     y2d = y' / w'
     ```

5. **Real-world Analogy:**
   - Think of these matrices as tools that help transform and project
   points, much like using a magic lens to adjust how objects appear.

6. **Application in FdF:**
   - In FdF, these matrix calculations are behind the scenes, helping to
   transform and project 3D points onto a 2D screen, creating the visual
   representation of the terrain.

In simple terms, matrices in this program act as tools that help adjust the
positions of points in 3D space, making them appear correctly on a 2D screen.
It's like a magic recipe for turning 3D coordinates into pixels on your
computer or phone screen!
\*--------------------------------------------------------------------------*/

/*-------------------------------3D-Formula---------------------------------*\
The concept of 3D projection, particularly perspective projection, and the
mathematics involved.

1. **Coordinate System:**
   - In a 3D space, we typically use a Cartesian coordinate system. Each point
   is represented by three coordinates: (x, y, z).
   - `x` is the horizontal position.
   - `y` is the vertical position.
   - `z` is the depth or distance from the viewer.

2. **Perspective Projection:**
   - In the real world, objects that are farther away appear smaller. This
   phenomenon is what we want to simulate with perspective projection.
   - When we look at a scene, objects that are closer to us seem larger,
   while those farther away seem smaller.

3. **Homogeneous Coordinates:**
   - To perform 3D projections, we often use homogeneous coordinates, where a
   3D point is represented as (x, y, z, w).
   - Homogeneous coordinates allow us to represent translation as well as
   projection using matrices.

4. **Projection Matrix:**
   - Perspective projection involves the use of a projection matrix. For a
   simple perspective projection, the matrix might look like this:

     ```
     | 1  0  0  0 |
     | 0  1  0  0 |
     | 0  0  1  0 |
     | 0  0  1/d 0 |
     ```

     - `d` is the distance from the viewer to the projection plane.

5. **Projection Formula:**
   - The perspective projection formula for a point (x, y, z) is given by:

     ```
     x' = x / (z / d)
     y' = y / (z / d)
     ```

     - Here, `x'` and `y'` are the projected 2D coordinates on viewing plane.

6. **Understanding the Formula:**
   - Dividing `x` and `y` by `z / d` simulates the effect of objects getting
   smaller as they move away from the viewer.
   - If `z` is large (object is far away), dividing by a large `z` value
   shrinks `x` and `y`, making the point appear smaller on the screen.
   - If `z` is small (object is closer), dividing by a small `z` doesn't
   reduce `x` and `y` as much, making the point appear larger.

7. **Real World Analogy:**
   - Think of taking a photo where you pinch the sides of the photo frame
   for distant objects to fit them in the frame.

8. **Application in Computer Graphics:**
   - In computer graphics, this projection process is applied to every point
   in a 3D scene to transform it into 2D screen coordinates.
   - The resulting 2D coordinates are what get displayed on your computer or
   phone screen, creating the illusion of depth and perspective in a 3D scene.

In essence, the perspective projection formula adjusts 3D coordinates to
simulate how objects appear smaller as they move away from the viewer,
creating a realistic representation of depth on a 2D surface.
\*--------------------------------------------------------------------------*/
