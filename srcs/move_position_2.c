/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_position_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldu-pree <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 14:58:01 by ldu-pree          #+#    #+#             */
/*   Updated: 2019/09/12 10:42:21 by ldu-pree         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	f_move_stack_b(t_stack **head, int type, int count)
{
	if (type == 1)
	{
		while (count--)
			rev_rotate_b(head);
	}
	else if (type == 0)
	{
		while (count--)
			rotate_b(head);
	}
}

int		f_mix_steps(int sa, int sb)
{
	int mix;
	int more;

	if (sa >= sb)
	{
		more = sa - sb;
		mix = sa - more;
		return (mix);
	}
	else
	{
		more = sb - sa;
		mix = sb - more;
		return (mix);
	}
}

void	do_ab_steps(t_stack **a, t_stack **b, int num)
{
	int steps_b;
	int steps_a;
	int type_a;
	int type_b;
	int mix;

	type_a = -1;
	type_b = -2;
	steps_b = f_steps_ab(*b, num, &type_b);
	steps_a = f_steps_ab(*a, num, &type_a);
	if (type_a == type_b)
	{
		mix = f_mix_steps(steps_a, steps_b);
		do_ss(a, b, mix, type_a);
		f_move_stack_a(a, type_a, steps_a - mix);
		f_move_stack_b(b, type_b, steps_b - mix);
		push_a(b, a);
	}
	else
	{
		f_move_stack_a(a, type_a, steps_a);
		f_move_stack_b(b, type_b, steps_b);
		push_a(b, a);
	}
}

int		b_mix_steps(t_stack *head_a, t_stack *head_b)
{
	int		a_steps;
	int		tmp;
	int		total;
	int		index_b;
	t_stack	*h;

	a_steps = get_steps(head_a, head_b->value);
	total = a_steps;
	index_b = 0;
	h = head_b;
	while (head_b)
	{
		tmp = f_ab_steps(head_a, h, head_b->value);
		if (total > tmp)
		{
			total = tmp;
			index_b = get_pos_in_a(h, head_b->value);
		}
		head_b = head_b->next;
	}
	return (index_b);
}

void	f_move_ab(t_stack **a, t_stack **b)
{
	int index_b;

	index_b = b_mix_steps(*a, *b);
	do_ab_steps(a, b, get_num(*b, index_b));
}
