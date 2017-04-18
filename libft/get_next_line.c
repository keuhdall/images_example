/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <lmarques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 23:22:24 by lmarques          #+#    #+#             */
/*   Updated: 2017/01/06 15:05:11 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_check_buff_2(char **line, char **content, int i)
{
	char	*dup;
	char	*tmp2;

	tmp2 = ft_strsub(*content, 0, i);
	*line = ft_strjoin(*line, tmp2);
	free(tmp2);
	dup = ft_strdup(*content + i + 1);
	free(*content);
	*content = dup;
	return (1);
}

int			ft_check_buff(char **line, char **content)
{
	int		i;
	char	*tmp;
	char	*tmp2;

	if (!*content)
		return (0);
	i = ft_strlen(*content);
	if ((tmp = ft_strchr(*content, '\n')))
		return (ft_check_buff_2(line, content, tmp - *content));
	else
	{
		tmp2 = *line;
		*line = ft_strjoin(*line, *content);
		free(tmp2);
		ft_strdel(content);
	}
	return (0);
}

static int	ft_reader_2(char **line, t_lst *lst, char *buff)
{
	char	*tmp;
	char	*tmp2;
	int		i;

	if ((tmp = ft_strchr(buff, '\n')))
	{
		i = tmp - buff;
		tmp2 = ft_strsub(buff, 0, i);
		tmp = *line;
		*line = ft_strjoin(*line, tmp2);
		free(tmp2);
		free(tmp);
		lst->content = ft_strdup(buff + i + 1);
		return (1);
	}
	else
	{
		tmp2 = *line;
		*line = ft_strjoin(*line, buff);
		free(tmp2);
	}
	return (0);
}

int			ft_reader(char **line, t_lst *lst)
{
	int		ret;
	char	buff[BUFF_SIZE + 1];

	while ((ret = read(lst->fd, buff, BUFF_SIZE)))
	{
		if (ret == -1)
			return (ret);
		buff[ret] = '\0';
		if (ft_reader_2(line, lst, (char *)buff))
			return (1);
	}
	if (ret == 0 && **line == '\0')
		return (0);
	else
		return (1);
}

int			get_next_line(int const fd, char **line)
{
	static t_lst	*begin_list = NULL;
	t_lst			*lst;
	char			tmp;

	if (!line || read(fd, &tmp, 0) == -1 || fd < 0)
		return (-1);
	if (*line)
		*line = NULL;
	*line = ft_strdup("");
	lst = begin_list;
	while (lst && lst->fd != fd)
		lst = lst->next;
	if (!lst)
	{
		ft_lst_push_back_gnl(&begin_list, fd);
		lst = begin_list;
		while (lst && lst->fd != fd)
			lst = lst->next;
	}
	else if (ft_check_buff(line, &(lst->content)))
		return (1);
	if (!begin_list)
		begin_list = lst;
	return (ft_reader(line, lst));
}
