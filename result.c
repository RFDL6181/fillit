/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   result.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtwyla <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 10:54:46 by dtwyla            #+#    #+#             */
/*   Updated: 2019/09/09 15:54:10 by dtwyla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			ft_free_space(char **dnee, int i, int raz)
{
	int		a;
	int		b;

	a = 0;
	while (a < raz)
	{
		b = 0;
		while (b < raz)
		{
			if (dnee[a][b] == 65 + i)
				dnee[a][b] = '.';
			b++;
		}
		a++;
	}
	return (0);
}

int			ft_vstavka(char **xirr, char **dne, int i, int j)
{
	int		a;
	int		b;
	int		l;
	int		k;

	k = ft_hight(xirr, 3, 3);
	l = ft_left(xirr, 3, 3);
	a = 0;
	while (a < 4)
	{
		b = 0;
		while (b < 4)
		{
			if (xirr[a][b] != '.')
				dne[i + (a - k)][j + (b - l)] = xirr[a][b];
			b++;
		}
		a++;
	}
	return (1);
}

int			ft_checker(char **xir, char **dnee, int i, int j)
{
	int		a;
	int		b;
	int		gg;
	int		k;
	int		l;
	//k и l находят крайний левый и самый верхний элемент тетраминки ft_left ft_hight находятся в ft_hightmoon 
	k = ft_hight(xir, 3, 3);
	l = ft_left(xir, 3, 3);
	a = 0;
	gg = 0;
	while (a < 4)
	{
		b = 0;
		while (b < 4)
		{
			if (xir[a][b] != '.')
				if (i + (a - k) < ft_strlen1(dnee[0]))
					if (j + (b - l) < ft_strlen1(dnee[0]))
						if (dnee[i + (a - k)][j + (b - l)] == '.')
							gg++;
			b++;
		}
		a++;
	}
	return (gg == 4 ? 1 : 0);
}

int			ft_reshtetris(char ***xir, char **dne, int index, int razz)
{
	int		a;
	int		b;

	a = 0;
	//условие выхода при найденном решении 
	if (xir[index] == NULL)
		return (0);
	//цикл идет по итоговой матрице и пытается подставлять фигурки
	while (a < razz)
	{
		b = 0;
		while (b < razz)
		{
			//ft_checker проверяет можно ли подставить фигуру в этом месте	
			if (ft_checker(xir[index], dne, a, b) == 1)
			{
				//вставляет фигуру
				ft_vstavka(xir[index], dne, a, b);
				//вызывать функцию, пытается подставить след фигуру
				if (ft_reshtetris(xir, dne, index + 1, razz) == 0)
					return (0);
				//чистит матрицу от неправильной подстановки 
				ft_free_space(dne, index, razz);
			}
			b++;
		}
		a++;
	}
	return (1);
}

int			ft_result(char ***rix, char *vh)
{
	char	**end;
	int		raz;
	int		ff;

	ff = 0;
	//raz считает минимально возможный квадрат в который теоретически можно впихнуть входные данные, функция находится в файле dop
	raz = ft_ccunt(vh, 0);
	while (ff < 1)
	{
		//создание итоговой матрицы
		if (!(end = ft_newmaat(raz, 0, 0)))
			return (!(write(1, "error", 5)));
		if (ft_reshtetris(rix, end, 0, raz) == 1)
		{
			//при неудачной попытке подстановки размер увеличивается 
			ft_onemorefre(end, 0);
			raz++;
		}
		else
			ff = 1;
	}
	//вывод результата
	ft_printmat(end, raz);
	ft_onemorefre(end, 0);
	return (0);
}
