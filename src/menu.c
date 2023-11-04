/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ookamonu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 03:20:26 by ookamonu          #+#    #+#             */
/*   Updated: 2023/11/04 21:48:12 by ookamonu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int menu_key(int key, t_fdf *fdf)
{
	if (key == 48)
	{
		fdf->menu.m_menu = 1;
		mlx_destroy_window(fdf->menu.mlx_ptr, fdf->menu.win_ptr);
	}
	return (0);
}

void    colors(t_fdf *fdf)
{
	mlx_string_put(fdf->menu.mlx_ptr, fdf->menu.win_ptr, 0, 150, 0xFF4500, "Colors:");
	mlx_string_put(fdf->menu.mlx_ptr, fdf->menu.win_ptr, 80, 150, 0x00FF00, "'0' green");
	mlx_string_put(fdf->menu.mlx_ptr, fdf->menu.win_ptr, 80, 170, 0xFF0000, "'1' red");
	mlx_string_put(fdf->menu.mlx_ptr, fdf->menu.win_ptr, 80, 190, 0x0000FF, "'2' blue");
	mlx_string_put(fdf->menu.mlx_ptr, fdf->menu.win_ptr, 80, 210, 0xC0C0C0, "'3' silver");
	mlx_string_put(fdf->menu.mlx_ptr, fdf->menu.win_ptr, 80, 230, 0xFF8C00, "'4' darkorange");
	mlx_string_put(fdf->menu.mlx_ptr, fdf->menu.win_ptr, 80, 250, 0x02691E, "'5' chocolate");
	mlx_string_put(fdf->menu.mlx_ptr, fdf->menu.win_ptr, 80, 270, 0xFFFFFF, "'6' white");
	mlx_string_put(fdf->menu.mlx_ptr, fdf->menu.win_ptr, 80, 290, 0x800080, "'7' purple");
	mlx_string_put(fdf->menu.mlx_ptr, fdf->menu.win_ptr, 80, 310, 0xFFFF00, "'8' yellow");
	mlx_string_put(fdf->menu.mlx_ptr, fdf->menu.win_ptr, 80, 330, 0x00FFFF, "'9' aqua");
	mlx_string_put(fdf->menu.mlx_ptr, fdf->menu.win_ptr, 50, 100, 0xFF4500, "'0-9' for another color");
}

void    menu(t_fdf *fdf, int key)
{
	if (fdf->menu.m_menu == 1)
	{
		(void)key;
		fdf->menu.m_menu = 2;
		fdf->menu.mlx_ptr = mlx_init();
		fdf->menu.win_ptr = mlx_new_window(fdf->menu.mlx_ptr, 800, 800, "MENU");
		mlx_hook(fdf->menu.win_ptr, 2, 0, menu_key, fdf);
		mlx_string_put(fdf->menu.mlx_ptr, fdf->menu.win_ptr, 0, 0, 0xFF4500, "Use:");
		mlx_string_put(fdf->menu.mlx_ptr, fdf->menu.win_ptr, 50, 0, 0xFF4500, "arrows for move map");
		mlx_string_put(fdf->menu.mlx_ptr, fdf->menu.win_ptr, 50, 20, 0xFF4500, "'+/-' for height +/-");
		mlx_string_put(fdf->menu.mlx_ptr, fdf->menu.win_ptr, 50, 40, 0xFF4500, "'P/M' for spaces +/-");
		mlx_string_put(fdf->menu.mlx_ptr, fdf->menu.win_ptr, 50, 60, 0xFF4500, "'Z' for another projection");
		mlx_string_put(fdf->menu.mlx_ptr, fdf->menu.win_ptr, 50, 80, 0xFF4500, "'H' for return on the start projection");
		mlx_string_put(fdf->menu.mlx_ptr, fdf->menu.win_ptr, 50, 120, 0xFF4500, "'TAB' for close menu");
		colors(fdf);
		mlx_loop(fdf->menu.mlx_ptr);
	}
}
