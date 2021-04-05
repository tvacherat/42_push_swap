/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvachera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 12:09:40 by tvachera          #+#    #+#             */
/*   Updated: 2021/04/01 13:45:46 by tvachera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../../libft/includes/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct	s_disp
{
	char		*move;
	size_t		nb;
}				t_disp;

typedef struct	s_sort
{
	bool		active;
	int			max;
}				t_sort;

typedef struct	s_stack
{
	int			*list;
	size_t		size;
	int			max;
	int			min;
	int			first;
	int			last;
	char		name;
	t_sort		sort;
}				t_stack;

typedef struct	s_pars
{
	bool		opt_f;
	char		*file;
	int			fd;
	size_t		nb_opt;
	t_stack		a;
	t_stack		b;
}				t_pars;

/*
**	check.c
*/
bool			check_args(int argc, char **argv, t_pars *pars);
bool			check_int(char *nbr, size_t len);
bool			check_nbr(char *nbr);
int				*get_list(int argc, char **argv, size_t nb_opt);
bool			check_list(t_stack *list);
/*
**	list.c
*/
bool			is_sort(t_stack *a);
void			update(t_stack *stack);
size_t			get_index(t_stack *stack, int value);
bool			rotate_to(t_stack *stack, int value);
bool			is_beetween(t_stack *stack, int min, int max);
/*
**	list2.c
*/
void			clean(t_stack *src, t_stack *dest);
void			quick_b(t_stack *a, t_stack *b, int inter_min, int inter_max);
void			quick_a(t_stack *a, t_stack *b, int inter_min, int inter_max);
void			add_to_sort(t_stack *a, t_stack *b);
int				get_closest_value(t_stack *stack, int a, int b);
/*
**	manage.c
*/
void			manage_three(t_stack *stack);
void			manage_few(t_stack *a, t_stack *b);
void			manage_most(t_stack *a, t_stack *b);
/*
**	main.c
*/
void			process(t_stack *a, t_stack *b);
t_pars			parsing(int argc, char **argv);
int				main(int argc, char **argv);
/*
**	moves.c
*/
void			swap(t_stack *stack);
void			push(t_stack *src, t_stack *dest);
void			rotate(t_stack *stack);
void			reverse(t_stack *stack);
/*
**	utils.c
*/
int				nb_inf(t_stack *stack, int value, size_t index);
int				nb_sup(t_stack *stack, int value, size_t index);
int				get_median(t_stack *stack);
/*
**	display.c
*/
void			clean_disp(t_disp *tab, char *move, int fd);
void			manage_rr(t_disp *tab, char *move, int fd);
void			manage_rrr(t_disp *tab, char *move, int fd);
void			manage_disp(char *move, int new_fd);
void			disp_move(char *move, char stack);

#endif
