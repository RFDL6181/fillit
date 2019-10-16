/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   highmoon.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtwyla <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 18:13:56 by dtwyla            #+#    #+#             */
/*   Updated: 2019/08/13 18:47:52 by dtwyla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_hight(char **xrr, int a, int b)
{
	int destiny;

	while (a > -1)
	{
		b = 3;
		while (b > -1)
		{
			if (xrr[a][b] != '.')
				destiny = a;
			b--;
		}
		a--;
	}
	return (destiny);
}

int		ft_left(char **xxr, int aa, int bb)
{
	int newlight;

	newlight = 10;
	while (aa > -1)
	{
		bb = 3;
		while (bb > -1)
		{
			if (xxr[aa][bb] != '.' && bb < newlight)
				newlight = bb;
			bb--;
		}
		aa--;
	}
	return (newlight);
}

char	***ft_fre(char ***a, int b)
{
	int i;
	int j;

	i = 0;
	while (i < b)
	{
		j = 0;
		while (j < 4)
		{
			free(a[i][j]);
			j++;
		}
		free(a[i]);
		i++;
	}
	free(a);
	return (NULL);
}

void	ft_onemorefre(char **end, int i)
{
	while (end[i])
		free(end[i++]);
	free(end);
	return ;
}

void	ft_another_free(char ***rix, int i, int j)
{
	int a;
	int b;

	a = 0;
	while (a < i)
	{
		b = 0;
		while (b < j)
		{
			free(rix[a][b]);
			b++;
		}
		free(rix[a]);
		a++;
	}
	free(rix);
	return ;
}
