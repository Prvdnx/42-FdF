
#ifndef FDF_H
# define FDF_H

# include "../ft_libft/libft.h"
# include "../minilibx/mlx.h"
# include "stdlib.h"

typedef struct	s_window
{
	void	*mlx_ptr;
	void	*win_ptr;
}			t_window;

typedef struct	s_map
{
	int		**karta;
	int		line;
	int		elem;
	int		fd;
	int		fd_error;
	int		error;
}			t_map;

typedef struct	s_draw_map
{
	int		start_x;
	int		start_y;
	int		i;
	int		j;
	int		x1;
	int		x2;
	int		y1;
	int		y2;
	int		color;
	int		spase;
	int		height;
	int		x;
	int		y;
	int		error;
	int		error2;
	double	cosxy;
	double	sinxy;
	int		show;
	int		c_color;
}			t_draw_map;

typedef struct	s_menu
{
	int		m_menu;
	void	*mlx_ptr;
	void	*win_ptr;
}			t_menu;

typedef struct	s_con
{
	int		deltay;
	int		deltax;
	int		signx;
	int		signy;
}			t_con;

typedef struct	s_fdf
{
	t_draw_map	draw;
	t_window	win;
	t_menu		menu;
}				t_fdf;

int		number_pases(char *line);
int		ft_read_2(char *argv, t_fdf *fdf);
int		read_file(char *argv, t_fdf *fdf);
int		menu_key(int key, t_fdf *fdf);
void	menu(t_fdf *fdf, int key);
void	draw_point(t_fdf *fdf);
void	test_draw(t_fdf *fdf);
void	draw_ver(t_fdf *fdf);
void	draw_hor(t_fdf *fdf);
int		write_key(int key, t_fdf *fdf);
int		mouse(int key);
void	start_value(t_fdf *fdf);
int		space(t_fdf *fdf);
void	drawline(t_fdf *fdf);

#endif
