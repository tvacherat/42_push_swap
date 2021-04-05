/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvachera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 11:17:45 by tvachera          #+#    #+#             */
/*   Updated: 2021/04/01 13:52:12 by tvachera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
			if (argv[i][j] == 'f')
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

bool	check_int(char *nbr, size_t len)
{
	static char	*min_int = "-2147483648";
	static char	*max_int = "2147483647";
	size_t		i;

	if (len == 11)
	{
		i = 1;
		while (nbr[i] && nbr[i] == min_int[i])
			i++;
		if (nbr[i] && nbr[i] > min_int[i])
			return (false);
	}
	else if (len == 10)
	{
		i = 0;
		while (nbr[i] && nbr[i] == max_int[i])
			i++;
		if (nbr[i] && nbr[i] > max_int[i])
			return (false);
	}
	return (true);
}

bool	check_nbr(char *nbr)
{
	size_t	i;
	size_t	neg;

	i = 0;
	neg = 0;
	if (nbr[i] == '-')
	{
		neg = 1;
		i++;
	}
	while (nbr[i])
	{
		if (nbr[i] < 48 || nbr[i] > 57 || i > 10 + neg)
			return (false);
		i++;
	}
	if ((nbr[i] == 0 && i < 1 + neg) || check_int(nbr, i) == false)
		return (false);
	return (true);
}

int		*get_list(int argc, char **argv, size_t nb_opt)
{
	int		*lst;
	size_t	i;
	size_t	j;

	i = 1 + nb_opt;
	j = 0;
	while (i < (size_t)argc)
	{
		if (argv[i][0] == 0 || check_nbr(argv[i]) == false)
			return (0);
		i++;
	}
	if (argc - 1 - nb_opt < 1)
		return (0);
	if (!(lst = malloc(sizeof(int) * argc - 1 - nb_opt)))
		return (0);
	while (--i > nb_opt)
		lst[j++] = ft_atoi(argv[i]);
	return (lst);
}

bool	check_list(t_stack *list)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < list->size)
	{
		j = i + 1;
		while (j < list->size)
		{
			if (list->list[i] == list->list[j])
			{
				free(list->list);
				return (false);
			}
			j++;
		}
		i++;
	}
	return (true);
}
