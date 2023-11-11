/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ookamonu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 01:17:53 by ookamonu          #+#    #+#             */
/*   Updated: 2023/11/09 00:38:04 by ookamonu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"
#include "../ft_libft/libft.h"

void fdf_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

int main(int argc, char *arg[])
{
	t_fdf *fdf;

	if (argc < 2)
	{
		fdf_putstr("no file to read\n");
	}
	else if (argc > 2)
	{
		fdf_putstr("too many files\n");
	}
	else if (argc == 2)
	{
		fdf = (t_fdf*)malloc(sizeof(t_fdf));
		
		if (ft_read_2(arg[1], fdf) == -1)
		{
			fdf_putstr("error file");
			exit(1);
		}
		read_file(arg[1], fdf);
		test_draw(fdf);
	}
	return (0);
}
