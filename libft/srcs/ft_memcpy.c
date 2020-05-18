/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: event <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 13:07:20 by event             #+#    #+#             */
/*   Updated: 2019/06/10 09:58:28 by ldu-pree         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*ptr;
	char	*ptr2;
	size_t	i;

	ptr = dst;
	ptr2 = (char *)src;
	i = -1;
	if (ptr == '\0' && ptr2 == '\0')
		return (dst);
	while (++i < n)
		*(ptr + i) = *(ptr2 + i);
	return (dst);
}
