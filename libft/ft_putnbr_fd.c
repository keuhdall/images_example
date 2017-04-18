/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <lmarques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/30 22:47:16 by lmarques          #+#    #+#             */
/*   Updated: 2016/10/08 16:33:07 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int nb, int fd)
{
	long int	long_nb;

	long_nb = nb;
	if (long_nb < 0)
	{
		long_nb = -long_nb;
		ft_putchar_fd('-', fd);
	}
	if (long_nb > 9)
		ft_putnbr_fd(long_nb / 10, fd);
	ft_putchar_fd(long_nb % 10 + '0', fd);
}
