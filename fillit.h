/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asirenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 16:38:44 by asirenko          #+#    #+#             */
/*   Updated: 2018/11/29 21:27:49 by asirenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FILLIT_H
# define _FILLIT_H
# include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "get_next_line.h"

int		g_tcount;
int		checkblocks(char *filename);
int		checkfile(char *filename);
int		countblocks(char *str);
int		validate(char *filename);
int		checksymb(char *str);
int		chains(char *filename);
char	**save2line(char *s);
int		tetricount(char *filename);
char	*saveline(char *filename);
int		mapsize(int numb_tetramino);
char	***save3line(char **mas);
int		separate_len(char *str);
char	**alphas(char **str, int i);
int		findhashx(char *str, int i);
int		findhashy(char *str, int i);
char	*separate(char *str, int len);
char	*points(char *s, size_t n);
char	**ft_map(void);
int		ft_puttetri(char **map, char ***tetri, int mapsize, int k);
void	ft_printm(char **map);
int		ft_ylen(char **str);
int		tryput(char **tetri, char **map, int i, int j);
int		put(char **tetri, char **map, int i, int j);
void	deltetri(char **map, int k);
char	**solve(char ***tetri, char **map);
char	**expmap(int size);
void	free_map(char **map);
int		check_strings_len(char *filename);
#endif
