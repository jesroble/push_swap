/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesroble <jesroble@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 12:56:15 by jesroble          #+#    #+#             */
/*   Updated: 2024/06/02 17:23:16 by jesroble         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_all(char **argv, t_stack **a, t_stack **b)
{
	free_stack(b);
	free_stack(a);
	free_split(argv);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc < 2 || (argc == 2 && !argv[1][0]))
		ft_exit(argv);
	else if (argc == 2)
		argv = ft_split(argv[1], ' ');
	else
		argv = argv + 1;
	if (argv[0] == NULL)
		exit (0);
	ft_init_a(&a, argv);
	if (!stack_sorted(a))
	{
		if (stack_len(a) == 2)
			sa(&a, true);
		else if (stack_len(a) == 3)
			sort_three(&a);
		else
			turk_algorithm(&a, &b);
	}
	free_all(argv, &a, &b);
	return (0);
}
