/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_flags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldu-pree <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 14:57:35 by ldu-pree          #+#    #+#             */
/*   Updated: 2019/09/09 14:57:35 by ldu-pree         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		check_visual(char **argv)
{
	if (ft_strcmp(argv[1], "-v") == 0)
		return (1);
	return (0);
}

void	del_argv(int argc, char **argv)
{
	int	i;

	i = 0;
	while (i < argc)
	{
		ft_strdel(&(argv[i]));
		i++;
	}
	free(argv);
}
