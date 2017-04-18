/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <lmarques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/08 02:34:36 by lmarques          #+#    #+#             */
/*   Updated: 2016/09/04 18:18:48 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	count;

	count = ft_strlen(s) - 1;
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[count])
	{
		if (s[count] == (char)c)
			return ((char *)&s[count]);
		count--;
	}
	return (0);
}
