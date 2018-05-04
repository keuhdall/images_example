#* ************************************************************************** *#
#*                                                                            *#
#*                                                        :::      ::::::::   *#
#*   Makefile                                           :+:      :+:    :+:   *#
#*                                                    +:+ +:+         +:+     *#
#*   By: lmarques <lmarques@student.42.fr>          +#+  +:+       +#+        *#
#*                                                +#+#+#+#+#+   +#+           *#
#*   Created: 2016/11/10 23:15:25 by lmarques          #+#    #+#             *#
#*   Updated: 2017/04/18 04:13:53 by lmarques         ###   ########.fr       *#
#*                                                                            *#
#* ************************************************************************** *#

NAME = example

SRC = example.c \


OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
		make -C minilibx
		mv minilibx/libmlx.a .
		gcc -Wall -g -Werror -Wextra -c $(SRC)
		gcc -Wall -g -Werror -Wextra -L. -lmlx -framework OpenGL -framework Appkit $(OBJ) -o $(NAME)

clean:
		make -C minilibx clean
		rm -rf $(OBJ) libft.a libmlx.a

fclean: clean
		make -C minilibx clean
		rm -rf $(NAME)

re : fclean all
