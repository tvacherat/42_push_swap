/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvachera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 11:14:38 by tvachera          #+#    #+#             */
/*   Updated: 2021/04/01 13:44:02 by tvachera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../../libft/includes/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

# define GREEN "\033[38;5;46m"
# define CLEAN "\e[H\e[2J"
# define RESET "\033[0m"
# define NB_MOVES 11
# define DELAY 100000

typedef struct	s_stack
{
	int			*list;
	size_t		size;
}				t_stack;

typedef struct	s_pars
{
	bool		opt_c;
	bool		opt_v;
	bool		opt_f;
	char		*file;
	int			fd;
	size_t		size;
	size_t		nb_opt;
	t_stack		a;
	t_stack		b;
}				t_pars;

/*
**	main.c
*/
void			disp_stack(t_pars *pars, char *move, int nb_moves);
void			apply_moves(t_list *list, t_pars *pars);
void			process(t_pars *pars);
t_pars			parsing(int argc, char **argv);
int				main(int argc, char **argv);
/*
**	list.c
*/
bool			check_int(char *nbr, size_t len);
bool			check_nbr(char *nbr);
int				*get_list(int argc, char **argv, size_t nb_opt);
bool			check_list(t_stack *list);
/*
**	moves.c
*/
void			swap(t_stack *stack);
void			push(t_stack *src, t_stack *dest);
void			rotate(t_stack *stack);
void			reverse(t_stack *stack);
void			execute(t_stack *a, t_stack *b, char *move);
/*
**	check.c
*/
bool			is_move(char *line);
bool			is_sort(t_stack *a);
bool			check_args(int argc, char **argv, t_pars *pars);

#endif
