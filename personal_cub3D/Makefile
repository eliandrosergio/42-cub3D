# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: efaustin <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/12 12:49:44 by efaustin          #+#    #+#              #
#    Updated: 2025/03/20 21:19:15 by efaustin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= 	cub3D
CC			= 	cc
CFLAGS		= 	-Wall -Wextra -Werror -g3
RM			= 	rm -rf

LIBFT_PATH	= 	libft/
LIBFT_NAME	= 	libft.a
LIBFT		= 	$(LIBFT_PATH)$(LIBFT_NAME)

MLXFLAGS	= 	-lXext -lX11 -lm
MLX_PATH	= 	minilibx-linux/
MLX_NAME	= 	libmlx.a
MLX			= 	$(MLX_PATH)$(MLX_NAME)

INC			= 	-I inc/\
				-I libft/\
				-I minilibx-linux/

SRC_PATH	= 	src/
SRC_FILES	=	$(SRC_PATH)main.c \
				$(SRC_PATH)check/check_args.c \
				$(SRC_PATH)check/check_grid.c \
				$(SRC_PATH)check/check_map.c \
				$(SRC_PATH)check/check_texture.c \
				$(SRC_PATH)check/check_utils.c \
				$(SRC_PATH)gameplay/gameplay.c \
				$(SRC_PATH)gameplay/move_check.c \
				$(SRC_PATH)gameplay/move.c \
				$(SRC_PATH)init/init_utils.c \
				$(SRC_PATH)init/init.c \
				$(SRC_PATH)parser/parser_2.c \
				$(SRC_PATH)parser/parser_utils.c \
				$(SRC_PATH)parser/parser.c \
				$(SRC_PATH)render/draw_ceiling_and_floor.c \
				$(SRC_PATH)render/draw_raycasting.c \
				$(SRC_PATH)render/raycasting.c \
				$(SRC_PATH)render/render_utils.c \
				$(SRC_PATH)render/sprites.c \
				$(SRC_PATH)utils/cleanup.c \
				$(SRC_PATH)utils/utils.c

OBJ_PATH	= 	obj/
OBJ_FILES	= 	$(SRC_FILES:$(SRC_PATH)%.c=$(OBJ_PATH)%.o)

all: $(MLX) $(LIBFT) $(NAME)

$(NAME): $(OBJ_FILES)
	$(CC) $(CFLAGS) $(OBJ_FILES) -o $(NAME) $(INC) $(LIBFT) $(MLX) $(MLXFLAGS)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@ $(INC)

$(LIBFT):
	make -C $(LIBFT_PATH)

$(MLX):
	make -C $(MLX_PATH)

clean:
	make clean -C $(LIBFT_PATH)
	make clean -C $(MLX_PATH)
	$(RM) $(OBJ_PATH)

fclean: clean
	make fclean -C $(LIBFT_PATH)
	$(RM) $(NAME)

re: fclean all
