# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yslati <yslati@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/13 20:19:58 by aaqlzim           #+#    #+#              #
#    Updated: 2020/02/27 12:38:28 by yslati           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Wextra -Werror

NAME = cub3D

NAME_A = cub3d.a

LIBFT = ./libft

LIBFT_A = ./libft/libft.a

SRC = 	src/check_footer_map.c \
		src/check_head_map.c \
		src/design_game.c \
		src/drawing.c \
		src/get_next_line_utils.c \
		src/get_next_line.c \
		src/initialisation_all.c \
		src/keys.c \
		src/movement.c \
		src/pars_map.c \
		src/pars_tools.c \
		src/rotation.c \
		src/save.c \
		src/sprite_tools.c \
		src/sprite.c \
		src/texture_tools.c \
		src/texture.c \
		src/main.c

OBJ = ${SRC:.c=.o}

HEADERS = ./include/cube3d.h

all : $(NAME)

%.o : %.c
	
	@$(CC) -c $< -o $@

$(LIBFT_A) :
	@make -C $(LIBFT)
	
$(NAME):	$(OBJ) $(LIBFT_A)
	@ar rc $(NAME_A) $(OBJ)
	@$(CC) $(CFLAGS) $(NAME_A) $(LIBFT_A) -lmlx -framework OpenGL -framework AppKit -o ${NAME}
	@echo 'SUCCESS'

clean :
	@rm -rf $(OBJ)
	@rm -rf $(LIBFT)/*.o

fclean : clean
	@rm -f $(NAME) rm -f $(NAME_A) $(LIBFT_A)

re : fclean all