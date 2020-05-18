/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldu-pree <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 14:58:42 by ldu-pree          #+#    #+#             */
/*   Updated: 2019/09/09 14:58:42 by ldu-pree         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int			main(int argc, char **argv)
{
	t_stack *head_a;
	t_stack *head_b;

	if (argc == 1)
		return (0);
	if (ft_strequ(argv[1], "-v"))
		ft_error();
	head_b = NULL;
	head_a = load_stack(argc, argv);
	if (!head_a)
		ft_error();
	if (is_sorted(head_a))
	{
		stiter(head_a, clean);
		return (0);
	}
	while (len_stack(head_a) > 3 && !is_sorted(head_a))
		push_b(&head_b, &head_a);
	if (len_stack(head_a) == 3 && !is_sorted(head_a))
		solve_mini(&head_a);
	while (head_b)
		solve(&head_a, &head_b);
	beginning(&head_a);
	stiter(head_a, clean);
}
