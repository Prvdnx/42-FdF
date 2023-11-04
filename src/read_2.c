/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ookamonu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 11:17:34 by ookamonu          #+#    #+#             */
/*   Updated: 2023/11/03 21:20:00 by ookamonu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int check_line(char *line, t_fdf *fdf)
{
	int i;
	int k;

	i = 0;
	k = 1;

	while (line[i] != '\0')
	{
		if (line[i] >= 48 && line[i] < 57 && k < 7)
			k++;
		else if ((line[i] == '-' && (line[i + 1] >= 48 && line[i + 1] < 57)) ||
				line[i] == ' ' || line[i] == '\n')
			k = 0;
		else
			fdf->map.error = -1;
		if (i != 0 && line[i] == '-' && (line[i - 1] >= 48 &&
				line[i - 1] < 57))
			fdf->map.error = -1;
		i++;
	}
	return 1;
}

int number_spaces(char *line)
{
	int k;
	int i;

	k = 0;
	i = 0;
	while (line[i])
	{
		if (line[i] == ' ')
		{
			k++;
			while (line[i] == ' ')
				i++;
		}
		else
			i++;
	}
	if (line[i-1] == '-' || line[0] == ' ')
		k--;
	return k + 1;
}

int ft_read_2(char *argv, t_fdf *fdf)
{
	char *line;
	int k;

	k = 0;
	fdf->map.elem = 0;
	fdf->map.error = 0;
	if ((fdf->map.fd_error = open(argv, O_RDONLY)) < 0)
		return -1;
	while ((k = get_next_line(fdf->map.fd_error, &line)) > 0)
	{
		if (check_line(line, fdf) != 0)
			fdf->map.elem = number_spaces(line);
		else
			fdf->map.error = -1;
		free(line);
	}
	if (k != -1)
		free(line);
	return fdf->map.error;
}
