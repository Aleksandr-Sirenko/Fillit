/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voksenui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 13:35:07 by voksenui          #+#    #+#             */
/*   Updated: 2018/11/29 21:25:46 by asirenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		mapsize(int count_t)
{
	int		map;

	map = 2;
	while (map * map < count_t * 4)
		map++;
	return (map);
}

char	*points(char *s, size_t n)
{
	char	*str;
	size_t	i;

	if (!n)
		return (NULL);
	str = s;
	i = 0;
	while (i < n)
		*(str + i++) = '.';
	*(str + i) = '\0';
	return (s);
}

char	**ft_map(void)
{
	char	**maps;
	int		x;
	int		i;

	i = 0;
	x = mapsize(g_tcount);
	maps = (char **)malloc(sizeof(char *) * (x + 1));
	while (i < x)
	{
		maps[i] = (char *)malloc(sizeof(char) * (x + 1));
		maps[i] = points(maps[i], x);
		i++;
	}
	maps[i] = 0;
	return (maps);
}

char	**expmap(int size)
{
	char	**newmap;
	int		i;
	int		j;

	i = 0;
	newmap = (char **)malloc(sizeof(char *) * (size + 1));
	while (i < size)
	{
		j = 0;
		newmap[i] = (char *)malloc(sizeof(char) * (size + 1));
		while (j < size)
		{
			newmap[i][j] = '.';
			j++;
		}
		newmap[i][j] = '\0';
		i++;
	}
	newmap[i] = 0;
	return (newmap);
}

void	free_map(char **map)
{
	int i;

	i = 0;
	while (map[i])
		free(map[i++]);
	free(map);
}
