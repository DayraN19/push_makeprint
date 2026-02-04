/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastiangranier <bastiangranier@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 13:02:27 by bgranier          #+#    #+#             */
/*   Updated: 2026/02/04 10:40:45 by bastiangran      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_bench(t_ctrl *c)
{
	ft_printf("\n========== BENCH ==========\n");
	ft_printf("Operations executed: %d\n", c->count_op);
	ft_printf("RA operations: %d\n", c->count_ra);
	ft_printf("RB operations: %d\n", c->count_rb);
	ft_printf("RR operations: %d\n", c->count_rr);
	ft_printf("RRA operations: %d\n", c->count_rra);
	ft_printf("RRB operations: %d\n", c->count_rrb);
	ft_printf("RRR operations: %d\n", c->count_rrr);
	ft_printf("PA operations: %d\n", c->count_pa);
	ft_printf("PB operations: %d\n", c->count_pb);
	ft_printf("SA operations: %d\n", c->count_sa);
	ft_printf("SB operations: %d\n", c->count_sb);
	ft_printf("SS operations: %d\n", c->count_ss);
	ft_printf("Stack A size: %d\n", c->size_a);
	ft_printf("Disorder measure: %.2f\n", c->count_disorder);
	ft_printf("Strategy used: %s", strategy_name(c->strategy));
	if (c->strategy == STRAT_ADAPTIVE)
	{
		ft_printf(" | %s | %s\n",
			strategy_name(c->executed_strategy),
			strategy_complexity(c->executed_strategy)
			);
	}
	else
		ft_printf(" | %s\n", strategy_complexity(c->strategy));
}

/* void	print_bench(t_ctrl *c)
{
	ft_printf(2, "\n========== BENCH ==========\n");
	ft_printf(2, "Operations executed: %d\n", c->count_op);
	ft_printf(2, "RA operations: %d\n", c->count_ra);
	ft_printf(2, "RB operations: %d\n", c->count_rb);
	ft_printf(2, "RR operations: %d\n", c->count_rr);
	ft_printf(2, "RRA operations: %d\n", c->count_rra);
	ft_printf(2, "RRB operations: %d\n", c->count_rrb);
	ft_printf(2, "RRR operations: %d\n", c->count_rrr);
	ft_printf(2, "PA operations: %d\n", c->count_pa);
	ft_printf(2, "PB operations: %d\n", c->count_pb);
	ft_printf(2, "SA operations: %d\n", c->count_sa);
	ft_printf(2, "SB operations: %d\n", c->count_sb);
	ft_printf(2, "SS operations: %d\n", c->count_ss);
	ft_printf(2, "Stack A size: %d\n", c->size_a);
	ft_printf(2, "Disorder measure: %.2f\n", c->count_disorder);
	ft_printf(2, "Strategy used: %s", strategy_name(c->strategy));
	if (c->strategy == STRAT_ADAPTIVE)
	{
		ft_printf(2, " | %s | %s\n",
			strategy_name(c->executed_strategy),
			strategy_complexity(c->executed_strategy)
			);
	}
	else
		ft_printf(2, " | %s\n", strategy_complexity(c->strategy));
} */
