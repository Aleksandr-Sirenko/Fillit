/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asirenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 16:36:26 by asirenko          #+#    #+#             */
/*   Updated: 2018/12/04 18:21:48 by asirenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	char	***line;
	char	**map;

	if (argc != 2)
	{
		write(1, "usage: ./fillit tetriminos_file\n", 32);
		exit(1);
	}
	if (validate(argv[1]) == 0 || chains(argv[1]) == 0)
	{
		write(1, "error\n", 6);
		exit(1);
	}
	g_tcount = tetricount(argv[1]);
	line = save3line(save2line(saveline(argv[1])));
	map = solve(line, ft_map());
	ft_printm(map);
	return (0);
}
