/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 14:25:26 by faventur          #+#    #+#             */
/*   Updated: 2022/04/03 16:03:58 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_map_reader() function creates an array of strings made up of the
** lines composing the .ber file.
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

char	**ft_map_reader(int fd)
{
	char	**arr;
	char	*buffer;
	char	*temp;
	int		i;

	i = 0;
	buffer = NULL;
	temp = NULL;
	while (get_next_line(fd))
	{
		temp = get_next_line(fd);
		buffer = ft_strlcat(buffer, temp, ft_strlen(buffer) + ft_strlen(temp));
		free(temp);
	}
	arr = ft_split(temp, "\n");
	return (arr);
}

int	ft_open(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (-1);
}
