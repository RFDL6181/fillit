/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtwyla <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 10:54:18 by dtwyla            #+#    #+#             */
/*   Updated: 2019/09/09 13:29:52 by dtwyla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_putstrr(char const *s)
{
	int		i;

	i = 0;
	if (s)
		while (s[i] != '\0')
		{
			write(1, &s[i], 1);
			i++;
		}
	write(1, "\n", 1);
}

char		*ft_strnew1(int size)
{
	char	*a;

	if (size == ((int)-1))
		return (NULL);
	if (!(a = (char *)ft_memalloc1(sizeof(char) * (size + 1))))
		return (NULL);
	else
		return (a);
}

int			ft_strlen1(const char *s)
{
	int		len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

char		*ft_strdupp(const char *s1, char *b)
{
	size_t	i;

	i = 0;
	while (s1[i])
	{
		b[i] = s1[i];
		i++;
	}
	b[i] = '\0';
	return (b);
}

int			main(int argc, char **argv)
{
	char	***mtrca;

	if (argc != 2)
	{
		ft_putstrr("error");
		write(1, "\n", 1);
		return (0);
	}
	//inputmain в ней будет проходить валидация данных и создаваться 3-мерный массив 
	mtrca = ft_inputmain(argv[1]);
	if (!mtrca)
		return (0);
	//ft_result будем подставлять тетраминки в квадрат
	ft_result(mtrca, argv[1]);
	ft_another_free(mtrca, ft_validlenghtchar(argv[1]), 4);
	exit(0);
}
