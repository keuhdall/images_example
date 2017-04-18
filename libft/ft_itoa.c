/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <lmarques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/27 21:36:58 by lmarques          #+#    #+#             */
/*   Updated: 2016/09/20 14:38:48 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_nb(int nb)
{
	int			count;
	long int	long_nb;

	count = 0;
	long_nb = nb;
	if (nb < 0)
	{
		long_nb = -nb;
		count++;
	}
	while (long_nb != long_nb % 10)
	{
		long_nb = (long_nb - long_nb % 10) / 10;
		count++;
	}
	count++;
	return (count);
}

char		*ft_itoa(int nb)
{
	char		*str;
	int			count;
	long int	long_nb;

	count = 0;
	long_nb = nb;
	str = (char *)malloc(sizeof(char) * (ft_count_nb(nb) + 1));
	if (!str)
		return (NULL);
	if (nb < 0)
	{
		str[0] = '-';
		long_nb *= -1;
	}
	while (count < (nb < 0 ? ft_count_nb(nb) - 1 : ft_count_nb(nb)))
	{
		str[ft_count_nb(nb) - count - 1] = (long_nb % 10) + '0';
		long_nb = (long_nb - long_nb % 10) / 10;
		count++;
	}
	str[ft_count_nb(nb)] = '\0';
	return (str);
}
