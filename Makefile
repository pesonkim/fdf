# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kpesonen <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/04 12:37:07 by kpesonen          #+#    #+#              #
#    Updated: 2020/08/19 19:56:38 by kpesonen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC_DIR = ./srcs/
SRC = error.c \
	  main.c \
	  parse.c \
	  init.c \
	  key_hooks.c \
	  mouse_hooks.c \
	  draw.c \
	  color.c \
	  project.c
SRCS = $(addprefix $(SRC_DIR), $(SRC))

OBJ_DIR = ./obj/
OBJ = $(SRC:.c=.o)
OBJS = $(addprefix $(OBJ_DIR), $(OBJ))

INC = fdf.h
INC_DIR = ./includes/
INCS = $(addprefix $(INC_DIR), $(INC))

LIB_DIR = ./libft/
LIB_INC = ./libft/includes

MLX_DIR = -L /usr/local/lib -lmlx 
MLX_LIB = -framework OpenGL -framework AppKit
MLX_INC = /usr/local/include

FLAGS = -Wall -Wextra -Werror -I$(INC_DIR) -I$(LIB_INC) -I$(MLX_INC)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJS)
	@ make -C $(LIB_DIR)
	@ gcc $(MLX_DIR) $(MLX_LIB) $(OBJS) -o $(NAME) -L $(LIB_DIR) -lft
	@ echo "fdf make done"

$(OBJ_DIR):
	@ mkdir -p $@ 

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(INCS)
	gcc $(FLAGS) -o $@ -c $<

clean:
	@ rm -f $(OBJS)
	@ rm -rf $(OBJ_DIR)
	@ make -C $(LIB_DIR) clean
	@ echo "fdf clean objs"
	
fclean: clean
	@ rm -f $(NAME)
	@ make -C $(LIB_DIR) fclean
	@ echo "fdf clean bin"

re: fclean all
