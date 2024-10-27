/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesroble <jesroble@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 15:11:17 by jesroble          #+#    #+#             */
/*   Updated: 2024/03/26 20:45:33 by jesroble         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Check if the argument is not a number or has mor than one - or +
bool	syntax_error(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] == '\0')
		return (true);
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (true);
		i++;
	}
	return (false);
}

//Check if n appears more than once
bool	repetition_error(t_stack *a, int n)
{
	t_stack	*tempnode;
	int		count;

	count = 0;
	if (!a)
		return (false);
	tempnode = a;
	while (tempnode != NULL)
	{
		if (tempnode->nbr == n)
			count++;
		if (count >= 1)
			return (true);
		tempnode = tempnode->next;
	}
	return (false);
}

void	free_stack(t_stack **stack)
{
	t_stack	*current;
	t_stack	*temp;

	if (!stack)
		return ;
	current = *stack;
	while (current)
	{
		temp = current->next;
		current->nbr = 0;
		free(current);
		current = temp;
	}
	*stack = NULL;
}

void	ft_free(t_stack **a)
{
	free_stack(a);
	ft_putendl_fd("Error", 2);
	exit(1);
}

void	ft_exit(char **arg)
{
	arg[0][1] = '\0';
	ft_putendl_fd("Error", 2);
	exit(1);
}
