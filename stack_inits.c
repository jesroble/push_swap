/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_inits.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesroble <jesroble@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 19:07:30 by jesroble          #+#    #+#             */
/*   Updated: 2024/04/14 20:08:03 by jesroble         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long	ft_atol(char *str)
{
	int	result;
	int	sign;

	result = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (result * sign);
}

static void	append_node(t_stack **stack, int n)
{
	t_stack	*newnode;
	t_stack	*last;

	if (!stack)
		return ;
	newnode = malloc(sizeof(t_stack));
	if (!newnode)
		return ;
	newnode->next = NULL;
	newnode->nbr = n;
	if (!(*stack))
	{
		*stack = newnode;
		newnode->prev = NULL;
	}
	else
	{
		last = find_last(*stack);
		last->next = newnode;
		newnode->prev = last;
	}
}

t_stack	*get_cheapest(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

void	prep_4_push(t_stack **stack, t_stack *top, char name)
{
	if (!stack || !top)
		return ;
	while (*stack != top)
	{
		if (name == 'a')
		{
			if (top->above_median)
				ra(stack, true);
			else
				rra(stack, true);
		}
		if (name == 'b')
		{
			if (top->above_median)
				rb(stack, true);
			else
				rrb(stack, true);
		}
	}
}

//check for errors in the inputs and append them to the stack a
void	ft_init_a(t_stack **a, char **argv)
{
	int		i;
	long	n;

	i = 0;
	while (argv[i] != NULL)
	{
		if (syntax_error(argv[i]))
			ft_free(a);
		n = ft_atol(argv[i]);
		if (n < INT_MIN || n > INT_MAX)
			ft_free(a);
		if (repetition_error(*a, (int)n))
			ft_free(a);
		append_node(a, (int)n);
		i++;
	}
}
