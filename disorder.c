/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastiangranier <bastiangranier@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 10:02:17 by bgranier          #+#    #+#             */
/*   Updated: 2026/02/04 11:00:21 by bastiangran      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

float	compute_disorder(t_stack_node *a)
{
	int				bad;
	int				total;
	t_stack_node	*tmp;

	bad = 0;
	total = 0;
	tmp = a;
	while (tmp && tmp->next)
	{
		if (tmp->index > tmp->next->index)
			bad++;
		total++;
		tmp = tmp->next;
	}
	if (total == 0)
		return (0.0f);
	return ((float)bad / (float)total);
}

int	print_disorder(t_stack_node *a)
{
	double	disorderdouble;

	(int)(disorderdouble);
	disorderdouble = compute_disorder(a) * 10000;
	ft_printf("Disorder: %.2f%%\n", disorderdouble / 100);
	ft_printf(" %d.%d\n",
		(int)(disorderdouble / 1000), (int)(disorderdouble % 100)
		);
	return (0);
}