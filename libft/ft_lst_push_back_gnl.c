/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_push_back_gnl.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 15:01:30 by lmarques          #+#    #+#             */
/*   Updated: 2017/01/06 15:02:31 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_lst_push_back_gnl(t_lst **begin_list, int fd)
{
	t_lst	*list;
	t_lst	*list2;

	list = *begin_list;
	list2 = (t_lst *)malloc(sizeof(t_lst));
	if (!list2)
		return ;
	list2->fd = fd;
	list2->content = NULL;
	list2->next = NULL;
	if (!list)
	{
		list = list2;
		*begin_list = list;
	}
	else
	{
		while (list->next)
			list = list->next;
		list->next = list2;
	}
}
