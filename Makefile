# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rnakai <rnakai@student.42tokyo.jp>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/25 15:17:11 by kkamashi          #+#    #+#              #
#    Updated: 2020/12/08 15:01:46 by rnakai           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

CC = gcc
CFLAGS = -Wall -Wextra -Werror
DEBUG = -g -fsanitize=address,undefined
DEPENDENCY_OPTION = -MMD -MP -MF

LIBS_DIR = ./libs

SRCS = main.c \
	$(LIBS_DIR)/get_next_line/get_next_line.c
SRCS += ${shell find ./srcs/bmp/ -type f -name "*.c"}
SRCS += ${shell find ./srcs/controllers/ -type f -name "*.c"}
SRCS += ${shell find ./srcs/parsing_cub_file/ -type f -name "*.c"}
SRCS += ${shell find ./srcs/utilities/ -type f -name "*.c"}
SRCS += ${shell find ./srcs/game/linked_list/ -type f -name "*.c"}
SRCS += ${shell find ./srcs/game/other_utils/ -type f -name "*.c"}
SRCS += ${shell find ./srcs/game/render/ -type f -name "*.c"}
SRCS += ${shell find ./srcs/game/hook/ -type f -name "*.c"}
SRCS += ${shell find ./srcs/game/cast_ray/ -type f -name "*.c"}
SRCS += ${shell find ./srcs/game/system/ -type f -name "*.c"}

#
SRCS += ${shell find ./srcs/debug/ -type f -name "*.c"}
#

INCLUDE = -I./includes/ \
			-I./libs/get_next_line/ \
			-I./libs/libft/ \
			-I./includes/structs/ \
			-I./minilibx-linux/

OBJS = $(SRCS:.c=.o)
DEPS = ${SRCS:.c=.d}
LIBFT = ./libs/libft/libft.a

.c.o:
	$(CC) $(CFLAGS) $(DEBUG) $(INCLUDE) -c $(DEPENDENCY_OPTION) ${<:.c=.d} $< -o ${<:.c=.o}

MLX = minilibx-linux
LIBMLX = libmlx.a
LIBMLX_PATH = $(MLX)/$(LIBMLX)
OPTIONS = -lXext -lX11
BMP_IMAGE = cub3D.bmp

$(NAME): $(OBJS)
	$(MAKE) bonus -C ./libs/libft
	$(MAKE) -C ./$(MLX)
	cp $(LIBMLX_PATH) ./
	${CC} ${CFLAGS} $(DEBUG) ${OBJS} ${LIBMLX} ${OPTIONS} -lm $(LIBFT) -o $(NAME)

all: $(NAME)

clean:
	$(RM) $(OBJS) $(DEPS)

fclean: clean
	$(MAKE) fclean -C ./libs/libft
	$(MAKE) clean -C ./$(MLX)
	$(RM) $(NAME) $(LIBMLX) $(BMP_IMAGE)


re: fclean all

error:
	sh error_test.sh

ok:
	sh ok_test.sh

.PHONY: all clean fclean re error ok

-include $(DEPS)
