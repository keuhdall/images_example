/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <lmarques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/08 05:08:38 by lmarques          #+#    #+#             */
/*   Updated: 2016/09/20 14:40:29 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr(char const *s)
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
}
