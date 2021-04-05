/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvachera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 15:51:53 by tvachera          #+#    #+#             */
/*   Updated: 2021/03/23 14:28:02 by tvachera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap(t_stack *stack)
{
	int	temp;

	temp = stack->list[stack->size - 1];
	stack->list[stack->size - 1] = stack->list[stack->size - 2];
	stack->list[stack->size - 2] = temp;
	stack->first = stack->list[stack->size - 1];
	disp_move("s", stack->name);
}

void	push(t_stack *src, t_stack *dest)
{
	if (src->size > 0)
	{
		dest->size += 1;
		dest->list[dest->size - 1] = src->list[src->size - 1];
		src->size -= 1;
	}
	update(src);
	update(dest);
	disp_move("p", dest->name);
}

void	rotate(t_stack *stack)
{
	int		temp;
	size_t	i;

	temp = stack->list[stack->size - 1];
	i = stack->size - 1;
	while (i >= 1)
	{
		stack->list[i] = stack->list[i - 1];
		i--;
	}
	stack->list[i] = temp;
	stack->first = stack->list[stack->size - 1];
	stack->last = stack->list[0];
	disp_move("r", stack->name);
}

void	reverse(t_stack *stack)
{
	int		temp;
	size_t	i;

	temp = stack->list[0];
	i = 0;
	while (i < stack->size - 1)
	{
		stack->list[i] = stack->list[i + 1];
		i++;
	}
	stack->list[i] = temp;
	stack->first = stack->list[stack->size - 1];
	stack->last = stack->list[0];
	disp_move("rr", stack->name);
}
