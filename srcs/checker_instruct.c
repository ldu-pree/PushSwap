/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_instruct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldu-pree <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 14:57:43 by ldu-pree          #+#    #+#             */
/*   Updated: 2019/09/09 14:57:44 by ldu-pree         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		correct_phrase(char *op)
{
	if (ft_strcmp(op, "sa") == 0)
		return (1);
	else if (ft_strcmp(op, "sb") == 0)
		return (2);
	else if (ft_strcmp(op, "pa") == 0)
		return (3);
	else if (ft_strcmp(op, "pb") == 0)
		return (4);
	else if (ft_strcmp(op, "ra") == 0)
		return (5);
	else if (ft_strcmp(op, "rb") == 0)
		return (6);
	else if (ft_strcmp(op, "ss") == 0)
		return (7);
	else if (ft_strcmp(op, "rr") == 0)
		return (8);
	else if (ft_strcmp(op, "rrr") == 0)
		return (9);
	else if (ft_strcmp(op, "rra") == 0)
		return (10);
	else if (ft_strcmp(op, "rrb") == 0)
		return (11);
	else
		return (0);
}

void	do_cmd(int cmd, t_stack **a, t_stack **b)
{
	if (cmd == 1)
		ft_swap(a);
	else if (cmd == 2)
		ft_swap(b);
	else if (cmd == 7)
		do_ss_ch(a, b);
	else if (cmd == 3)
		do_pa(b, a);
	else if (cmd == 4)
		do_pb(b, a);
	else if (cmd == 5)
		ft_rotate(a);
	else if (cmd == 6)
		ft_rotate(b);
	else if (cmd == 8)
		do_rr(b, a);
	else if (cmd == 9)
		do_rrr(b, a);
	else if (cmd == 10)
		ft_rev_rotate(a);
	else if (cmd == 11)
		ft_rev_rotate(b);
}
