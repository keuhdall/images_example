/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <lmarques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/05 05:01:21 by lmarques          #+#    #+#             */
/*   Updated: 2016/09/09 03:40:18 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strequ(const char *s1, const char *s2)
{
	int	count;

	count = 0;
	if (!s1 || !s2)
		return (0);
	while (s1[count] && s2[count] && s1[count] == s2[count])
		count++;
	if (s1[count] != s2[count])
		return (0);
	else
		return (1);
}
