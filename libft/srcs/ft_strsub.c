/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldu-pree <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 12:56:49 by ldu-pree          #+#    #+#             */
/*   Updated: 2019/06/11 12:56:51 by ldu-pree         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*new_str;
	size_t	i;

	i = 0;
	if (s)
	{
		new_str = (char*)malloc(sizeof(char) * len + 1);
		if (new_str == NULL)
			return (0);
		while (i < len)
			new_str[i++] = s[start++];
		new_str[i] = '\0';
		return (new_str);
	}
	return (0);
}
