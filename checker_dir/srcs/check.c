/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvachera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 13:28:23 by tvachera          #+#    #+#             */
/*   Updated: 2021/04/01 13:52:52 by tvachera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

bool	is_move(char *line)
{
	size_t		i;
	static char	*moves[] = {"sa", "sb", "ss", "pa", "pb", "ra", "rb", "rr"
		, "rra", "rrb", "rrr"};

	i = 0;
	while (i < NB_MOVES)
	{
		if (!ft_strcmp(line, moves[i]))
			return (true);
		i++;
	}
	return (false);
}

bool	is_sort(t_stack *a)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < a->size)
	{
		j = i + 1;
		if (j < a->size && a->list[i] < a->list[j])
			return (false);
		i++;
	}
	return (true);
}

bool	check_args(int argc, char **argv, t_pars *pars)
{
	size_t	i;
	size_t	j;

	i = 1;
	while (i < (size_t)argc && argv[i][0] == '-' && !check_nbr(argv[i]))
	{
		j = 1;
		while (argv[i][j])
		{
			if (argv[i][j] == 'c')
				pars->opt_c = true;
			else if (argv[i][j] == 'v')
				pars->opt_v = true;
			else if (argv[i][j] == 'f')
				pars->opt_f = true;
			else
				return (false);
			j++;
		}
		if (pars->opt_f == true && !pars->file && i + 1 < (size_t)argc)
			pars->file = argv[++i];
		i++;
	}
	pars->nb_opt = i - 1;
	return (true);
}
