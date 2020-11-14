# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/25 15:17:11 by kkamashi          #+#    #+#              #
#    Updated: 2020/11/14 21:32:20 by kkamashi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

LIBS_DIR = ./libs
MODELS_DIR = ./srcs/models
VIEWS_DIR = ./srcs/views
CONTROLLERS_DIR = ./srcs/controllers
UTILITIES_DIR = ./srcs/utilities
PARSING_DIR = ./srcs/parsing_cub_file
BMP = ./srcs/bmp
RAYCASTING = ./srcs/raycasting

CC = gcc
CFLAGS = -Wall -Wextra -Werror
DEBUG = -g

SRCS = main.c \
	$(LIBS_DIR)/get_next_line/get_next_line.c \
	$(UTILITIES_DIR)/print_error_msg.c \
	$(UTILITIES_DIR)/init_cub_data.c \
	$(UTILITIES_DIR)/useful_funcs.c \
	$(UTILITIES_DIR)/validate_cub_file_utils.c \
	$(UTILITIES_DIR)/read_cub_file_utils.c \
	$(UTILITIES_DIR)/debug_funcs.c \
	$(UTILITIES_DIR)/validate_map_utils.c \
	$(UTILITIES_DIR)/useful_render_funcs.c \
	$(UTILITIES_DIR)/create_rectanglar_map.c \
	$(UTILITIES_DIR)/handle_command_line_utils.c \
	$(PARSING_DIR)/parse_cub_elems.c \
	$(PARSING_DIR)/parse_color_data.c \
	$(PARSING_DIR)/parse_resolution_data.c \
	$(PARSING_DIR)/parse_texture_data.c \
	$(CONTROLLERS_DIR)/detect_key_actions.c \
	$(CONTROLLERS_DIR)/handle_command_line.c \
	$(CONTROLLERS_DIR)/read_cub_file.c \
	$(CONTROLLERS_DIR)/validate_map.c \


OBJS = $(SRCS:.c=.o)
LIBFT = ./libs/libft/libft.a
SANITIZE = -fsanitize=address -g
LLDB = -g

# DYNAMIC MINILIBX
MLX = dynamic_mlx
LIBMLX = libmlx.dylib

# MINILIBX-LINUX
# MLX = minilibx-linux
# LIBMLX = libmlx.a
# LIBMLX_PATH = $(MLX)/$(LIBMLX)
# OPTIONS = -lXext -lX11

# DYNAMIC MINILIBX
$(NAME): $(OBJS)
	$(MAKE) bonus -C ./libs/libft
	$(MAKE) -C ./$(MLX)
	cp ./$(MLX)/$(LIBMLX) ./
	$(CC) $(CFLAGS) $(LLDB) -o $(NAME) $(LIBMLX) -framework OpenGL -framework AppKit -lm $(LIBFT) $(SRCS)

# MINILIBX-LINUX
# $(NAME): $(OBJS)
# 	$(MAKE) bonus -C ./libs/libft
# 	$(MAKE) -C ./$(MLX)
# 	cp $(LIBMLX_PATH) ./
# 	${CC} ${CFLAGS} ${OBJS} ${LIBMLX} ${OPTIONS} -lm $(LIBFT) -o $(NAME)

all: $(NAME)

clean:
	$(MAKE) clean -C ./libs/libft
	$(MAKE) clean -C ./$(MLX)
	$(RM) $(OBJS)

fclean: clean
	$(MAKE) fclean -C ./libs/libft
	$(MAKE) clean -C ./$(MLX)
	$(RM) $(NAME) $(LIBMLX)

re: fclean all

error:
	sh error_test.sh

ok:
	sh ok_test.sh

.PHONY: all clean fclean re
