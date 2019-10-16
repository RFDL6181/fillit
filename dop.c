/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dop.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtwyla <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 11:03:08 by dtwyla            #+#    #+#             */
/*   Updated: 2019/08/13 15:32:11 by dtwyla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

//подсчет минимальной размерности
int			ft_ccunt(char *vhh, int k)
{
	int		b;
	int		glg;

	k = ft_validlenghtchar(vhh);
	glg = 1;
	b = 0;
	while (glg != 0)
	{
		if (b * b >= k * 4)
			glg = 0;
		else
			b++;
	}
	return (b);
}

//создание итоговой матрицы
char		**ft_newmaat(int ll, int i, int j)
{
	char	**nwmat;

	if (!(nwmat = (char **)malloc((sizeof(char*)) * (ll + 1))))
		return (NULL);
	while (i < ll)
	{
		if (!(nwmat[i] = (char *)malloc(sizeof(char) * (ll + 1))))
			return (NULL);
		while (j < ll)
		{
			nwmat[i][j] = '.';
			j++;
		}
		nwmat[i][j] = '\0';
		i++;
		j = 0;
	}
	nwmat[i] = NULL;
	return (nwmat);
}

int			ft_printmat(char **g, int a)
{
	int		i;
	int		j;

	i = 0;
	while (i < a)
	{
		j = 0;
		while (j < a)
		{
			write(1, &g[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
	return (0);
}
