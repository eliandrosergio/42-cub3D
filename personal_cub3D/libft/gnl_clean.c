/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_clean.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efaustin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 23:17:07 by efaustin          #+#    #+#             */
/*   Updated: 2025/03/06 23:30:09 by efaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	gnl_clean(char **buffer)
{
	int		i;

	i = 0;
	while (i < FOPEN_MAX)
	{
		if (buffer[i])
			free(buffer[i]);
		buffer[i] = NULL;
		i++;
	}
	return ;
}
