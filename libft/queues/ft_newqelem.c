/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newnode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 15:16:43 by faventur          #+#    #+#             */
/*   Updated: 2022/05/03 16:59:27 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_newqelem() function allocates (with malloc(3)) and returns a
** new "fresh" element. The "content" member variable is initialised to
** the value of the "content" parameter. The "next" variable is
** set to NULL.
*/

#include "stacks.h"

t_qelem	*ft_newqelem(void *content)
{
	t_qelem	*suite;

	suite = malloc(sizeof(*suite));
	if (suite == NULL)
		return (NULL);
	suite->content = content;
	suite->next = NULL;
	return (suite);
}
