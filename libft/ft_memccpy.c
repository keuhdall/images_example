/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <lmarques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/06 18:01:30 by lmarques          #+#    #+#             */
/*   Updated: 2016/09/03 21:41:04 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char	*str_src;
	char	*str_dst;
	size_t	count;

	str_src = (char *)src;
	str_dst = (char *)dst;
	count = 0;
	while (count < n && str_src[count] != c)
	{
		str_dst[count] = str_src[count];
		count++;
	}
	if (count == n)
		return (0);
	str_dst[count] = str_src[count];
	return (dst + count + 1);
}
