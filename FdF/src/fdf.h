/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ookamonu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 19:18:27 by ookamonu          #+#    #+#             */
/*   Updated: 2023/11/15 05:29:02 by ookamonu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "../ft_libft/libft.h"
# include <math.h>
# include "mlx.h"
# include "../minilibx_macos/mlx.h"
# include <stdlib.h>
# include <fcntl.h>

typedef enum e_projection
{
	ISOMETRIC,
	PARALLEL
}	t_projection;

typedef enum e_palette
{
	VIBRANT,
	ELEGANT
}	t_palette;

typedef struct s_var
{
	int				dx;
	int				sx;
	int				dy;
	int				sy;
	int				err;
	int				e2;
}					t_var;

typedef struct s_draw
{
	int				dx;
	int				dy;
	int				x;
	int				x2;
	int				y;
	int				y2;
	int				z;
	int				z2;
}					t_draw;

typedef struct s_fdf
{
	int				**map;
	int				height;
	int				width;
	int				zoom;
	int				map_h;
	int				map_w;
	int				color;
	int				altitude;
	t_projection	projection;
	t_palette		palette;
	int				pos_x;
	int				pos_y;
	void			*mlx;
	void			*win;
}					t_fdf;

void		bresenham_algo(t_fdf *data, t_draw start,
				t_draw end, t_var *var);
void		display_menu(t_fdf *data);
void		reading(char *file, t_fdf *data);
void		map_size(char *file, t_fdf *data);
void		handle_error(char *error);
void		draw_map(t_fdf *data);
void		display_menu(t_fdf *data);
void		color(t_fdf *data, int x, int y);
void		projection(t_draw *info);

#endif
/*--------------------------------------------------------------------------*\
The FdF program is a 3D wireframe renderer that takes a map file as input and
generates a visual representation of the terrain using the MiniLibX graphics
library. The program is written in C and consists of several source files,
each handling specific functionalities.

1. **Main Functionality:**
   - The program starts with the `main` function in the "fdf.c" file.
   - It initializes the necessary structures, including the `t_fdf` structure
   to hold map data, window properties, and rendering configurations.
   - Reads the map file provided as a command-line argument using the `reading`
   function.
   - Sets up the initial image properties and window size based on the height
   and width of the map using the `setup_image` function.
   - Initializes the MiniLibX connection, creates a window, and enters the event
   loop to handle user interactions.

2. **Reading and Processing the Map:**
   - The `reading` function in "reading.c" calculates the height and width of
   the map by reading the input file line by line.
   - Dynamically allocates memory for the map using the `malloc_z` function.
   - Converts string representations of numbers in each line to integers using
   the `fill_map` function.
   - This processed map data is stored in the `t_fdf` structure for later
   rendering.

3. **Rendering and Drawing:**
   - The rendering and drawing functionalities are implemented in "drawing.c."
   - The `draw_map` function iterates through each point in the map, calling
   `set_coordinates` for each point to draw lines between adjacent points.
   - The `set_coordinates` function manages the process of setting coordinates
   for drawing lines based on the map data.
   - The `draw_lines` function is responsible for rendering lines using the
   Bresenham algorithm, and it calls `draw_now` for each point.

4. **Bresenham Line Drawing Algorithm:**
   - The Bresenham algorithm is implemented in "bresenham.c" through the
   `bresenham_algo` function.
   - It calculates the 2D coordinates for each point along the line between
   two given points.
   - Uses the `mlx_pixel_put` function to draw each pixel on the screen
   efficiently.
   - The algorithm ensures accurate and efficient line rendering,
   contributing to the visual representation of the map.

5. **Projection:**
   - The program supports two types of projections: isometric and parallel.
   - The `isometric` function in "do_isometric.c" applies isometric projection
   to 2D coordinates, providing a 3D-like visual representation.
   - The `projection` function in "do_isometric.c" coordinates the
   application of projection to the drawing process.

6. **Color and Menu Display:**
   - Color assignment and menu display functionalities are implemented in
   "colorNmenu.c."
   - The `display_menu` function presents a user interface at the top of the
   window, providing options and information.
   - Two color palettes (vibrant and elegant) are supported, and the `color`
   function determines the color of each point based on the chosen palette.

7. **User Interaction:**
   - The program supports key controls for user interaction.
   - The `control_keys` function in "fdf.c" handles key events, allowing users
   to switch between projections and color palettes, clear the window, and
   exit the program.

8. **Error Handling:**
   - The `handle_error` function in "fdf.c" is responsible for displaying
   error messages and terminating the program in case of critical errors,
   such as invalid map files or memory allocation failures.
\*--------------------------------------------------------------------------*/
