/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <lmarques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/04 05:16:39 by lmarques          #+#    #+#             */
/*   Updated: 2016/10/09 02:46:26 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		count;
	char	*str2;

	count = 0;
	str2 = NULL;
	str2 = (char *)malloc(sizeof(char) * ft_strlen(s1) + 1);
	if (str2)
	{
		while (s1[count])
		{
			str2[count] = s1[count];
			count++;
		}
		str2[count] = '\0';
	}
	return (str2);
}
