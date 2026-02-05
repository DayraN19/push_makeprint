/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_adaptive.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastiangranier <bastiangranier@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 13:17:22 by bgranier          #+#    #+#             */
/*   Updated: 2026/02/05 12:50:50 by bastiangran      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_strategy	choose_adaptive_strategy(t_stack_node *a, t_ctrl *c)
{
	float	disorder;

	disorder = compute_disorder_precise(a);
	c->count_disorder = disorder;
	if (disorder <= 3000)
		c->strategy = STRAT_SIMPLE;
	else if (disorder <= 6000)
		c->strategy = STRAT_MEDIUM;
	else
		c->strategy = STRAT_COMPLEX;
	return (c->strategy);
}

void	sort_adaptive(t_stack_node **a, t_stack_node **b, t_ctrl *c)
{
	if (!a || !*a || !c)
		return ;

	c->executed_strategy = choose_adaptive_strategy(*a, c);
	if (c->executed_strategy == STRAT_SIMPLE)
		sort_simple(a, b, c);
	else if (c->executed_strategy == STRAT_MEDIUM)
		sort_medium(a, b, c);
	else
		sort_complex(a, b, c);

	c->size_a = stack_size(*a);
	c->size_b = stack_size(*b);
}