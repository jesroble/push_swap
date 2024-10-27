/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesroble <jesroble@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 15:38:06 by jesroble          #+#    #+#             */
/*   Updated: 2024/03/04 17:26:54 by jesroble         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	set_target_b(t_stack *b, t_stack *a)
{
	t_stack	*current_a;
	t_stack	*target;
	long	best_match;

	while (b)
	{
		current_a = a;
		best_match = LONG_MAX;
		while (current_a)
		{
			if (current_a->nbr > b->nbr && current_a->nbr < best_match)
			{
				best_match = current_a->nbr;
				target = current_a;
			}
			current_a = current_a->next;
		}
		if (best_match == LONG_MAX)
			b->target = find_min(a);
		else
			b->target = target;
		b = b->next;
	}
}

void	init_b(t_stack *a, t_stack *b)
{
	set_index(a);
	set_index(b);
	set_target_b(b, a);
}
