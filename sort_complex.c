/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgranier <bgranier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 13:22:57 by bgranier          #+#    #+#             */
/*   Updated: 2026/02/13 10:03:09 by bgranier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int	get_max_bits(t_stack_node **stack)
{
	t_stack_node	*head;
	int		max_bits;
	int		max;

	head = *stack;
	max = head->index;
	max_bits = 0;
	while (head)
	{
		if (head->index > max)
			max = head->index;
		head = head->next;
	}
	while ((max >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

int	is_sorted(t_stack_node **stack)
{
	t_stack_node	*current;

	if (!stack || !*stack)
		return (1);
	current = *stack;
	while (current->next)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}

void	index_stack(t_stack_node **stack)
{
	t_stack_node	*current;
	t_stack_node	*compare;
	int		index;

	current = *stack;
	while (current)
	{
		index = 0;
		compare = *stack;
		while (compare)
		{
			if (current->value > compare->value)
				index++;
			compare = compare->next;
		}
		current->index = index;
		current = current->next;
	}
}

void	sort_complex(t_stack_node **stack_a, t_stack_node **stack_b, t_ctrl *number_op)
{
	t_stack_node	*head_a;
	int		current_number;
	int		current_bit;
	int		stack_size;
	int		max_bits;

	if (is_sorted(stack_a))
		return ;
	index_stack(stack_a);
	current_bit = 0;
	head_a = *stack_a;
	stack_size = ft_lstsize(*stack_a);
	max_bits = get_max_bits(stack_a);
	while (current_bit < max_bits)
	{
		current_number = 0;
		while (current_number++ < stack_size)
		{
			head_a = *stack_a;
			if (((head_a->index >> current_bit) & 1) == 1)
				ra(stack_a, number_op);
			else
				pb(stack_a, stack_b, number_op);
		}
		while (ft_lstsize(*stack_b) != 0)
			pa(stack_b, stack_a, number_op);
		current_bit++;
	}
}



/* void	sort_complex(t_stack_node **a, t_stack_node **b, t_ctrl *c)
{
	int	max_bits;
	int	i;
	int	j;
	int	size;

	size = stack_size(*a);
	max_bits = 0;
	while ((size - 1) >> max_bits)
		max_bits++;
	i = 0;
	while (i < max_bits)

void	index_stack(t_stack_node **stack)
{
	t_stack_node	*current;
	t_stack_node	*compare;
	int		index;

	current = *stack;
	while (current)
	{
		index = 0;
		compare = *stack;

	{
		j = 0;
		while (j < size)
		{
			if (((*a)->index >> i) & 1)
				ra(a, c);
			else
				pb(a, b, c);
			j++;
		}
		while (*b)
			pa(a, b, c);
		i++;
	}
} */
