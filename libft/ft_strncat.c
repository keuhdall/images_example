/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <lmarques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/08 04:04:40 by lmarques          #+#    #+#             */
/*   Updated: 2016/09/02 17:42:40 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	count;
	int		s1_len;

	count = 0;
	s1_len = ft_strlen(s1);
	while (s2[count] && count < n)
	{
		s1[s1_len + count] = s2[count];
		count++;
	}
	s1[s1_len + count] = '\0';
	return (s1);
}
