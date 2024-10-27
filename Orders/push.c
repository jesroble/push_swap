/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesroble <jesroble@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 17:57:02 by jesroble          #+#    #+#             */
/*   Updated: 2024/03/19 12:57:08 by jesroble         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	push(t_stack **dst, t_stack **src)
{
	t_stack	*pushed_node;

	if (!*src)
		return ;
	pushed_node = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	pushed_node->prev = NULL;
	if (*dst)
	{
		pushed_node->next = *dst;
		pushed_node->next->prev = pushed_node;
		*dst = pushed_node;
	}
	else if (!*dst)
	{
		*dst = pushed_node;
		pushed_node->next = NULL;
	}
}

void	pa(t_stack **a, t_stack **b, bool print)
{
	push(a, b);
	if (print)
		ft_printf("pa\n");
}

void	pb(t_stack **a, t_stack **b, bool print)
{
	push(b, a);
	if (print)
		ft_printf("pb\n");
}
