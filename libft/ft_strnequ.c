/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <lmarques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/05 05:04:27 by lmarques          #+#    #+#             */
/*   Updated: 2016/09/20 14:42:12 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strnequ(const char *s1, const char *s2, int n)
{
	int count;

	count = 0;
	if (n == 0)
		return (1);
	if (!s1 || !s2)
		return (0);
	while (s1[count] && s2[count] && s1[count] == s2[count] && count < n)
		count++;
	if (count != n && s1[count] != s2[count])
		return (0);
	else
		return (1);
}
