/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_epur_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <lmarques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 21:25:14 by lmarques          #+#    #+#             */
/*   Updated: 2016/11/24 21:34:21 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_spaces(char *str)
{
	int	count;
	int	count_spaces;

	count = 0;
	count_spaces = 0;
	while (str[count])
	{
		if (str[count] == ' ')
		{
			count++;
			while (count < (int)ft_strlen(str) && str[count] == ' ')
			{
				count++;
				count_spaces++;
			}
		}
		count++;
	}
	return (count_spaces);
}

char		*ft_epur_str(char *str)
{
	int		count;
	int		count_str;
	char	*str_new;

	count = 0;
	count_str = 0;
	str_new = ft_strnew(ft_strlen(str) - ft_count_spaces(str));
	while (str[count_str])
	{
		if (str[count_str] == ' ')
		{
			str_new[count] = str[count_str];
			count++;
			count_str++;
			while (str[count_str] == ' ')
				count_str++;
		}
		str_new[count] = str[count_str];
		count++;
		count_str++;
	}
	return (str_new);
}
