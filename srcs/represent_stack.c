/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   represent_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldu-pree <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 14:58:49 by ldu-pree          #+#    #+#             */
/*   Updated: 2019/09/12 10:46:56 by ldu-pree         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print_stack(t_stack *stack, t_stack *stack_b)
{
	ft_putstr("\n------------\n");
	while (stack || stack_b)
	{
		if (!stack)
		{
			print_b(&stack_b, stack_b->value);
		}
		else if (!stack_b)
		{
			print_a(&stack, stack->value);
		}
		else
			print_all(&stack, &stack_b);
	}
	ft_putstr("|\t|\n");
	ft_putstr("A\tB\n");
	ft_putstr("------------\n");
}

int		len_stack(t_stack *head)
{
	int	len;

	len = 0;
	while (head)
	{
		head = head->next;
		len++;
	}
	return (len);
}

t_stack	*create_stack_from_arg(int argc, char **argv, int flag)
{
	t_stack	*head;
	int		i;

	argc = 0;
	if (!flag)
		argv = ft_strsplit(argv[1], ' ');
	else
		argv = ft_strsplit(argv[2], ' ');
	while (argv[argc])
		argc++;
	head = create_stack(argc, argv, 1);
	i = 0;
	while (i < argc)
	{
		ft_strdel(&(argv[i]));
		i++;
	}
	free(argv);
	return (head);
}

t_stack	*load_stack(int argc, char **argv)
{
	if (argc == 2)
		return (create_stack_from_arg(argc, argv, 0));
	else if (argc == 3 && check_visual(argv))
		return (create_stack_from_arg(argc, argv, 1));
	else if (check_visual(argv) && argc > 3)
	{
		argv += 2;
		argc -= 2;
		return (create_stack(argc, argv, 1));
	}
	else
		return (create_stack(--argc, ++argv, 1));
}

t_stack	*create_stack(int argc, char **argv, int type)
{
	int		i;
	t_stack	*head;
	t_stack	*prev;
	t_stack	*new;

	if (check_num(argc, argv) && check_dup(argc, argv)
		&& bigger_int(argc, argv) && argv[0])
	{
		prev = stnew(ft_atoi(argv[type ? 0 : 1]));
		head = prev;
		i = type ? 1 : 2;
		while (i < argc)
		{
			new = stnew(ft_atoi(argv[i]));
			prev->next = new;
			prev = new;
			i++;
		}
		return (head);
	}
	return (NULL);
}
