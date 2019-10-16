/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetranos.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtwyla <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 15:15:20 by dtwyla            #+#    #+#             */
/*   Updated: 2019/08/13 13:36:39 by dtwyla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
//подсчет связей
int			ft_insidethesqare(char ***mat, int a, int b, int c)
{
	int		kk;

	kk = 0;
	if (c != 3 && mat[a][b][c + 1] == '#')
		kk++;
	if (c != 0 && mat[a][b][c - 1] == '#')
		kk++;
	if (b != 3 && mat[a][b + 1][c] == '#')
		kk++;
	if (b != 0 && mat[a][b - 1][c] == '#')
		kk++;
	return (kk);
}

//вторая проверка каждой тетраминки на кол-во связей внутри фигуры
int			ft_tetranos(char ***mat, int flagofsize, int b, int c)
{
	int		rez;
	int		a;

	a = 0;
	while (a < flagofsize)
	{
		b = 0;
		rez = 0;
		while (b < 4)
		{
			c = 0;
			while (c < 4)
			{
				if (mat[a][b][c] == '#')
					rez = rez + ft_insidethesqare(mat, a, b, c);
				c++;
			}
			b++;
		}
		if (rez != 6 && rez != 8)
			return (0);
		a++;
	}
	return (1);
}

//замена # на буквы
char		***ft_formating(char ***trix, int flag, int aa, int bb)
{
	int		cc;

	while (aa < flag)
	{
		bb = 0;
		while (bb < 4)
		{
			cc = 0;
			while (cc < 4)
			{
				if (trix[aa][bb][cc] == '#')
					trix[aa][bb][cc] = 65 + aa;
				cc++;
			}
			bb++;
		}
		aa++;
	}
	return (trix);
}

char		***ft_kostilptint(void)
{
	ft_putstrr("error");
	return (NULL);
}

void		*ft_memalloc1(int size)
{
	void	*res;
	char	*reschar;
	int		i;

	res = malloc(size);
	if (res == NULL)
		return (NULL);
	reschar = (char *)res;
	i = 0;
	while (i < size)
	{
		reschar[i] = '\0';
		i++;
	}
	return (reschar);
}
