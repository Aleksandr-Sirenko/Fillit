/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asirenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 17:57:44 by asirenko          #+#    #+#             */
/*   Updated: 2018/11/29 18:35:26 by asirenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**alphas(char **str, int i)
{
	int k;
	int j;

	k = 0;
	while (str[k])
	{
		j = 0;
		while (str[k][j])
		{
			if (str[k][j] == '#')
				str[k][j] = ('A' + i);
			j++;
		}
		k++;
	}
	return (str);
}

int		findhashx(char *str, int i)
{
	int x;

	x = 0;
	while (str[i] != '*' && str[i] != '\0')
	{
		if (str[i++] == '#')
			x = 1;
	}
	i--;
	while (str[i] != '*' && i > 0)
	{
		if (str[i--] == '#')
			x = 1;
	}
	if (x == 1)
		return (1);
	return (0);
}

int		findhashy(char *str, int i)
{
	int x;

	x = 0;
	while (i > 4)
	{
		i -= 5;
		if (str[i] == '#')
			x = 1;
	}
	while (i <= 13)
	{
		i += 5;
		if (str[i] == '#')
			x = 1;
	}
	if (x == 1)
		return (1);
	return (0);
}

int		separate_len(char *str)
{
	int i;
	int len;

	i = 0;
	len = 0;
	while (str[i])
	{
		if (str[i] == '*' || str[i] == '#')
			len++;
		if (str[i] == '.' && findhashx(str, i) && findhashy(str, i))
			len++;
		i++;
	}
	return (len);
}

char	*separate(char *str, int len)
{
	char	*newstr;
	int		i;
	int		j;

	j = 0;
	i = 0;
	newstr = (char *)malloc(sizeof(char) * (len + 1));
	while (str[i])
	{
		if (str[i] == '*' || str[i] == '#')
			newstr[j++] = str[i];
		if (str[i] == '.' && findhashx(str, i) && findhashy(str, i))
			newstr[j++] = str[i];
		i++;
	}
	newstr[j] = '\0';
	free(str);
	return (newstr);
}
