# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: efaustin <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/12 12:49:44 by efaustin          #+#    #+#              #
#    Updated: 2025/03/26 15:23:24 by efaustin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= 	cub3D
NAME_BONUS		= 	cub3D_bonus
CC				= 	cc
CFLAGS			= 	-Wall -Wextra -Werror -g3
RM				= 	rm -rf

LIBFT_PATH		= 	libft/
LIBFT_NAME		= 	libft.a
LIBFT			= 	$(LIBFT_PATH)$(LIBFT_NAME)

MLXFLAGS		= 	-lXext -lX11 -lm
MLX_PATH		= 	minilibx-linux/
MLX_NAME		= 	libmlx.a
MLX				= 	$(MLX_PATH)$(MLX_NAME)

INC				= 	-I inc/\
					-I libft/\
					-I minilibx-linux/

SRC_PATH		= 	src/
SRC_FILES		=	$(SRC_PATH)main.c \
					$(SRC_PATH)check/check_args.c \
					$(SRC_PATH)check/check_grid.c \
					$(SRC_PATH)check/check_map.c \
					$(SRC_PATH)check/check_tex_clr.c \
					$(SRC_PATH)check/check_utils.c \
					$(SRC_PATH)gameplay/gameplay.c \
					$(SRC_PATH)gameplay/move.c \
					$(SRC_PATH)init/init_utils.c \
					$(SRC_PATH)init/init.c \
					$(SRC_PATH)parser/parser_2.c \
					$(SRC_PATH)parser/parser_utils.c \
					$(SRC_PATH)parser/parser.c \
					$(SRC_PATH)render/draw_raycasting.c \
					$(SRC_PATH)render/raycasting.c \
					$(SRC_PATH)render/render.c \
					$(SRC_PATH)utils/cleanup.c \
					$(SRC_PATH)utils/color.c \
					$(SRC_PATH)utils/utils.c

SRC_PATH_BONUS	= 	bonus/
SRC_FILES_BONUS	=	$(SRC_PATH_BONUS)main_bonus.c \
					$(SRC_PATH_BONUS)check/check_args_bonus.c \
					$(SRC_PATH_BONUS)check/check_grid_bonus.c \
					$(SRC_PATH_BONUS)check/check_map_bonus.c \
					$(SRC_PATH_BONUS)check/check_tex_clr_bonus.c \
					$(SRC_PATH_BONUS)check/check_utils_bonus.c \
					$(SRC_PATH_BONUS)gameplay/gameplay_bonus.c \
					$(SRC_PATH_BONUS)gameplay/move_bonus.c \
					$(SRC_PATH_BONUS)init/init_bonus.c \
					$(SRC_PATH_BONUS)init/init_sprites_bonus.c \
					$(SRC_PATH_BONUS)parser/parser_2_bonus.c \
					$(SRC_PATH_BONUS)parser/parser_utils_bonus.c \
					$(SRC_PATH_BONUS)parser/parser_bonus.c \
					$(SRC_PATH_BONUS)render/draw_raycasting_bonus.c \
					$(SRC_PATH_BONUS)render/draw_sprites_bonus.c \
					$(SRC_PATH_BONUS)render/raycasting_bonus.c \
					$(SRC_PATH_BONUS)render/render_bonus.c \
					$(SRC_PATH_BONUS)utils/cleanup_bonus.c \
					$(SRC_PATH_BONUS)utils/color_bonus.c \
					$(SRC_PATH_BONUS)utils/utils_bonus.c

OBJ_PATH		= 	obj/
OBJ_FILES	= 	$(SRC_FILES:$(SRC_PATH)%.c=$(OBJ_PATH)%.o)

OBJ_PATH_BONUS	= 	obj_bonus/
OBJ_FILES_BONUS	= 	$(SRC_FILES_BONUS:$(SRC_PATH_BONUS)%.c=$(OBJ_PATH_BONUS)%.o)

all: $(MLX) $(LIBFT) $(NAME)

$(NAME): $(OBJ_FILES)
	$(CC) $(CFLAGS) $(OBJ_FILES) -o $(NAME) $(INC) $(LIBFT) $(MLX) $(MLXFLAGS)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@ $(INC)

$(OBJ_PATH_BONUS)%.o: $(SRC_PATH_BONUS)%.c
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
	$(RM) $(OBJ_PATH_BONUS)

fclean: clean
	make fclean -C $(LIBFT_PATH)
	$(RM) $(NAME)
	$(RM) $(NAME_BONUS)

bonus: $(MLX) $(LIBFT) $(OBJ_FILES_BONUS)
	$(CC) $(CFLAGS) $(OBJ_FILES_BONUS) -o $(NAME_BONUS) $(INC) $(LIBFT) $(MLX) $(MLXFLAGS)

re: fclean all
