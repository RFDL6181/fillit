/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtwyla <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 11:16:33 by dtwyla            #+#    #+#             */
/*   Updated: 2019/08/21 10:13:56 by dtwyla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_FILLIT_H
# define FILLIT_FILLIT_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>

int		main(int argc, char **argv);
int		ft_tetranos(char ***mat, int flagofsize, int b, int c);
int		ft_insidethesqare(char ***mat, int a, int b, int c);
char	***ft_formating(char ***mat, int flag, int aa, int bb);
char	***ft_kostilptint(void);
char	***ft_inputmain(char *vhod);
int		ft_validlenghtchar(char *vhod);
int		ft_validchar(char *check);
int		ft_fillmat(char ***mat, char *vhod, int bb, int flag);
char	***ft_createmat(int flag, int first_par, int second_par);
int		ft_free_space(char **xirr, int i, int raz);
int		ft_vstavka(char **xirr, char **dne, int i, int j);
int		ft_checker(char **xir, char **dnee, int i, int j);
int		ft_reshtetris(char ***xir, char **dne, int index, int razz);
int		ft_result(char ***rix, char *vh);
int		ft_ccunt(char *vhh, int k);
char	**ft_newmaat(int ll, int i, int j);
int		ft_printmat(char **g, int a);
int		ft_hight(char **xrr, int a, int b);
int		ft_left(char **xxr, int a, int b);
void	ft_putstrr(char const *s);
char	*ft_strdupp(const char *s1, char *b);
int		ft_strlen1(const char *s);
void	*ft_memalloc1(int size);
char	***ft_fre(char ***a, int b);
char	*ft_strnew1(int size);
void	ft_onemorefre(char **end, int i);
void	ft_another_free(char ***rix, int i, int j);

#endif
