/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesroble <jesroble@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 15:37:49 by jesroble          #+#    #+#             */
/*   Updated: 2024/03/04 17:26:17 by jesroble         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_index(t_stack *stack)
{
	int		index;
	int		median;

	index = 0;
	if (!stack)
		return ;
	median = stack_len(stack) / 2;
	while (stack)
	{
		stack->index = index;
		if (index <= median)
			stack->above_median = true;
		else
			stack->above_median = false;
		index++;
		stack = stack->next;
	}
}

static void	set_target_a(t_stack *a, t_stack *b)
{
	t_stack	*current_b;
	t_stack	*target;
	long	best_match;

	while (a)
	{
		current_b = b;
		best_match = LONG_MIN;
		while (current_b)
		{
			if (current_b->nbr < a->nbr && current_b->nbr > best_match)
			{
				best_match = current_b->nbr;
				target = current_b;
			}
			current_b = current_b->next;
		}
		if (best_match == LONG_MIN)
			a->target = find_max(b);
		else
			a->target = target;
		a = a->next;
	}
}

static void	set_push_cost_a(t_stack *a, t_stack *b)
{
	int	len_a;
	int	len_b;

	len_a = stack_len(a);
	len_b = stack_len(b);
	while (a)
	{
		a->cost = a->index;
		if (!(a->above_median))
			a->cost = len_a - a->index;
		if (a->target->above_median)
			a->cost += a->target->index;
		else if (!(a->target->above_median))
			a->cost += len_b - a->target->index;
		a = a->next;
	}
}

static void	set_cheapest(t_stack *stack)
{
	long	cheapest_cost;
	t_stack	*cheapest_node;

	if (!stack)
		return ;
	cheapest_cost = LONG_MAX;
	while (stack)
	{
		if (stack->cost < cheapest_cost)
		{
			cheapest_cost = stack->cost;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	cheapest_node->cheapest = true;
}

void	init_a(t_stack *a, t_stack *b)
{
	set_index(a);
	set_index(b);
	set_target_a(a, b);
	set_push_cost_a(a, b);
	set_cheapest(a);
}