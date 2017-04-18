/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 17:39:03 by lmarques          #+#    #+#             */
/*   Updated: 2016/11/03 17:43:47 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	long int	long_nb;
	int			count;

	long_nb = nb;
	count = 1;
	while (count * count <= long_nb)
		count++;
	count--;
	if ((count * count) != long_nb)
		return (0);
	return (count);
}
