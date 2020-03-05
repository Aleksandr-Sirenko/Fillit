/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asirenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 16:39:56 by asirenko          #+#    #+#             */
/*   Updated: 2018/12/04 12:03:48 by asirenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		checkfile(char *filename)
{
	char	*str;
	int		fd;
	int		i;

	i = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (0);
	while (get_next_line(fd, &str))
	{
		i++;
		if ((ft_strlen(str) != 4 && ft_strcmp(str, "") != 0) || (ft_strcmp(str,
						"") == 0 && i % 5 != 0) || (checksymb(str) == 0))
		{
			free(str);
			return (0);
		}
		free(str);
	}
	free(str);
	if (i % 5 == 0)
		return (0);
	if (i < 4 || i > 129)
		return (0);
	return (1);
}

int		validate(char *filename)
{
	if (checkfile(filename) == 0)
		return (0);
	if (checkblocks(filename) == 0)
		return (0);
	if (check_strings_len(filename) == 0)
		return (0);
	return (1);
}

int		checksymb(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '.' && str[i] != '#')
			return (0);
		i++;
	}
	return (1);
}

int		countblocks(char *str)
{
	int i;
	int blocks;

	blocks = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '#')
			blocks++;
		i++;
	}
	return (blocks);
}

int		checkblocks(char *filename)
{
	int		fd;
	char	*str;
	int		blocks;

	blocks = 0;
	fd = open(filename, O_RDONLY);
	while (get_next_line(fd, &str))
	{
		blocks += countblocks(str);
		if (ft_strcmp(str, "") == 0 && blocks != 4)
			return (0);
		if (ft_strcmp(str, "") == 0 && blocks == 4)
			blocks = 0;
		free(str);
	}
	free(str);
	if (blocks != 4)
		return (0);
	return (1);
}
