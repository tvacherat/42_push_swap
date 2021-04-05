/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvachera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 11:17:45 by tvachera          #+#    #+#             */
/*   Updated: 2021/04/02 12:21:18 by tvachera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	process(t_stack *a, t_stack *b)
{
	update(a);
	if (a->size < 3)
		swap(a);
	else if (a->size == 3)
		manage_three(a);
	else if (a->size <= 15)
		manage_few(a, b);
	else
		manage_most(a, b);
	manage_disp(0, 1);
}

t_pars	parsing(int argc, char **argv)
{
	t_pars	pars;

	pars.opt_f = false;
	pars.file = 0;
	pars.fd = 1;
	if (!check_args(argc, argv, &pars))
	{
		write(2, "Wrong options\n", 14);
		exit(1);
	}
	if (pars.opt_f == true)
		pars.fd = open(pars.file, O_WRONLY | O_CREAT | O_TRUNC, S_IRWXU);
	if (pars.fd < 0)
	{
		write(2, "File issue\n", 11);
		exit(1);
	}
	else if (pars.fd > 1)
		manage_disp(0, pars.fd);
	pars.a.list = get_list(argc, argv, pars.nb_opt);
	pars.a.size = argc - 1 - pars.nb_opt;
	pars.a.name = 'a';
	pars.b.name = 'b';
	return (pars);
}

int		main(int argc, char **argv)
{
	t_pars	pars;

	if (argc > 1)
	{
		pars = parsing(argc, argv);
		if (!pars.a.list || check_list(&pars.a) == false)
		{
			write(2, "Error\n", 6);
			return (1);
		}
		if (!(pars.b.list = malloc(sizeof(int) * pars.a.size)))
		{
			write(2, "Error\n", 6);
			free(pars.a.list);
			return (1);
		}
		pars.b.size = 0;
		if (!is_sort(&pars.a))
			process(&pars.a, &pars.b);
		if (pars.fd > 1)
			close(pars.fd);
		free(pars.a.list);
		free(pars.b.list);
	}
	return (0);
}
