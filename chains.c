/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chains.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asirenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 13:52:56 by asirenko          #+#    #+#             */
/*   Updated: 2018/12/03 20:20:52 by asirenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		tetricount(char *filename)
{
	int		i;
	char	*s;
	int		count;

	count = 0;
	s = saveline(filename);
	i = 0;
	while (s[i])
	{
		if (s[i] == '\n' && (s[i - 1] == '.' || s[i - 1] == '#'))
			count++;
		i++;
	}
	free(s);
	return (count / 4);
}

int		chainscount(char *m, int j)
{
	int c;

	c = 0;
	if (m[j + 5] == '#' && j < 14)
		c++;
	if (m[j - 5] == '#' && j > 4)
		c++;
	if (m[j + 1] == '#' && j < 18)
		c++;
	if (m[j - 1] == '#' && j > 0)
		c++;
	return (c);
}

int		chains(char *filename)
{
	int		i;
	int		j;
	char	**m;
	int		c;

	m = save2line(saveline(filename));
	i = 0;
	while (m[i])
	{
		c = 0;
		j = 0;
		while (m[i][j])
		{
			if (m[i][j] == '#')
				c += chainscount(m[i], j);
			j++;
		}
		if (c != 6 && c != 8)
			return (0);
		i++;
	}
	free_map(m);
	return (1);
}

int		check_strings_len(char *filename)
{
	char	**ar;
	int		i;

	i = 0;
	ar = save2line(saveline(filename));
	while (ar[i])
	{
		if (ft_strlen(ar[i]) != 20)
		{
			free_map(ar);
			return (0);
		}
		i++;
	}
	free_map(ar);
	return (1);
}
