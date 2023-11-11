/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_point.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ookamonu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 14:15:24 by ookamonu          #+#    #+#             */
/*   Updated: 2023/11/03 21:24:21 by ookamonu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	start_value(t_fdf *fdf)
{
	fdf->draw.space = space(fdf);
	fdf->draw.height = 3;
	fdf->draw.start_x = 700;
	fdf->draw.start_y = -300;
	fdf->draw.sinxy = 0.525321989;
	fdf->draw.cosxy = 0.525321989;
	fdf->draw.show = 1;
	fdf->draw.color = 0x00FF00;
	fdf->draw.c_color = 0x00FF00;
}

void    draw_point(t_fdf *fdf)
{
	mlx_string_put(fdf->win.mlx_ptr, fdf->win.win_ptr, 20, 20,
		0xFF4500, "press 'tab' for on/off menu");
	mlx_string_put(fdf->win.mlx_ptr, fdf->win.win_ptr, 28, 40,
		0xFF4500, "press 'Esc' for close");
	fdf->draw.color = 0x00FF00;
	fdf->draw.i = -1;
	fdf->draw.j = -1;
	fdf->draw.x1 = fdf->draw.start_x;
	fdf->draw.y1 = fdf->draw.start_y;
	draw_hor(fdf);
	fdf->draw.i = -1;
	fdf->draw.j = -1;
	fdf->draw.x1 = fdf->draw.start_x;
	fdf->draw.y1 = fdf->draw.start_y;
	fdf->draw.color = 0x00FF00;
	draw_ver(fdf);
}

int    space(t_fdf *fdf)
{
	int i;

	i = 30;
	if (fdf->map.elem >= 20)
		i = 20;
	if (fdf->map.elem >= 50)
		i = 10;
	if (fdf->map.elem >= 100)
		i = 9;
	if (fdf->map.elem >= 150)
		i = 6;
	return (i);
}

void    test_draw(t_fdf *fdf)
{
	fdf->draw.show = 1;
	fdf->menu.m_menu = 1;
	fdf->draw.space = space(fdf);
	fdf->draw.height = 3;
	fdf->draw.start_x = 700;
	fdf->draw.start_y = -300;
	fdf->draw.sinxy = 0.525321989;
	fdf->draw.cosxy = 0.525321989;
	fdf->draw.color = 0x00FF00;
	fdf->draw.c_color = 0x00FF00;
	fdf->win.mlx_ptr = mlx_init();
	fdf->win.win_ptr = mlx_new_window(fdf->win.mlx_ptr, 2000, 1200, "fdf 42");
	draw_point(fdf);
	mlx_hook(fdf->win.win_ptr, 2, 0, keybd_key, fdf);
	mlx_hook(fdf->win.win_ptr, 17, 0, mouse, (void *)0);
	mlx_loop(fdf->win.mlx_ptr);
}
