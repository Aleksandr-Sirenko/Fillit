/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asirenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 22:09:44 by asirenko          #+#    #+#             */
/*   Updated: 2018/11/29 18:53:03 by asirenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	***save3line(char **mas)
{
	char	***a;
	int		i;
	int		j;

	j = 0;
	i = 0;
	a = (char ***)malloc(sizeof(char **) * (g_tcount + 1));
	while (mas[j])
	{
		mas[j] = separate(mas[j], separate_len(mas[j]));
		j++;
	}
	j = 0;
	while (i < g_tcount)
		a[i++] = ft_strsplit(mas[j++], '*');
	a[i] = 0;
	i = -1;
	while (a[++i])
		a[i] = alphas(a[i], i);
	free_map(mas);
	return (a);
}

char	**save2line(char *s)
{
	int		i;
	char	**mas;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n' && (s[i - 1] == '.' || s[i - 1] == '#'))
			s[i] = '*';
		i++;
	}
	mas = ft_strsplit(s, '\n');
	free(s);
	return (mas);
}

char	*saveline(char *filename)
{
	int		fd;
	char	*buf;
	int		ret;
	char	*line;

	buf = (char *)malloc(sizeof(char) * 546);
	fd = open(filename, O_RDONLY);
	ret = read(fd, buf, 546);
	buf[ret] = '\0';
	line = ft_strdup(buf);
	close(fd);
	free(buf);
	return (line);
}

void	ft_printm(char **map)
{
	int i;

	i = 0;
	while (map[i])
		ft_putendl(map[i++]);
}

int		ft_ylen(char **str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
