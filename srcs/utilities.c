/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldu-pree <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 14:55:57 by ldu-pree          #+#    #+#             */
/*   Updated: 2019/09/12 10:51:29 by ldu-pree         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	clean(t_stack *head)
{
	if (head)
		free(head);
}

t_stack	*stnew(int num)
{
	t_stack *new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->value = num;
	new->next = NULL;
	return (new);
}

void	stiter(t_stack *stack, void (*f)(t_stack *elem))
{
	t_stack	*next;
	t_stack	*current;

	if (stack && f)
	{
		next = stack->next;
		current = stack;
		while (current)
		{
			next = current->next;
			f(current);
			current = next;
		}
	}
}

void	print_a(t_stack **a, int num)
{
	char	*number;

	number = ft_itoa(num);
	ft_putstr(number);
	free(number);
	ft_putstr("\t");
	ft_putstr("\n");
	*a = (*a)->next;
}

void	print_b(t_stack **b, int num)
{
	char *number;

	number = ft_itoa(num);
	ft_putstr("\t");
	ft_putstr(number);
	free(number);
	ft_putstr("\n");
	*b = (*b)->next;
}

void	print_all(t_stack **a, t_stack **b)
{
	int		num_a;
	int		num_b;
	char	*number;

	num_a = (*a)->value;
	num_b = (*b)->value;
	number = ft_itoa(num_a);
	ft_putstr(number);
	free(number);
	ft_putstr("\t");
	number = ft_itoa(num_b);
	ft_putstr(number);
	free(number);
	ft_putstr("\n");
	*a = (*a)->next;
	*b = (*b)->next;
}
