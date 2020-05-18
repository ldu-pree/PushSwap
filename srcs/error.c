/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldu-pree <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 14:56:08 by ldu-pree          #+#    #+#             */
/*   Updated: 2019/09/12 10:40:29 by ldu-pree         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

int		check_num(int argc, char **argv)
{
	int i;
	int j;
	int len;

	i = 0;
	while (argv[i] && i < argc)
	{
		len = ft_strlen(argv[i]);
		j = 0;
		while (argv[i] && argv[i][j] && j < len)
		{
			if (j == 0 && argv[i][j] == '-' && len > 1)
				j++;
			if (!ft_isdigit(argv[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int		bigger_int(int argc, char **argv)
{
	int i;

	i = 0;
	while (i < argc)
	{
		if (ft_atoi(argv[i]) > MAX_INT || ft_atoi(argv[i]) < MIN_INT)
			return (0);
		i++;
	}
	return (1);
}

int		check_dup(int argc, char **argv)
{
	int		i;
	int		j;
	char	*num;

	i = 0;
	while (i < argc)
	{
		num = argv[i];
		j = i;
		while (j < argc)
		{
			if (j != i && ft_strcmp(num, argv[j]) == 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
