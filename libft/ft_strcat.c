/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <lmarques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/08 02:50:34 by lmarques          #+#    #+#             */
/*   Updated: 2016/08/27 00:18:23 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	int	count;
	int	s1_len;

	count = 0;
	s1_len = ft_strlen(s1);
	while (s2[count])
	{
		s1[s1_len + count] = s2[count];
		count++;
	}
	s1[s1_len + count] = '\0';
	return (s1);
}
