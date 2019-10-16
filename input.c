/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtwyla <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 10:54:18 by dtwyla            #+#    #+#             */
/*   Updated: 2019/08/21 10:30:59 by dtwyla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			ft_validchar(char *check)
{
	int		c1;
	int		c2;
	int		c3;
	int		ii;

	ii = 0;
	c1 = 0;
	c2 = 0;
	c3 = 0;
	while (ii < 19)
	{
		if (check[ii] == '.')
			c1++;
		if (check[ii] == '#')
			c2++;
		if (ii % 5 == 0 && ii - 1 > 0 && check[ii - 1] == '\n')
			c3++;
		ii++;
	}
	//кол-во . # \n
	if (c2 == 4 && c1 == 12 && c3 == 3)
		return (1);
	return (0);
}

int			ft_validlenghtchar(char *vhod)
{
	int		fd;
	char	*buffer;
	int		counter;
	int		saver;
	// rez - кол-во тетраминок
	int		rez;

	if (!(buffer = (char *)malloc(sizeof(char) * 22)))
		return (0);
	rez = 0;
	fd = open(vhod, O_RDONLY);
	if (fd == -1)
		return (0);
	while ((counter = read(fd, buffer, 21)) > 0)
	{
		//проверяет каждую тетраминку
		if (ft_validchar(buffer) == 0 || counter < 19)
			return (0);
		rez++;
		saver = counter;
	}
	if (saver != 20)
		return (0);
	free(buffer);
	if (close(fd) == -1)
		return (0);
	return (rez);
}

char		***ft_createmat(int flag, int first_par, int second_par)
{
	char	***rix;

	if (!(rix = (char ***)malloc((sizeof(char**)) * (flag + 1))))
		return (NULL);
	while (first_par < flag)
	{
		if (!(rix[first_par] = (char **)malloc((sizeof(char*)) * 5)))
			return (ft_fre(rix, first_par));
		second_par = 0;
		while (second_par < 4)
		{
			if (!(rix[first_par][second_par] = ft_strnew1(4)))
			{
				ft_another_free(rix, first_par, second_par);
				return (NULL);
			}
			second_par++;
		}
		rix[first_par][second_par] = NULL;
		first_par++;
	}
	rix[first_par] = NULL;
	return (rix);
}

int			ft_fillmat(char ***mat, char *vhod, int a, int flag)
{
	int		set;
	int		fdd;
	char	buffer1[5];
	char	buffer2[1];

	set = 0;
	if ((fdd = open(vhod, O_RDONLY)) < set)
		return (0);
	while (set < (flag * 5 - 1))
	{
		if ((set + 1) % 5 == 0 && set > 0)
			read(fdd, buffer2, 1);
		else
		{
			if (set % 5 == 0 && set > 0)
				a++;
			read(fdd, buffer1, 5);
			buffer1[4] = '\0';
			ft_strdupp(buffer1, mat[a][set % 5]);
		}
		set++;
	}
	if (close(fdd) == -1)
		return (0);
	return (1);
}

char		***ft_inputmain(char *vhod)
{
	int		flag;
	char	***mat;
	//считает кол-во тетраминок и проверяет их валидность
	flag = ft_validlenghtchar(vhod);
	if (flag == 0 || flag > 26)
		return (ft_kostilptint());
	//создает 3-мерный массив
	if (!(mat = ft_createmat(flag, 0, 0)))
		return (ft_kostilptint());
	//заполняет массив
	if (ft_fillmat(mat, vhod, 0, flag) == 0)
		return (ft_kostilptint());
	//вторая проверка тетраиминок на кол-во связей 6/8
	if ((ft_tetranos(mat, flag, 0, 0)) == 0)
		return (ft_kostilptint());
	//заменяет # на буквы
	mat = ft_formating(mat, flag, 0, 0);
	return (mat);
}
