/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvachera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 11:05:17 by tvachera          #+#    #+#             */
/*   Updated: 2021/04/01 13:37:56 by tvachera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		nb_inf(t_stack *stack, int value, size_t index)
{
	size_t	count;

	count = 0;
	while (index < stack->size)
	{
		if (stack->list[index] < value)
			count++;
		index++;
	}
	return (count);
}

int		nb_sup(t_stack *stack, int value, size_t index)
{
	size_t	count;

	count = 0;
	while (index < stack->size)
	{
		if (stack->list[index] > value)
			count++;
		index++;
	}
	return (count);
}

int		get_median(t_stack *stack)
{
	size_t	i;
	size_t	start;
	size_t	s_size;

	if (stack->sort.active == true)
		i = get_index(stack, stack->min) + 1;
	else
		i = 0;
	s_size = stack->size - i;
	if (s_size == 1)
		return (stack->list[stack->size - 1]);
	start = i;
	while (i < stack->size)
	{
		if (s_size % 2 == 0 && nb_sup(stack, stack->list[i], start) - 1
			== nb_inf(stack, stack->list[i], start))
			break ;
		else if (nb_inf(stack, stack->list[i], start)
			== nb_sup(stack, stack->list[i], start))
			break ;
		i++;
	}
	return (stack->list[i]);
}
