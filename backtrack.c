/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtrack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asirenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 16:09:22 by asirenko          #+#    #+#             */
/*   Updated: 2018/11/29 21:26:01 by asirenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		tryput(char **tetri, char **map, int i, int j)
{
	int y;
	int z;
	int k;

	k = j;
	y = 0;
	while (tetri[y])
	{
		z = 0;
		j = k;
		while (tetri[y][z])
		{
			if (tetri[y][z] != '.')
				if (map[i][j] != '.')
					return (0);
			z++;
			j++;
		}
		i++;
		y++;
	}
	return (1);
}

int		put(char **tetri, char **map, int i, int j)
{
	int y;
	int z;
	int k;

	k = j;
	y = 0;
	if (!tryput(tetri, map, i, j))
		return (0);
	while (tetri[y])
	{
		z = 0;
		j = k;
		while (tetri[y][z])
		{
			if (tetri[y][z] != '.')
				map[i][j] = tetri[y][z];
			j++;
			z++;
		}
		i++;
		y++;
	}
	return (1);
}

void	deltetri(char **map, int k)
{
	int i;
	int j;
	int z;

	z = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == k + 'A')
			{
				map[i][j] = '.';
				z++;
			}
			if (z == 4)
				return ;
			j++;
		}
		i++;
	}
}

int		ft_puttetri(char **map, char ***tetri, int mapsize, int k)
{
	int i;
	int j;

	if (!tetri[k])
		return (1);
	i = 0;
	while (i + ft_ylen(tetri[k]) <= mapsize)
	{
		j = 0;
		while (j + (int)ft_strlen(tetri[k][0]) <= mapsize)
		{
			if (put(tetri[k], map, i, j))
			{
				if (ft_puttetri(map, tetri, mapsize, (k + 1)))
					return (1);
				else
					deltetri(map, k);
			}
			j++;
		}
		i++;
	}
	return (0);
}

char	**solve(char ***tetri, char **map)
{
	int size;

	size = ft_ylen(map);
	while (!ft_puttetri(map, tetri, size, 0))
	{
		size++;
		free_map(map);
		map = expmap(size);
	}
	return (map);
}
