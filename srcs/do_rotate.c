/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldu-pree <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 14:55:33 by ldu-pree          #+#    #+#             */
/*   Updated: 2019/09/12 10:40:15 by ldu-pree         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_rotate(t_stack **head)
{
	t_stack *tmp;

	if (!head || !(*head))
		return ;
	tmp = *head;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = *head;
	*head = (*head)->next;
	tmp->next->next = NULL;
}

void	rotate_a(t_stack **head)
{
	ft_rotate(head);
	ft_putstr("ra\n");
}

void	rotate_b(t_stack **head)
{
	ft_rotate(head);
	ft_putstr("rb\n");
}

void	rotate_both(t_stack **head_a, t_stack **head_b)
{
	ft_rotate(head_a);
	ft_rotate(head_b);
	ft_putstr("rr\n");
}

