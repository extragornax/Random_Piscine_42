/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colle-2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwitrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/17 18:53:53 by gwitrand          #+#    #+#             */
/*   Updated: 2016/09/17 18:53:54 by gwitrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "function.h"
#include "colle.h"
#define BUF_SIZE 1

int			testcolle02(int more, int x, int y, char *buf)
{
	if (ft_strcmp(buf, colle3(x, y)) == 0)
	{
		if (more > 0)
			ft_putstr(" || ");
		ft_putresult("[colle-03]", x, y);
		more++;
	}
	if (ft_strcmp(buf, colle4(x, y)) == 0)
	{
		if (more > 0)
			ft_putstr(" || ");
		ft_putresult("[colle-04]", x, y);
		more++;
	}
	if (more == 0)
		ft_putstr("aucune");
	ft_putchar('\n');
	return (0);
}

void		ft_tabcmp(char *buf, int x, int y)
{
	int		i;
	int		more;

	i = 0;
	more = 0;
	if (ft_strcmp(buf, colle0(x, y)) == 0)
	{
		ft_putresult("[colle-00]", x, y);
		more++;
	}
	if (ft_strcmp(buf, colle1(x, y)) == 0)
	{
		if (more > 0)
			ft_putstr(" || ");
		ft_putresult("[colle-01]", x, y);
		more++;
	}
	if (ft_strcmp(buf, colle2(x, y)) == 0)
	{
		if (more > 0)
			ft_putstr(" || ");
		ft_putresult("[colle-02]", x, y);
		more++;
	}
	testcolle02(more, x, y, buf);
}

int			testsread(char *buf, int ret, char *mem, int i)
{
	buf[ret] = '\0';
	mem[i] = buf[0];
	i++;
	return (0);
}

int			main(void)
{
	char	*mem;
	char	buf[BUF_SIZE + 1];
	int		ret;
	int		i;
	int		x;
	int		y;

	i = 0;
	x = 0;
	y = 0;
	mem = NULL;
	if (malloc(sizeof(char**) * 2048 + 1))
	{
		while ((ret = read(0, buf, BUF_SIZE)))
		{
			if (buf[0] == '\n')
				y++;
			if (buf[0] != '\n')
				x++;
			testsread(buf, ret, mem, i);
		}
		mem[i] = '\0';
		if (y != 0)
			x = x / y;
		ft_tabcmp(mem, x, y);
		return (0);
	}
}
