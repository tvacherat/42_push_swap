/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvachera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 19:04:14 by tvachera          #+#    #+#             */
/*   Updated: 2021/04/01 13:38:12 by tvachera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	manage_three(t_stack *stack)
{
	if (stack->list[0] > stack->list[2])
	{
		if (stack->list[1] < stack->list[2])
			return (swap(stack));
		swap(stack);
		rotate(stack);
	}
	else if (stack->list[2] > stack->list[1])
	{
		if (stack->list[0] > stack->list[1])
			return (rotate(stack));
		swap(stack);
		reverse(stack);
	}
	else
		reverse(stack);
}

void	manage_few(t_stack *a, t_stack *b)
{
	while (a->size != 3)
	{
		rotate_to(a, a->min);
		push(a, b);
	}
	if (!is_sort(a))
		manage_three(a);
	while (b->size != 0)
		push(b, a);
}

void	manage_most(t_stack *a, t_stack *b)
{
	int	inter_max;
	int	inter_min;

	a->sort.active = false;
	b->sort.active = false;
	inter_min = a->min;
	while (!is_sort(a))
	{
		inter_max = get_median(a);
		if (inter_max == inter_min)
		{
			if (a->first > a->list[a->size - 2])
				swap(a);
			rotate(a);
			rotate(a);
			return ;
		}
		quick_a(a, b, inter_min, inter_max);
		inter_min = a->sort.max + 1;
	}
}
