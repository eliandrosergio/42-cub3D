/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efaustin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 12:49:20 by efaustin          #+#    #+#             */
/*   Updated: 2025/03/20 21:24:14 by efaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_erro(char *str)
{
	printf("Error\n%s", str);
	return ;
}

int	is_num(char *str)
{
	int		i;
	int		status;

	i = 0;
	status = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]))
			status = 0;
		i++;
	}
	return (status);
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
