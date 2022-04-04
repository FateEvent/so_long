/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 12:38:44 by faventur          #+#    #+#             */
/*   Updated: 2022/02/27 13:05:55 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The strdup() function returns a pointer to a new string which is a
** duplicate of the string s. Memory for the new string is obtained
** with malloc(3), and can be freed with free(3).
** 
** Return Value: The strdup() function returns a pointer to the
** duplicated string, or NULL if insufficient memory was available.
*/

#include "libft.h"

static char	*ft_strcpy(char *dest, const char *src)
{
	size_t	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strdup(const char *src)
{
	char	*dst;

	dst = (char *)malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (dst == NULL)
		return (NULL);
	ft_strcpy(dst, src);
	return (dst);
}
