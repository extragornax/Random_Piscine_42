/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainbis.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwitrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/11 12:31:26 by gwitrand          #+#    #+#             */
/*   Updated: 2016/09/11 14:23:07 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void		ft_putstr(char *str);
void		ft_putchar(char e);
void		affichage(int **grille);
int			absli(int k, int **grille, int i);
int			abscol(int k, int **grille, int j);
int			absblc(int k, int **grille, int i, int j);
int			check_erreur(int argc, char **argv);
int			mkgrille(int **grille, int argc, char **argv);

int			estvalide(int **grille, int pos)
{
	int i;
	int j;
	int k;

	if (pos == 9 * 9)
		return (1);
	i = pos / 9;
	j = pos % 9;
	if (grille[i][j] != 0)
		return (estvalide(grille, pos + 1));
	k = 1;
	while (k <= 9)
	{
		if (absli(k, grille, i) && abscol(k, grille, j)
		&& absblc(k, grille, i, j))
		{
			grille[i][j] = k;
			if (estvalide(grille, pos + 1))
				return (1);
		}
		k++;
	}
	grille[i][j] = 0;
	return (0);
}

int			estvalidebis(int **grille, int pos)
{
	int i;
	int j;
	int k;

	if (pos == 9 * 9)
		return (1);
	i = pos / 9;
	j = pos % 9;
	if (grille[i][j] != 0)
		return (estvalidebis(grille, pos + 1));
	k = 9;
	while (k >= 1)
	{
		if (absli(k, grille, i) && abscol(k, grille, j)
		&& absblc(k, grille, i, j))
		{
			grille[i][j] = k;
			if (estvalidebis(grille, pos + 1))
				return (1);
		}
		k--;
	}
	grille[i][j] = 0;
	return (0);
}

int			main(int argc, char **argv)
{
	int	**grille;

	grille = (int**)malloc(sizeof(int*) * 9);
	if (check_erreur(argc, argv) > 0)
		return (0);

	mkgrille(grille, argc, argv);
	ft_putstr("Grille avant\n");
	affichage(grille);

	estvalide(grille, 0);
	ft_putstr("Grille apres\n");
	affichage(grille);

	mkgrille(grille, argc, argv);
	estvalidebis(grille, 0);
	ft_putstr("Grille apres V2\n");
	affichage(grille);

	
}
