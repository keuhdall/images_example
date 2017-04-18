/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <lmarques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/08 05:21:53 by lmarques          #+#    #+#             */
/*   Updated: 2016/08/08 05:30:30 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	long int	long_n;

	long_n = n;
	if (long_n < 0)
	{
		ft_putchar('-');
		long_n = -long_n;
	}
	if (long_n > 9)
		ft_putnbr(long_n / 10);
	ft_putchar(long_n % 10 + '0');
}
