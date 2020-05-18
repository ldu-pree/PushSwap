/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldu-pree <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 14:59:01 by ldu-pree          #+#    #+#             */
/*   Updated: 2019/09/12 10:47:28 by ldu-pree         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		get_min(t_stack *a)
{
	int		num;
	t_stack	*tmp;

	num = MAX_INT;
	tmp = a;
	while (tmp)
	{
		if (tmp->value < num)
			num = tmp->value;
		tmp = tmp->next;
	}
	return (num);
}

int		get_steps_begin(t_stack *head, int index, int *type)
{
	int len;

	len = len_stack(head);
	if (index > len / 2)
	{
		*type = 1;
		return (len - index);
	}
	else
	{
		*type = 0;
		return (index);
	}
}

void	beginning(t_stack **a)
{
	int index;
	int type;
	int steps;

	type = -2;
	index = get_closest(*a, get_min(*a));
	steps = get_steps_begin(*a, index, &type);
	f_move_stack_a(a, type, steps);
}

int		is_sorted(t_stack *head)
{
	t_stack	*tmp;
	int		prev;

	tmp = head;
	prev = head->value;
	while (tmp)
	{
		prev = tmp->value;
		head = tmp;
		while (head)
		{
			if (prev > head->value)
				return (0);
			head = head->next;
		}
		tmp = tmp->next;
	}
	return (1);
}

void	solve_mini(t_stack **a)
{
	if ((*a)->value > (*a)->next->value)
	{
		if ((*a)->next->value < (*a)->next->next->value)
		{
			if ((*a)->next->next->value < (*a)->value)
				rotate_a(a);
			else
				swap_a(a);
		}
		else
			swap_a(a);
	}
	else
	{
		if ((*a)->value > (*a)->next->next->value)
			rev_rotate_a(a);
		else
		{
			rotate_a(a);
			swap_a(a);
		}
	}
	beginning(a);
}
