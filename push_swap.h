/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesroble <jesroble@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 12:47:14 by jesroble          #+#    #+#             */
/*   Updated: 2024/06/02 17:14:43 by jesroble         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdbool.h>
# include <limits.h>
# include "push_swap.h"
# include "./libft/libft.h"
# include "./printf/ft_printf.h"

typedef struct s_stack
{
	int				nbr;
	int				index;
	int				cost;
	bool			above_median;
	bool			cheapest;
	struct s_stack	*target;
	struct s_stack	*prev;
	struct s_stack	*next;
}	t_stack;

//push swap
int			main(int argc, char **argv);
char		**ft_split(char *s, char c);

//stack_inits
void		ft_init_a(t_stack **a, char **argv);
t_stack		*get_cheapest(t_stack *a);
void		prep_4_push(t_stack **stack, t_stack *top, char name);

//errors
bool		syntax_error(char *str);
bool		repetition_error(t_stack *a, int n);
void		free_stack(t_stack **stack);
void		ft_free(t_stack **a);
void		*free_split(char **split);
void		ft_exit(char **arg);

//utils
bool		stack_sorted(t_stack *stack);
t_stack		*find_last(t_stack *stack);
int			stack_len(t_stack *stack);
t_stack		*find_min(t_stack *stack);
t_stack		*find_max(t_stack *stack);

//orders
void		sa(t_stack **a, bool print);
void		sb(t_stack **b, bool print);
void		ss(t_stack **a, t_stack **b, bool print);
void		pa(t_stack **a, t_stack **b, bool print);
void		pb(t_stack **a, t_stack **b, bool print);
void		ra(t_stack **a, bool print);
void		rb(t_stack **b, bool print);
void		rr(t_stack **a, t_stack **b, bool print);
void		r_both(t_stack **a, t_stack **b, t_stack *cheapest);
void		rra(t_stack **a, bool print);
void		rrb(t_stack **b, bool print);
void		rrr(t_stack **a, t_stack **b, bool print);
void		rr_both(t_stack **a, t_stack **b, t_stack *cheapest);
void		sort_three(t_stack **a);
void		turk_algorithm(t_stack **a, t_stack **b);

//init
void		init_a(t_stack *a, t_stack *b);
void		set_index(t_stack *stack);
void		init_b(t_stack *a, t_stack *b);

#endif