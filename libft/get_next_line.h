/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <lmarques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 23:38:03 by lmarques          #+#    #+#             */
/*   Updated: 2017/01/07 19:12:38 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 1

# include "./libft.h"
# include <fcntl.h>

typedef struct		s_data
{
	int				fd;
	char			*content;
	struct s_data	*next;
}					t_data;

typedef struct		s_lst
{
	char			*content;
	int				fd;
	struct s_lst	*next;
}					t_lst;

t_data				*ft_manage_fd(t_data **tmp, int fd);
int					ft_parse_content(char **line, t_data *tmp);
int					ft_read(char **line, t_data *current);
void				ft_lst_push_back_gnl(t_lst **begin_list, int fd);
int					get_next_line(int const fd, char **line);

#endif
