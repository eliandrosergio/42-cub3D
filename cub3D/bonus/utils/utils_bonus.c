/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elian <elian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 12:49:20 by efaustin          #+#    #+#             */
/*   Updated: 2025/03/26 14:08:12 by elian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	print_erro(char *str)
{
	printf("Error\n%s", str);
	return ;
}

int	is_num(char *str)
{
	int	i;

	if (!str)
		return (0);
	while (*str == ' ' || *str == '\t' || *str == '\n')
		str++;
	if (!*str)
		return (0);
	if ((*str == '-' || *str == '+') && ft_isdigit(str[1]))
		str++;
	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			break ;
		i++;
	}
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
		i++;
	return (str[i] == '\0');
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
