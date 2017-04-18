/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <lmarques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/27 17:36:30 by lmarques          #+#    #+#             */
/*   Updated: 2016/11/02 18:06:49 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_realloc(char *str, int size)
{
	size_t	count;
	char	*newstr;

	count = 0;
	if (!str)
		return (NULL);
	newstr = (char *)malloc(sizeof(*newstr) * (ft_strlen(str) + size + 1));
	if (!newstr)
		return (NULL);
	while (count < (ft_strlen(str) + size) && str[count])
	{
		newstr[count] = str[count];
		count++;
	}
	newstr[count] = '\0';
	free(str);
	return (newstr);
}
