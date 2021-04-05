/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvachera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 15:51:53 by tvachera          #+#    #+#             */
/*   Updated: 2021/03/31 16:26:07 by tvachera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	swap(t_stack *stack)
{
	int	temp;

	if (stack->size < 2)
		return ;
	temp = stack->list[stack->size - 1];
	stack->list[stack->size - 1] = stack->list[stack->size - 2];
	stack->list[stack->size - 2] = temp;
}

void	push(t_stack *src, t_stack *dest)
{
	if (src->size == 0)
		return ;
	if (src->size > 0)
	{
		dest->size += 1;
		dest->list[dest->size - 1] = src->list[src->size - 1];
		src->size -= 1;
	}
}

void	rotate(t_stack *stack)
{
	int		temp;
	size_t	i;

	if (stack->size < 2)
		return ;
	temp = stack->list[stack->size - 1];
	i = stack->size - 1;
	while (i >= 1)
	{
		stack->list[i] = stack->list[i - 1];
		i--;
	}
	stack->list[i] = temp;
}

void	reverse(t_stack *stack)
{
	int		temp;
	size_t	i;

	if (stack->size < 2)
		return ;
	temp = stack->list[0];
	i = 0;
	while (i < stack->size - 1)
	{
		stack->list[i] = stack->list[i + 1];
		i++;
	}
	stack->list[i] = temp;
}

void	execute(t_stack *a, t_stack *b, char *move)
{
	if (!ft_strcmp(move, "sa"))
		return (swap(a));
	else if (!ft_strcmp(move, "sb"))
		return (swap(b));
	else if (!ft_strcmp(move, "pa"))
		return (push(b, a));
	else if (!ft_strcmp(move, "pb"))
		return (push(a, b));
	else if (!ft_strcmp(move, "ra"))
		return (rotate(a));
	else if (!ft_strcmp(move, "rb"))
		return (rotate(b));
	else if (!ft_strcmp(move, "rr"))
	{
		rotate(a);
		return (rotate(b));
	}
	else if (!ft_strcmp(move, "rra"))
		return (reverse(a));
	else if (!ft_strcmp(move, "rrb"))
		return (reverse(b));
	reverse(a);
	reverse(b);
}
