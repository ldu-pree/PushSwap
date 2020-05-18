/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldu-pree <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 14:55:43 by ldu-pree          #+#    #+#             */
/*   Updated: 2019/09/12 10:39:15 by ldu-pree         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_a(t_stack **head_b, t_stack **head_a)
{
	t_stack *tmp;

	if (!head_b || !(*head_b))
		return ;
	tmp = (*head_b)->next;
	(*head_b)->next = *head_a;
	*head_a = *head_b;
	*head_b = tmp;
	ft_putstr("pa\n");
}

void	push_b(t_stack **head_b, t_stack **head_a)
{
	t_stack *tmp;

	if (!head_a || !(*head_a))
		return ;
	tmp = (*head_a)->next;
	(*head_a)->next = *head_b;
	*head_b = *head_a;
	*head_a = tmp;
	ft_putstr("pb\n");
}
