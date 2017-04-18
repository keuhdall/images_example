/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 14:54:21 by lmarques          #+#    #+#             */
/*   Updated: 2017/01/27 18:29:42 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	ft_count_str(char **tab)
{
	int	count;

	count = -1;
	while (tab[++count])
		continue;
	return (count);
}

static int	ft_count_nb(char *str)
{
	int	count;
	int	count_nb;

	count = -1;
	count_nb = 0;
	while (str[++count])
	{
		if (ft_isdigit(str[count]))
			count_nb++;
	}
	return (count_nb);
}

double		ft_atof(const char *str)
{
	int		count;
	int		tmp1;
	double	tmp2;
	char	**tab;

	count = -1;
	tab = ft_strsplit(str, '.');
	if (ft_count_str(tab) < 2)
	{
		tmp2 = (double)ft_atoi(tab[0]);
		while (tab[++count])
			free(tab[count]);
		free(tab);
		return (tmp2);
	}
	tmp1 = ft_atoi(tab[0]);
	tmp2 = (double)((double)ft_atoi(tab[1]) / ft_pow(10, ft_count_nb(tab[1])));
	tmp2 += (double)tmp1;
	while (tab[++count])
		free(tab[count]);
	free(tab);
	return (tmp2);
}
