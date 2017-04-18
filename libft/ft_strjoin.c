/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <lmarques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/27 19:17:33 by lmarques          #+#    #+#             */
/*   Updated: 2016/11/21 14:40:01 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;

	if (!((s1 && s2) && (str = ft_strnew((ft_strlen(s1) + ft_strlen(s2)) + 1))))
		return (NULL);
	ft_strcat(ft_strcpy(str, s1), s2);
	return (str);
}
