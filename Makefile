# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: novsiann <novsiann@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/19 13:35:40 by novsiann          #+#    #+#              #
#    Updated: 2023/11/25 14:46:53 by novsiann         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = main.c \
       exit.c \
       init_map.c \
       map_errors.c \
       map.c \
       pic_utils.c \
       split_utils.c \
       color_trgb.c \
       fill_map.c \
       utils.c \
       textures.c \
       raycasting.c \
       raycasting2.c \
       keys.c \
       keys2.c \
       rotate.c

NAME = cub3d

LIBFT = includes/libft/
MLX = mlx/
LIBS = -lm -L$(MLX) -lmlx -framework OpenGL -framework AppKit
SRCS_DIR = srcs/

OBJS_DIR = objs/
OBJS = $(SRCS:.c=.o)
OBJECTS_PREFIXED = $(addprefix $(OBJS_DIR), $(OBJS))

CC = gcc -O3

CC_FLAGS = -Wall -Wextra -Werror -I $(MLX)

$(OBJS_DIR)%.o : $(SRCS_DIR)%.c includes/cub3d.h
		@mkdir -p $(OBJS_DIR)
		@gcc $(CC_FLAGS) -c $< -o $@

$(NAME): $(OBJECTS_PREFIXED)
		@make -C $(LIBFT)
		@$(CC) $(CC_FLAGS) -o $(NAME) $(OBJECTS_PREFIXED) -L$(MLX) -lmlx -Lincludes/libft -lft $(LIBS)

all: $(NAME)

clean:
		@rm -rf $(OBJS_DIR)
		@make fclean -C $(LIBFT)

fclean: clean
		@rm -rf $(NAME)

re: fclean all