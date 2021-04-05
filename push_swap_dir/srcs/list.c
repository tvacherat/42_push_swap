/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvachera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 13:25:27 by tvachera          #+#    #+#             */
/*   Updated: 2021/04/01 13:38:44 by tvachera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

void	update(t_stack *stack)
{
	size_t	i;

	i = 1;
	if (!stack->size)
		return ;
	stack->first = stack->list[stack->size - 1];
	stack->last = stack->list[0];
	stack->min = stack->last;
	stack->max = stack->last;
	while (i < stack->size)
	{
		if (stack->list[i] > stack->max)
			stack->max = stack->list[i];
		if (stack->list[i] < stack->min)
			stack->min = stack->list[i];
		i++;
	}
}

size_t	get_index(t_stack *stack, int value)
{
	size_t	i;

	i = 0;
	while (i < stack->size && stack->list[i] != value)
		i++;
	return (i);
}

bool	rotate_to(t_stack *stack, int value)
{
	size_t	index;

	index = get_index(stack, value);
	if (index == stack->size)
		return (false);
	if (index >= stack->size / 2)
	{
		while (stack->first != value)
			rotate(stack);
	}
	else
	{
		while (stack->first != value)
			reverse(stack);
	}
	return (true);
}

bool	is_beetween(t_stack *stack, int min, int max)
{
	size_t	i;

	i = 0;
	while (i < stack->size)
	{
		if (stack->list[i] >= min && stack->list[i] <= max)
			return (true);
		i++;
	}
	return (false);
}
