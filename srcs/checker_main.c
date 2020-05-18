/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldu-pree <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 10:40:47 by ldu-pree          #+#    #+#             */
/*   Updated: 2019/09/12 10:41:50 by ldu-pree         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		read_cmd(t_stack **a, t_stack **b, char **cmd)
{
	int	command_id;

	if ((command_id = correct_phrase(*cmd)))
	{
		do_cmd(command_id, a, b);
		return (1);
	}
	else
	{
		stiter(*a, clean);
		stiter(*b, clean);
		return (0);
	}
}

void	if_three(int argc, char **argv)
{
	if (argv[argc == 3 ? 2 : 1][0] == 0)
		ft_error();
	argv = ft_strsplit(argv[argc == 3 ? 2 : 1], ' ');
	argc = 0;
	while (argv[argc])
		argc++;
	if (!check_num(argc, argv) || !check_dup(argc, argv)
		|| !bigger_int(argc, argv))
	{
		del_argv(argc, argv);
		ft_error();
	}
	del_argv(argc, argv);
}

void	check_in(int argc, char **argv, int *flag)
{
	if (argc == 1)
		exit(0);
	*flag = check_visual(argv);
	if (*flag && argc == 3)
		if_three(argc, argv);
	else if (argc == 2)
		if_three(argc, argv);
	else if (!(*flag) &&
		(!check_num(--argc, ++argv) || !check_dup(argc, argv)
		|| !bigger_int(argc, argv)))
		ft_error();
	else
	{
		argv += 2;
		argc -= 2;
		if (!check_num(argc, argv) || !check_dup(argc, argv)
			|| !bigger_int(argc, argv))
			ft_error();
	}
}

void	sorted_check(t_stack *a, t_stack *b)
{
	if (is_sorted(a) && len_stack(b) == 0)
	{
		ft_putstr("OK\n");
		stiter(a, clean);
	}
	else
	{
		ft_putstr("KO\n");
		stiter(a, clean);
		stiter(b, clean);
	}
}

int		main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	*command;
	int		flag;

	check_in(argc, argv, &flag);
	a = load_stack(argc, argv);
	b = NULL;
	if (flag)
		print_stack(a, b);
	while (get_next_line(0, &command) > 0)
	{
		if (!read_cmd(&a, &b, &command))
		{
			free(command);
			ft_error();
		}
		if (flag)
			print_stack(a, b);
		free(command);
	}
	sorted_check(a, b);
	return (0);
}
