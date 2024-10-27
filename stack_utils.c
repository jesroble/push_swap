/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesroble <jesroble@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 12:39:29 by jesroble          #+#    #+#             */
/*   Updated: 2024/03/19 14:43:18 by jesroble         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//check is the stack is already sorted
bool	stack_sorted(t_stack *stack)
{
	if (!stack)
		return (0);
	while (stack->next)
	{
		if (stack->nbr > stack->next->nbr)
			return (false);
		stack = stack->next;
	}
	return (true);
}

//return the last node of the stack
t_stack	*find_last(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
	{
		stack = stack->next;
	}
	return (stack);
}

//return the length of the stack
int	stack_len(t_stack *stack)
{
	int	count;

	if (!stack)
		return (0);
	count = 0;
	while (stack != NULL)
	{
		stack = stack->next;
		count++;
	}
	return (count);
}

//find the minimum value of the stack
t_stack	*find_min(t_stack *stack)
{
	long		min;
	t_stack		*node;

	if (!stack)
		return (NULL);
	min = LONG_MAX;
	while (stack)
	{
		if (min > stack->nbr)
		{
			min = stack->nbr;
			node = stack;
		}
		stack = stack->next;
	}
	return (node);
}

//find the maximum value of the stack
t_stack	*find_max(t_stack *stack)
{
	long		min;
	t_stack		*node;

	if (!stack)
		return (NULL);
	min = LONG_MIN;
	while (stack)
	{
		if (min < stack->nbr)
		{
			min = stack->nbr;
			node = stack;
		}
		stack = stack->next;
	}
	return (node);
}
