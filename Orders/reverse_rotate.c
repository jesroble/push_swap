/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesroble <jesroble@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 17:36:18 by jesroble          #+#    #+#             */
/*   Updated: 2024/03/19 12:57:01 by jesroble         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	rev_rotate(t_stack **list)
{
	t_stack	*last;
	t_stack	*second_last;

	if (stack_len(*list) <= 1)
		return ;
	last = find_last(*list);
	second_last = last->prev;
	second_last->next = NULL;
	last->next = *list;
	last->prev = NULL;
	(*list)->prev = last;
	*list = last;
}

void	rra(t_stack **a, bool print)
{
	rev_rotate(a);
	if (print)
		ft_printf("rra\n");
}

void	rrb(t_stack **b, bool print)
{
	rev_rotate(b);
	if (print)
		ft_printf("rrb\n");
}

void	rrr(t_stack **a, t_stack **b, bool print)
{
	rev_rotate(a);
	rev_rotate(b);
	if (print)
		ft_printf("rrr\n");
}

void	rr_both(t_stack **a, t_stack **b, t_stack *cheapest)
{
	while (*a != cheapest && *b != cheapest->target)
	{
		rrr(a, b, true);
		set_index(*a);
		set_index(*b);
	}
}
