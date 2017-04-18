/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <lmarques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/08 05:16:23 by lmarques          #+#    #+#             */
/*   Updated: 2016/09/20 14:40:14 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl(char const *s)
{
	int	count;

	count = 0;
	if (!s)
		return ;
	while (s[count])
	{
		write(1, &s[count], 1);
		count++;
	}
	write(1, "\n", 1);
}
