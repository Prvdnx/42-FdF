/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ookamonu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 19:18:27 by ookamonu          #+#    #+#             */
/*   Updated: 2023/11/13 01:33:10 by ookamonu         ###   ########.fr       */
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
