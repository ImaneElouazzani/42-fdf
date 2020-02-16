# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ielouazz <ielouazz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/15 12:39:55 by ielouazz          #+#    #+#              #
#    Updated: 2020/02/15 16:44:34 by ielouazz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
SRC = draw_line.c ft_hooks.c get_map_info.c main.c store_point.c 
OBJ = $(SRC:.c=.o)
LIBFT = libft/libft.a
CFLAGS = -Wall -Wextra -Werror
LDLIBS = -lm -lmlx -lft
LDFLAGS = -L./libft -framework Appkit -framework OpenGl
HEADER = fdf.h

all: $(LIBFT) $(NAME)

$(LIBFT):
	make -C libft

$(NAME): $(OBJ) $(HEADER)
	gcc $(OBJ) $(LDLIBS) $(LDFLAGS) -o fdf

%.o:%.c
	gcc -c $<

clean:
	make clean -C libft
	rm -f $(OBJ)
	
fclean: clean
	rm -f $(NAME)
	make fclean -C libft

re: fclean all	
