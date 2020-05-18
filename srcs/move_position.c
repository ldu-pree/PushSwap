/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_position.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldu-pree <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 14:57:56 by ldu-pree          #+#    #+#             */
/*   Updated: 2019/09/12 10:44:07 by ldu-pree         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		f_steps_ab(t_stack *head, int num, int *type)
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

void	f_move_to_a(t_stack **a, t_stack **b, int num)
{
	int i;
	int type;
	int steps;

	steps = f_steps_ab(*a, num, &type);
	i = 0;
	while (i < steps)
	{
		if (type == 1)
			rev_rotate_a(a);
		else
			rotate_a(a);
		i++;
	}
	push_a(b, a);
}

void	do_ss(t_stack **a, t_stack **b, int count, int type)
{
	if (type == 1)
	{
		while (count--)
			rev_rotate_both(a, b);
	}
	else if (type == 0)
	{
		while (count--)
			rotate_both(a, b);
	}
}

void	f_move_stack_a(t_stack **head, int type, int count)
{
	if (type == 1)
	{
		while (count--)
			rev_rotate_a(head);
	}
	else if (type == 0)
	{
		while (count--)
			rotate_a(head);
	}
}

int		get_pos_in_a(t_stack *head, int num)
{
	int index;

	index = get_closest(head, num);
	index = get_check_pos(head, num, index);
	return (index);
}

