/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesroble <jesroble@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 18:14:44 by jesroble          #+#    #+#             */
/*   Updated: 2024/03/19 14:45:16 by jesroble         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	move_to_b(t_stack **a, t_stack **b)
{
	t_stack	*cheapest_node;

	cheapest_node = get_cheapest(*a);
	if (cheapest_node->above_median && cheapest_node->target->above_median)
		r_both(a, b, cheapest_node);
	else if (!cheapest_node->above_median
		&& !cheapest_node->target->above_median)
		rr_both(a, b, cheapest_node);
	prep_4_push(a, cheapest_node, 'a');
	prep_4_push(b, cheapest_node->target, 'b');
	pb(a, b, true);
}

static void	move_to_a(t_stack **a, t_stack **b)
{
	prep_4_push(a, (*b)->target, 'a');
	pa(a, b, true);
}

static void	min_on_top(t_stack **a)
{
	if (!a)
		return ;
	while ((*a)->nbr != find_min(*a)->nbr)
	{
		if ((find_min(*a)->above_median))
			ra(a, true);
		else
			rra(a, true);
	}
}

void	turk_algorithm(t_stack **a, t_stack **b)
{
	int	len;

	len = stack_len(*a);
	if (len-- > 3 && !stack_sorted(*a))
	{
		pb(a, b, true);
	}
	if (len-- > 3 && !stack_sorted(*a))
	{
		pb(a, b, true);
	}
	while (len-- > 3 && !stack_sorted(*a))
	{
		init_a(*a, *b);
		move_to_b(a, b);
	}
	sort_three(a);
	while (*b)
	{
		init_b(*a, *b);
		move_to_a(a, b);
	}
	set_index(*a);
	min_on_top(a);
}
