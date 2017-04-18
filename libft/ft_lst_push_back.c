/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_push_back.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 16:04:11 by lmarques          #+#    #+#             */
/*   Updated: 2016/11/03 17:15:46 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst_push_back(t_list **begin, t_list *list)
{
	t_list	*tmp;

	tmp = *begin;
	if (!tmp)
		*begin = list;
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = list;
	}
}
