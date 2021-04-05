/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvachera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 19:05:36 by tvachera          #+#    #+#             */
/*   Updated: 2021/04/01 13:39:23 by tvachera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	clean_disp(t_disp *tab, char *move, int fd)
{
	size_t	i;

	i = 0;
	while (i < 4)
	{
		while (tab[i].nb > 0)
		{
			write(fd, tab[i].move, ft_strlen(tab[i].move));
			write(fd, "\n", 1);
			tab[i].nb--;
		}
		i++;
	}
	if (move)
	{
		write(fd, move, ft_strlen(move));
		write(fd, "\n", 1);
	}
}

void	manage_rr(t_disp *tab, char *move, int fd)
{
	if (tab[2].nb > 0 || tab[3].nb > 0)
		clean_disp(tab, 0, fd);
	if (move[1] == 'a' && tab[1].nb == 0)
		tab[0].nb++;
	else if (move[1] == 'a' && tab[1].nb > 0)
	{
		write(fd, "rr\n", 3);
		tab[1].nb--;
	}
	else if (move[1] == 'b' && tab[0].nb == 0)
		tab[1].nb++;
	else if (move[1] == 'b' && tab[0].nb > 0)
	{
		write(fd, "rr\n", 3);
		tab[0].nb--;
	}
}

void	manage_rrr(t_disp *tab, char *move, int fd)
{
	if (tab[0].nb > 0 || tab[1].nb > 0)
		clean_disp(tab, 0, fd);
	if (move[2] == 'a' && tab[3].nb == 0)
		tab[2].nb++;
	else if (move[2] == 'a' && tab[3].nb > 0)
	{
		write(fd, "rrr\n", 4);
		tab[3].nb--;
	}
	else if (move[2] == 'b' && tab[2].nb == 0)
		tab[3].nb++;
	else if (move[2] == 'b' && tab[2].nb > 0)
	{
		write(fd, "rrr\n", 4);
		tab[2].nb--;
	}
}

void	manage_disp(char *move, int new_fd)
{
	static t_disp	tab[] = {{"ra", 0}, {"rb", 0}, {"rra", 0}, {"rrb", 0}};
	static int		fd = 1;

	if (new_fd > 1)
	{
		fd = new_fd;
		return ;
	}
	if (!move || move[0] == 'p' || move[0] == 's')
		clean_disp(tab, move, fd);
	else if (move[1] == 'r')
		manage_rrr(tab, move, fd);
	else
		manage_rr(tab, move, fd);
}

void	disp_move(char *move, char stack)
{
	if (move[0] == 'p' && stack == 'a')
		manage_disp("pa", 1);
	else if (move[0] == 'p' && stack == 'b')
		manage_disp("pb", 1);
	else if (move[0] == 's' && stack == 'a')
		manage_disp("sa", 1);
	else if (move[0] == 's' && stack == 'b')
		manage_disp("sb", 1);
	else if (move[0] == 'r' && move[1] == 'r' && stack == 'a')
		manage_disp("rra", 1);
	else if (move[0] == 'r' && move[1] == 'r' && stack == 'b')
		manage_disp("rrb", 1);
	else if (move[0] == 'r' && stack == 'a')
		manage_disp("ra", 1);
	else
		manage_disp("rb", 1);
}
