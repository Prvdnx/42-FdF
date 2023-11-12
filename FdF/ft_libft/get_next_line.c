/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ookamonu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 06:08:55 by ookamonu          #+#    #+#             */
/*   Updated: 2023/11/13 00:54:51 by ookamonu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*int	ft_gnlstrlen(char *string)
{
	int	count;

	count = 0;
	while (string[count])
		count++;
	return (count);
}

char	*ft_gnlstrdup(char *string)
{
	int		i;
	int		size;
	char	*duplicate;

	i = 0;
	size = ft_gnlstrlen(string);
	duplicate = malloc(sizeof(char) * (size + 1));
	if (!duplicate)
		return (0);
	while (string[i])
	{
		duplicate[i] = string[i];
		i++;
	}
	duplicate[i] = '\0';
	return (duplicate);
}

char	*get_next_line(int fd)
{
	char	buffer;
	char	line[7000000];
	int		b;
	int		i;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
		
	i = 0;
	b = read(fd, &buffer, BUFFER_SIZE);
	while (b > 0)
	{
		line[i++] = buffer;
		if (buffer == '\n')
			break ;
		b = read(fd, &buffer, BUFFER_SIZE);
	}
	line[i] = '\0';
	if (b <= 0 && i == 0)
		return (NULL);
	return (ft_gnlstrdup(line));
}*/

int	search_line(char **stack, char **line)
{
	int		len;
	char	*tmp;

	len = 0;
	while ((*stack)[len] != '\n' && (*stack)[len] != '\0')
		len++;
	if ((*stack)[len] == '\n')
	{
		*line = ft_strsub(*stack, 0, len);
		tmp = ft_strdup(*stack + len + 1);
		free(*stack);
		*stack = tmp;
		if (*stack[0] == '\0')
			ft_strdel(stack);
	}
	else if ((*stack)[len] == '\0')
	{
		*line = ft_strdup(*stack);
		ft_strdel(stack);
	}
	return (1);
}

int	ft_return(char **stack, int n, char **line)
{
	if (n < 0)
		return (-1);
	else if (n == 0 && (*stack) == NULL)
		return (0);
	else
		return (search_line(stack, line));
}

int	get_next_line(const int fd, char **line)
{
	char		buffer[BUFF_SIZE + 1];
	char		*tmp;
	static char	*stack;
	int			n;

	if (fd < 0 || line == NULL)
		return (-1);
	n = read(fd, buffer, BUFF_SIZE);
	while (n > 0)
	{
		buffer[n] = '\0';
		if (stack == NULL)
			stack = ft_strdup(buffer);
		else
		{
			tmp = ft_strjoin(stack, buffer);
			free(stack);
			stack = tmp;
		}
		if (ft_strchr(buffer, '\n'))
			break ;
		n = read(fd, buffer, BUFF_SIZE);
	}
	return (ft_return(&stack, n, line));
}
