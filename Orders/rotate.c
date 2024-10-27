/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesroble <jesroble@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 16:42:47 by jesroble          #+#    #+#             */
/*   Updated: 2024/03/19 12:56:40 by jesroble         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//put the first nbr at the end of the stack
static void	rotate(t_stack **list)
{
	t_stack	*last;

	if (stack_len(*list) <= 1)
		return ;
	last = find_last(*list);
	last->next = *list;
	*list = (*list)->next;
	(*list)->prev = NULL;
	last->next->prev = last;
	last->next->next = NULL;
}

void	ra(t_stack **a, bool print)
{
	rotate(a);
	if (print)
		ft_printf("ra\n");
}

void	rb(t_stack **b, bool print)
{
	rotate(b);
	if (print)
		ft_printf("rb\n");
}

void	rr(t_stack **a, t_stack **b, bool print)
{
	rotate(a);
	rotate(b);
	if (print)
		ft_printf("rr\n");
}

void	r_both(t_stack **a, t_stack **b, t_stack *cheapest)
{
	while (*a != cheapest && *b != cheapest->target)
	{
		rr(a, b, true);
		set_index(*a);
		set_index(*b);
	}
}
