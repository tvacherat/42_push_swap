/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvachera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 11:17:45 by tvachera          #+#    #+#             */
/*   Updated: 2021/04/01 14:23:45 by tvachera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	disp_stack(t_pars *pars, char *move, int nb_moves)
{
	int	i;

	i = (int)pars->size - 1;
	printf(CLEAN);
	printf("%11c   %-11c\n", 'a', 'b');
	while (i >= 0)
	{
		if (i < (int)pars->a.size)
			printf("%11d | ", pars->a.list[i]);
		else
			printf("%11s | ", "");
		if (i < (int)pars->b.size)
			printf("%-11d", pars->b.list[i]);
		printf("\n");
		i--;
	}
	if (pars->opt_c == true)
		printf(GREEN);
	printf("%s -- %d\n", move, nb_moves);
	if (pars->opt_c == true)
		printf(RESET);
	usleep(DELAY);
}

void	apply_moves(t_list *list, t_pars *pars)
{
	static int	i = 0;

	while (list)
	{
		execute(&pars->a, &pars->b, list->content);
		i++;
		if (pars->opt_v == true)
			disp_stack(pars, list->content, i);
		list = list->next;
	}
}

void	process(t_pars *pars)
{
	char		*line;
	t_list		*list;

	list = 0;
	while (get_next_line(pars->fd, &line))
	{
		if (is_move(line) == false)
		{
			write(2, "Error\n", 6);
			ft_lstclear(&list, &free);
			free(line);
			return ;
		}
		ft_lstadd_back(&list, ft_lstnew(line));
	}
	apply_moves(list, pars);
	ft_lstclear(&list, &free);
	if (is_sort(&pars->a) == true && pars->b.size == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

t_pars	parsing(int argc, char **argv)
{
	t_pars	pars;

	pars.opt_v = false;
	pars.opt_c = false;
	pars.opt_f = false;
	pars.file = 0;
	pars.fd = 0;
	if (!check_args(argc, argv, &pars))
	{
		write(2, "Wrong options\n", 14);
		exit(1);
	}
	if (pars.opt_f == true)
		pars.fd = open(pars.file, O_RDONLY);
	if (pars.fd < 0)
	{
		write(2, "Wrong file\n", 11);
		exit(1);
	}
	pars.a.list = get_list(argc, argv, pars.nb_opt);
	pars.size = argc - 1 - pars.nb_opt;
	pars.a.size = pars.size;
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
		process(&pars);
		if (pars.fd > 0)
			close(pars.fd);
		free(pars.a.list);
		free(pars.b.list);
	}
	return (0);
}
