/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldu-pree <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 14:55:38 by ldu-pree          #+#    #+#             */
/*   Updated: 2019/09/12 10:50:31 by ldu-pree         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		get_steps(t_stack *head, int num)
{
	int index;
	int len;

	len = len_stack(head);
	index = get_pos_in_a(head, num);
	if (index > len / 2)
		return (len - index);
	else
		return (index);
}

int		get_steps_ab(t_stack *head, int num, int *type)
{
	int index;
	int len;

	len = len_stack(head);
	index = get_pos_in_a(head, num);
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

int		f_ab_steps(t_stack *a, t_stack *b, int num)
{
	int steps_b;
	int steps_a;
	int type_a;
	int type_b;
	int total;

	type_a = -1;
	type_b = -2;
	steps_b = f_steps_ab(b, num, &type_b);
	steps_a = f_steps_ab(a, num, &type_a);
	if (type_a == type_b)
	{
		total = steps_a >= steps_b ? steps_a : steps_b;
	}
	else
		total = steps_a + steps_b;
	return (total);
}

int		mix_steps(t_stack *head_a, t_stack *head_b)
{
	int		a_steps;
	int		tmp;
	int		total;
	t_stack	*head_b_fix;

	head_b_fix = head_b;
	a_steps = get_steps(head_a, head_b->value);
	total = a_steps;
	while (head_b)
	{
		tmp = f_ab_steps(head_a, head_b_fix, head_b->value);
		if (total > tmp)
			total = tmp;
		head_b = head_b->next;
	}
	return (total);
}

void	solve(t_stack **head_a, t_stack **head_b)
{
	int	steps_a;
	int	steps_a_b;

	steps_a = get_steps(*head_a, (*head_b)->value);
	steps_a_b = mix_steps(*head_a, *head_b);
	if (steps_a <= steps_a_b)
	{
		f_move_to_a(head_a, head_b, (*head_b)->value);
	}
	else
	{
		f_move_ab(head_a, head_b);
	}
}
