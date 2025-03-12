/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efaustin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 12:49:20 by efaustin          #+#    #+#             */
/*   Updated: 2025/03/12 15:20:24 by efaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_erro(char *str)
{
	printf("Error\n%s", str);
	return ;
}

int	is_num(char val)
{
	if (val >= '0' && val <= '9')
		return (1);
	return (0);
}

int	ft_strchr_int(const char *s, int c)
{
	char	find_c;

	find_c = c;
	while (*s != find_c)
	{
		if (*s == '\0')
			return (1);
		s++;
	}
	return (0);
}

int	return_erro(char *str1, char *str2, char *str3, char *line)
{
	print_erro(str1);
	if (str2)
		printf("%s", str2);
	if (str3)
		printf("%s", str3);
	if (line)
		free(line);
	return (1);
}
