/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldu-pree <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 14:58:34 by ldu-pree          #+#    #+#             */
/*   Updated: 2019/09/12 10:44:46 by ldu-pree         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	get_num(t_stack *head, int index)
{
	int i;
	int num;

	i = 0;
	num = 0;
	while (head && i < index)
	{
		head = head->next;
		i++;
	}
	if (head)
		num = head->value;
	return (num);
}

int	get_check_pos(t_stack *head, int num, int index)
{
	int st_len;
	int new_index;

	new_index = index;
	st_len = len_stack(head);
	if (st_len == 0)
		return (new_index);
	if (index == st_len - 1)
	{
		if (num > get_num(head, index))
			new_index = 0;
		return (new_index);
	}
	else
	{
		if (num > get_num(head, index))
			new_index = index + 1;
		return (new_index);
	}
}

int	negative(int head, int num)
{
	int diff;

	diff = 0;
	if (head <= 0)
	{
		if (head <= num)
			diff = num - head;
		else
			diff = head - num;
	}
	else if (head > 0)
		diff = head - num;
	return (diff);
}

int	positive(int head, int num)
{
	int diff;

	diff = 0;
	if (head >= 0)
	{
		if (head <= num)
			diff = num - head;
		else
			diff = head - num;
	}
	else if (head < 0)
		diff = num - head;
	return (diff);
}

int	get_closest(t_stack *head, int num)
{
	int diff;
	int index;
	int tmp;

	diff = MAX_INT;
	index = 0;
	tmp = 0;
	while (head)
	{
		if (num <= 0 && diff > negative(head->value, num))
		{
			diff = negative(head->value, num);
			index = tmp;
		}
		else if (num > 0 && diff > positive(head->value, num))
		{
			diff = positive(head->value, num);
			index = tmp;
		}
		tmp++;
		head = head->next;
	}
	return (index);
}
