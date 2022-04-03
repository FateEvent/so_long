/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 14:25:26 by faventur          #+#    #+#             */
/*   Updated: 2022/04/03 20:39:36 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_map_reader() function opens the .ber files and creates an array
** of strings made up of the lines composing the file.
** 
** The ft_map_freer() function frees the memory allocated to each string
** of the array passed as a parameter and finally frees the array itself.
*/

#include "so_long.h"

void	ft_map_freer(char **map)
{
	int	i;

	i = 0;
	while (map[i++])
		free(map[i]);
	free(map);
}
/*
int ft_wall_parser(char **map)
{
	int		i;
	int		j;
	t_prop	obj;

	i = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				obj.item++;
			if (map[i][j] == 'E')
				obj.exit++;
			if (map[i][j] == 'P')
				obj.start_pos++;
			j++;
		}
		j = 0;
		i++;
	}
	if (obj.item > 0 && obj.exit > 0 && obj.start_pos == 1)
		return (1);
	return (0);
}
*/
int	ft_prop_counter(char **map)
{
	int		i;
	int		j;
	t_prop	obj;

	i = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				obj.item++;
			if (map[i][j] == 'E')
				obj.exit++;
			if (map[i][j] == 'P')
				obj.start_pos++;
			j++;
		}
		j = 0;
		i++;
	}
	if (obj.item > 0 && obj.exit > 0 && obj.start_pos == 1)
		return (1);
	return (0);
}

int	ft_map_parser(char **map)
{
	int	i;
	int	line;

	line = ft_strlen(map[0]);
	i = 1;
	while (map[i])
	{
		if (ft_strlen(map[i]) != line)
			return (0);
		i++;
	}
	if (ft_prop_counter(map) && ft_wall_parser(map))
		return (1);
	return (0);
}

char	**ft_map_reader(char *filename)
{
	char	**arr;
	char	*buffer;
	char	*temp;
	int		fd;
	int		i;

	fd = open(filename, O_RDONLY);
	i = 0;
	if (fd == -1)
		return (NULL);
	buffer = NULL;
	temp = malloc(sizeof(char) * 1);
	if (!temp)
		return (NULL);
	temp[0] = '\0';
	while (get_next_line(fd))
	{
		temp = get_next_line(fd);
		buffer = ft_strjoin(buffer, temp);
		free(temp);
	}
	arr = ft_split(temp, "\n");
	free(buffer);
	return (arr);
}
