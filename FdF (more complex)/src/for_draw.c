/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ookamonu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 19:20:07 by ookamonu          #+#    #+#             */
/*   Updated: 2023/11/04 01:30:52 by ookamonu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"
#include <math.h>

void draw_hor_2(t_fdf *fdf)
{
	if (fdf->map.structure[fdf->draw.i][fdf->draw.j] != 0)
		(fdf->draw.color = fdf->draw.color -
		fdf->map.structure[fdf->draw.i][fdf->draw.j] * 500);
	if (fdf->draw.y1 == 0)
	{
		(fdf->draw.y1 = fdf->draw.start_y + fdf->draw.i *
			fdf->draw.space -
			fdf->map.structure[fdf->draw.i][fdf->draw.j] *
			fdf->draw.height);
		(fdf->draw.x1 = fdf->draw.start_x + fdf->draw.j *
			fdf->draw.space -
			fdf->map.structure[fdf->draw.i][fdf->draw.j] *
			fdf->draw.height);
	}
	(fdf->draw.x2 = fdf->draw.start_x + fdf->draw.j *
		fdf->draw.space -
		fdf->map.structure[fdf->draw.i][fdf->draw.j] *
		fdf->draw.height);
	(fdf->draw.y2 = fdf->draw.start_y + fdf->draw.i *
		fdf->draw.space -
		fdf->map.structure[fdf->draw.i][fdf->draw.j] *
		fdf->draw.height);
	drawline(fdf);
	fdf->draw.x1 = fdf->draw.x2;
	fdf->draw.y1 = fdf->draw.y2;
}

void    draw_hor(t_fdf *fdf)
{
	while (++fdf->draw.i < fdf->map.line)
	{
		fdf->draw.x1 = fdf->draw.start_x;
		fdf->draw.j = -1;
		while (++fdf->draw.j < fdf->map.elem)
		{
			fdf->draw.color = fdf->draw.c_color;
			if (fdf->draw.i < fdf->map.line && fdf->draw.j < fdf->map.elem)
			{
				draw_hor_2(fdf);
			}
		}
	}
}

void    draw_ver_2(t_fdf *fdf)
{
	if (fdf->map.structure[fdf->draw.i][fdf->draw.j] != 0)
		(fdf->draw.color = fdf->draw.color -
			fdf->map.structure[fdf->draw.i][fdf->draw.j] > 500); 
	if (fdf->draw.i == 0)
	{
		(fdf->draw.y1 = fdf->draw.start_y + fdf->draw.i *
			fdf->draw.space - 
			fdf->map.structure[fdf->draw.i][fdf->draw.j] *
			fdf->draw.height);
		(fdf->draw.x1 = fdf->draw.start_x + fdf->draw.j *
			fdf->draw.space - 
			fdf->map.structure[fdf->draw.i][fdf->draw.j] *
			fdf->draw.height);
	}
	(fdf->draw.x2 = fdf->draw.start_x + fdf->draw.j *
		fdf->draw.space - 
		fdf->map.structure[fdf->draw.i][fdf->draw.j] *
		fdf->draw.height);
	(fdf->draw.y2 = fdf->draw.start_y + fdf->draw.i *
		fdf->draw.space - 
		fdf->map.structure[fdf->draw.i][fdf->draw.j] *
		fdf->draw.height);
	drawline(fdf);
	fdf->draw.x1 = fdf->draw.x2;
	fdf->draw.y1 = fdf->draw.y2;
}

void    draw_ver(t_fdf *fdf)
{
	while (++fdf->draw.j < fdf->map.elem)
	{
		fdf->draw.y1 = fdf->draw.start_y;
		fdf->draw.i = -1;
		while (++fdf->draw.i < fdf->map.line)
		{
			fdf->draw.color = fdf->draw.c_color;
			if (fdf->draw.i < fdf->map.line && fdf->draw.j < fdf->map.elem)
			{
				draw_ver_2(fdf);
			}
		}
	}
}
