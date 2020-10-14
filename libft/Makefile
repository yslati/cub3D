# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yslati <yslati@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/21 17:36:56 by aaqlzim           #+#    #+#              #
#    Updated: 2020/02/22 20:06:19 by yslati           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_bzero.c ft_strdup.c ft_atoi.c ft_strcmp.c ft_putstr_fd.c \
	  ft_strlen.c ft_strlcat.c ft_strchr.c ft_putchar_fd.c \
	  ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c 
OBJ = $(SRC:.c=.o)

SRC_BONUS = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c\
			ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c
OBJ_BONUS = $(SRC_BONUS:.c=.o)

FLAGS = -Wall -Wextra -Werror

CC = gcc

all : $(NAME)

bonus : all $(OBJ_BONUS)
	@ar rcs $(NAME) $(OBJ_BONUS)

$(NAME) : $(OBJ)
	@ar rcs $(NAME) $(OBJ)

%.o : %.c
	@$(CC) $(FLAGS) -c $<

clean:
	@rm -rf *.o

fclean: clean
	@rm -rf $(NAME)

re: fclean all
